/*
 * Copyright (C) 2016 Luiz Carlos Vieira (http://www.luiz.vieira.nom.br)
 *
 * This file is part of FLAT.
 *
 * FLAT is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * FLAT is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "facedataset.h"

#include <QDebug>
#include <QFileInfo>
#include <QDir>
#include <QApplication>
#include <fstream>
#include <iostream>



using namespace std;

// +-----------------------------------------------------------
ft::FaceDataset::FaceDataset()
{
	m_iNumFeatures = 0;
}

// +-----------------------------------------------------------
ft::FaceDataset::~FaceDataset()
{
	clear();
}

// +-----------------------------------------------------------
int ft::FaceDataset::size() const
{
	return m_vSamples.size();
}

// +-----------------------------------------------------------
bool ft::FaceDataset::loadFromFile(const QString &sFileName, QString &sMsgError)
{
	/******************************************************
	 * Open and read the file
	 ******************************************************/
	QFile oFile(sFileName);
	if (!oFile.open(QFile::ReadOnly))
    {
		sMsgError = QString(QApplication::translate("FaceDataset", "it was not possible to read from file [%1]")).arg(sFileName);
        return false;
    }

	// Used to resolve the image file sNames relative to the saved file path
	QDir oBase(QFileInfo(sFileName).absolutePath());

	QTextStream oData(&oFile);
	QString sData = oData.readAll();
	oFile.close();

	/******************************************************
	 * Parse the xml document
	 ******************************************************/
	QDomDocument oDoc;
	QString sError;
	int iLine, iColumn;
	if(!oDoc.setContent(sData, true, &sError, &iLine, &iColumn))
	{
		sMsgError = QString(QApplication::translate("FaceDataset", "there is an error in the contents of the file [%1]: error [%2], line [%3], column [%4]")).arg(sFileName, sError, QString::number(iLine), QString::number(iColumn));
		return false;
	}

	// Root node
	QDomElement oRoot = oDoc.firstChildElement("FaceDataset");

	if(oRoot.isNull())
	{
		sMsgError = QString(QApplication::translate("FaceDataset", "there is an error in the contents of the file [%1]: the node '%2' does not exist")).arg(sFileName, "FaceDataset");
		return false;
	}

	int iNumFeats = oRoot.attribute("numberOfFeatures", "-1").toInt();
	if(iNumFeats < 0)
	{
		sMsgError = QString(QApplication::translate("FaceDataset", "there is an error in the contents of the file [%1]: the attribute '%2' does not exist or it contains an invalid value")).arg(sFileName, "numberOfFeatures");
		return false;
	}

	// Landmark Groups
    QDomElement oGroups = oRoot.firstChildElement("LandmarksGroups");
	if (oGroups.isNull()){
        std::cout << "There are no landmarks groups in file" << std::endl;
	}else{
        groups.loadFromXML(oGroups);
	}

	// Sample images
//	QDomElement oSamples = oRoot.nextSiblingElement("Samples");
	QDomElement oSamples = oRoot.firstChildElement("Samples");
	if(oSamples.isNull())
	{
		sMsgError = QString(QApplication::translate("FaceDataset", "there is an error in the contents of the file [%1]: the node '%2' does not exist")).arg(sFileName, "Samples");
		return false;
	}

	vector<FaceImage*> vSamples;
	for(QDomElement oElement = oSamples.firstChildElement(); !oElement.isNull(); oElement = oElement.nextSiblingElement())
	{
		FaceImage *pSample = new FaceImage();
		if(!pSample->loadFromXML(oElement, sError, iNumFeats))
		{
			foreach(FaceImage *pSamp, vSamples)
				delete(pSamp);
			delete pSample;

			sMsgError = QString(QApplication::translate("FaceDataset", "there is an error in the contents of the file [%1]: %2")).arg(sFileName, sError);
			return false;
		}
		pSample->setFileName(oBase.absoluteFilePath(pSample->fileName()));
		vSamples.push_back(pSample);
	}

	clear();
	m_iNumFeatures = iNumFeats;
	m_vSamples = vSamples;

	return true;
}

// +-----------------------------------------------------------
bool ft::FaceDataset::saveToFile(const QString &sFileName, QString &sMsgError) const
{
	/******************************************************
	 * Create the xml document
	 ******************************************************/
	QDomDocument oDoc;

	// Processing instruction
	QDomProcessingInstruction oInstr = oDoc.createProcessingInstruction("xml", "version='1.0' encoding='UTF-8'");
	oDoc.appendChild(oInstr);

	// Root node
	QDomElement oRoot = oDoc.createElementNS("https://github.com/luigivieira/Facial-Landmarks-Annotation-Tool", "FaceDataset");
	oDoc.appendChild(oRoot);

	oRoot.setAttribute("numberOfFeatures", m_iNumFeatures);
	groups.saveToXML(oRoot);

	// Sample images
	QDomElement oSamples = oDoc.createElement("Samples");
	oRoot.appendChild(oSamples);

	// Used to make the image file sNames relative to the saved file path
	QDir oBase(QFileInfo(sFileName).absolutePath());
	QString sSave;

	foreach(FaceImage *pImage, m_vSamples)
	{
		sSave = pImage->fileName(); // Save the absolute path (it is still used in the editor)
		pImage->setFileName(oBase.relativeFilePath(pImage->fileName()));
		pImage->saveToXML(oSamples);
		pImage->setFileName(sSave);


        std::vector<FaceFeature*>   features        =   pImage->getFeatures();
        QString                     img_name        =   oBase.absoluteFilePath( pImage->fileName() );
        std::string                 img_name__      =   img_name.toUtf8().constData();

        img_name__      +=  ".dan74";
        std::ofstream   file( img_name__.c_str() );
        for ( int idx=0; idx<features.size(); ++idx){    file << features[idx]->x() << " "  << features[idx]->y() << std::endl;        }
        file.close();

        /*
        std::string   img_name_pts = img_name__.substr(0, img_name__.size()-4);
        img_name_pts    +=  ".pts";
        std::ofstream   file2( img_name_pts.c_str() );
        file2 << "version: 1" << std::endl;
        file2 << "n_points: " << features.size() << std::endl;
        file2 << "{" << std::endl;

        for ( int idx=0; idx<features.size(); ++idx){    file2 << features[idx]->x() << " "  << features[idx]->y() << std::endl;        }
        file2 << "}" ;
        file2.close();
        */
	}

	/******************************************************
	 * Save the file
	 ******************************************************/
	QFile oFile(sFileName);
	if (!oFile.open(QFile::WriteOnly | QFile::Truncate))
    {
		sMsgError = QString(QApplication::translate("FaceDataset", "it was not possible to write to file [%1]")).arg(sFileName);
        return false;
    }

	QTextStream oData(&oFile);
	oDoc.save(oData, 4);
	oFile.close();

	return true;
}

// +-----------------------------------------------------------
void ft::FaceDataset::clear()
{
	foreach(FaceImage *pImage, m_vSamples)
		delete pImage;
	m_vSamples.clear();

	m_iNumFeatures = 0;
}

// +-----------------------------------------------------------
ft::FaceImage* ft::FaceDataset::getImage(const int iIndex) const
{
    if(iIndex < 0 || iIndex >= size())
		return NULL;

	return m_vSamples[iIndex];
}

// +-----------------------------------------------------------
ft::FaceImage* ft::FaceDataset::addImage(const QString &sFileName)
{
	foreach(FaceImage *pImage, m_vSamples)
		if(pImage->fileName() == sFileName)
			return pImage;

    FaceImage *pRet = new FaceImage(sFileName);
    FaceImage *pImLast = getImage( this->size()-1 );

    for (int idx=0; idx<this->numFeatures(); ++idx){

        FaceFeature *pF = pImLast->getFeature(idx);
        pRet->addFeature(idx, pF->x(), pF->y());
    }

	m_vSamples.push_back(pRet);
	return pRet;
}

// +-----------------------------------------------------------
bool ft::FaceDataset::removeImage(const int iIndex)
{
	if(iIndex < 0 || iIndex >= size())
		return false;

	FaceImage *pImage = m_vSamples[iIndex];
	m_vSamples.erase(m_vSamples.begin() + iIndex);
	delete pImage;

	return true;
}

// +-----------------------------------------------------------
int ft::FaceDataset::numFeatures() const
{
	return m_iNumFeatures;
}

// +-----------------------------------------------------------
void ft::FaceDataset::setNumFeatures(int iNumFeats)
{
	m_iNumFeatures = iNumFeats;
}

// +-----------------------------------------------------------
void ft::FaceDataset::addFeature(int iID, float x, float y)
{
	FaceFeature *pFeat;
	foreach(FaceImage *pSample, m_vSamples)
		pFeat = pSample->addFeature(iID, x, y);
	m_iNumFeatures++;
}

// +-----------------------------------------------------------
bool ft::FaceDataset::removeFeature(const int iIndex)
{
	if(iIndex < 0 || iIndex >= m_iNumFeatures)
		return false;

	foreach(FaceImage *pSample, m_vSamples)
		pSample->removeFeature(iIndex);
	m_iNumFeatures--;

	return true;
}

// +-----------------------------------------------------------
bool ft::FaceDataset::connectFeatures(int iIDSource, int iIDTarget)
{
	foreach(FaceImage *pSample, m_vSamples)
		pSample->connectFeatures(iIDSource, iIDTarget);

	return true;
}

// +-----------------------------------------------------------
bool ft::FaceDataset::disconnectFeatures(int iIDSource, int iIDTarget)
{
	foreach(FaceImage *pSample, m_vSamples)
		pSample->disconnectFeatures(iIDSource, iIDTarget);

	return true;
}

// +-----------------------------------------------------------
vector<ft::FaceFeature*> ft::FaceDataset::getImageFeatures(const int iIndex)
{
	if(iIndex < 0 || iIndex >= (int) m_vSamples.size())
		return vector<FaceFeature*>();

	return m_vSamples[iIndex]->getFeatures();
}

QList<QString> ft::FaceDataset::getImageNamesList() {

    if (m_vSamples.empty())
        return QList<QString>();

    QList<QString> namesList;

    for (auto faceImage:m_vSamples){

        QString imageName = faceImage->fileName();
        namesList.push_back(imageName);
    }

    return  namesList;
}

//
// Created by morzh on 01.01.2020.
//

#include <iostream>
#include "LandmarksGroups.h"

void LandmarksGroups::genActionsMenu(QMenu *menu) {

    if (!menu)
        return;

    for (int idx=0; idx<num_groups; ++idx)
        menu->addAction(actions[idx]);
}

bool LandmarksGroups::loadFromXML(QDomElement oElement) {

    sNames.clear();
    sIndices.clear();
    sInterpolations.clear();

    // Check the element name
    if(oElement.tagName() != "LandmarksGroups")
    {
//        sMsgError = QString(QApplication::translate("FaceImage", "invalid node name [%1] - expected node '%2'").arg(oElement.tagName(), "Sample"));
        std::cerr << "Landmarks Groups read error" << std::endl;
        return false;
    }

    for(QDomElement oGroup = oElement.firstChildElement(); !oGroup.isNull(); oGroup = oGroup.nextSiblingElement())
    {
        if ( oGroup.tagName() != "Group"){   std::cout << "tagName not Group" << std::endl;          return  false;       }
        QString sName   = oGroup.attribute("name");
        QString sInd    = oGroup.attribute("indices");
        QString sInterp = oGroup.attribute("interpolation");

        sNames.push_back(sName);
        sIndices.push_back(sInd);
        sInterpolations.push_back(sInterp);
    }

    num_groups = sNames.size();

    return  true;
}

void LandmarksGroups::saveToXML(QDomElement &oParent) const{

    QDomElement oGroups = oParent.ownerDocument().createElement("LandmarksGroups");
    oParent.appendChild(oGroups);

    for (int idx=0; idx<this->sNames.size(); ++idx){

        QDomElement oGroup = oGroups.ownerDocument().createElement("Group");
        oGroup.setAttribute("name", sNames[idx]);
        oGroup.setAttribute("indices", sIndices[idx]);
        oGroup.setAttribute("interpolation", sInterpolations[idx]);
        oGroups.appendChild(oGroup);
    }
}

void LandmarksGroups::genMenuActions(QObject *parent) {

    if (  !parent)
        return;

    num_groups = sNames.size();

    if (actions.size()==0){

        for (int idx=0; idx<num_groups; ++idx){
            QAction* actn = new QAction(sNames[idx], parent);
            actn->setCheckable(true);
            actn->setChecked(true);
            actions.push_back(actn);
        }
    }
    else{
        for (int idx=0; idx<num_groups; ++idx){
            actions[idx]->setParent(parent);
        }
    }
}


void LandmarksGroups::parseIndices() {

    iIndices.clear();
    num_groups = sIndices.size();

    for (int idx=0; idx< sIndices.size(); ++idx){

        QStringList     sRange  = sIndices[idx].split("-");
        Range           iRange;

//        std::cout << sRange.size() << std::endl;

        if (sRange.size() !=2){
            iRange.start = -1;
            iRange.end   = -1;
        }
        else{
            iRange.start = sRange.at(0).toInt();
            iRange.end   = sRange.at(1).toInt();
            }

        iIndices.push_back(iRange);
    }
}

void LandmarksGroups::printIndices() {

    std::cout << "-------------- Face Parts Indices ------------" << std::endl;

    for (int idx=0; idx<iIndices.size(); ++idx)

        std::cout << sNames[idx].toStdString() << " " << iIndices[idx].start <<  " " << iIndices[idx].end << std::endl;
}

void LandmarksGroups::parseData() {

    parseIndices();
    parseInterpolation();
}

void LandmarksGroups::parseInterpolation() {

    iInterpolations.clear();

    for (int idx=0; idx< sIndices.size(); ++idx){

        QStringList  sParts  = sInterpolations[idx].split(";");
        QList<QList<int>> iIndicesUnit;

//        std::cout << sIndices[idx].toStdString() << std::endl;
        for (int i = 0; i < sParts.size(); ++i) {

            QList<int> indices_arr = extractIndices(sParts.at(i));
            iIndicesUnit.push_back(indices_arr);
        }

        iInterpolations.push_back(iIndicesUnit);
    }
}

QList<int> LandmarksGroups::extractIndices(const QString &substring) {

    QStringList     sParts;
    QList<int>      indices;

    if (substring.contains(",")){
        sParts  = substring.split(",");
    }else{
        sParts.push_back(substring);
    }


    for (int i = 0; i < sParts.size(); ++i) {

        if (sParts.at(i).contains("-")){

            QStringList     sRange  = sParts.at(i).split("-");

            if (sRange.size() < 2){
                indices.push_back(sRange.at(0).toInt());
            }
            else{
                indices.append( Range(sRange.at(0).toInt(), sRange.at(1).toInt()).unroll() );
            }
        }
        else{
            indices.append(sParts.at(i).toInt());
        }
    }

    return indices;
}

void LandmarksGroups::printInterpolationsIndices() {

    std::cout << "======= Indices Sets For Interpolation ===========" << std::endl;

    for (int  idx=0; idx<iInterpolations.size(); ++idx){

        auto elvl1 = iInterpolations[idx];
        std::cout << sNames[idx].toStdString()  << "::";

        for( auto elvl2: elvl1){

            std::cout << " (";
            for (auto elvl3: elvl2){
                std::cout << elvl3 << " ";
            }
            std::cout << "), ";

        }
        std::cout << std::endl;
    }
}

void LandmarksGroups::addSignalMapper(QSignalMapper *mapper) {

    if (!mapper)
        return;

    for (int idx=0; idx<sNames.size(); ++idx) {
        connect(actions[idx], SIGNAL(triggered()), mapper, SLOT(map()), Qt::UniqueConnection);
        mapper->setMapping(actions[idx], sNames[idx]);
    }

}

LandmarksGroups::~LandmarksGroups() {

}

void LandmarksGroups::getMatchedRange(const QString &sType, int *pStart, int *pEnd, bool *pIsChecked) {

    for (int idx=0; idx < sNames.size(); ++idx){

        if (sType == sNames[idx]){
            *pStart = iIndices[idx].start;
            *pEnd = iIndices[idx].end;
            *pIsChecked = actions[idx]->isChecked();
            return;
        }
    }
}

//Range::Range(int start, int end) : start(start), end(end) {}

//
// Created by morzh on 01.01.2020.
//

#include <iostream>
#include "LandmarksGroups.h"

void LandmarksGroups::addMenusToButton(QMenu *button, QObject *parent) {

    if ( !button && !parent)
        return;

    num_groups = sNames.size();
    actions.reserve(num_groups);

    for (int idx=0; idx<num_groups; ++idx){

        actions[idx] = new QAction(sNames[idx], parent);
        actions[idx]->setText(sNames[idx]);
        actions[idx]->setCheckable(true);
        actions[idx]->setChecked(true);

        button->addAction(actions[idx]);
    }

}

void LandmarksGroups::createActions() {

}

bool LandmarksGroups::loadFromXML(QDomElement oElement) {

    sNames.clear();
    sIndices.clear();
    sInterpolation.clear();

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
        sInterpolation.push_back(sInterp);
    }

    num_groups = sNames.size();

    return  true;
}

void LandmarksGroups::saveToXML(QDomElement &oParent)  const{

    // Add the "Sample" node
    QDomElement oGroups = oParent.ownerDocument().createElement("LandmarksGroups");
    oParent.appendChild(oGroups);

    for (int idx=0; idx<this->sNames.size(); ++idx){

        QDomElement oGroup = oGroups.ownerDocument().createElement("Group");
        oGroup.setAttribute("name", sNames[idx]);
        oGroup.setAttribute("indices", sIndices[idx]);
        oGroup.setAttribute("interpolation", sInterpolation[idx]);
        oGroups.appendChild(oGroup);
    }
}

//Range::Range(int start, int end) : start(start), end(end) {}

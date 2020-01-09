//
// Created by morzh on 01.01.2020.
//

#include <iostream>
#include "LandmarksGroups.h"

void LandmarksGroups::addMenusToButton(QMenu *button, QObject *parent) {

    if ( !button && !parent)
        return;

    num_groups = list_names.size();
    actions.reserve(num_groups);

    for (int idx=0; idx<num_groups; ++idx){

        actions[idx] = new QAction( list_names[idx], parent);
        actions[idx]->setText(list_names[idx]);
        actions[idx]->setCheckable(true);
        actions[idx]->setChecked(true);

        button->addAction(actions[idx]);
    }

}

void LandmarksGroups::createActions() {

}

bool LandmarksGroups::loadFromXML(QDomElement oElement) {

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
        QString name = oGroup.attribute("name");
        std::cout << name.toStdString() << std::endl;

    }

    return  true;
}

//Range::Range(int start, int end) : start(start), end(end) {}

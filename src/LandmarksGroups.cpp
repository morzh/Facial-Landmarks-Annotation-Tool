//
// Created by morzh on 01.01.2020.
//

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

//Range::Range(int start, int end) : start(start), end(end) {}

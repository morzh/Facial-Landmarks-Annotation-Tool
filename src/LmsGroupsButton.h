//
// Created by morzh on 01.01.2020.
//

#ifndef FLAT_LMSGROUPSBUTTON_H
#define FLAT_LMSGROUPSBUTTON_H


#include <QtCore/QString>
#include <vector>
#include <QtWidgets/QAction>
#include <QMenu>

class LmsGroupsButton: public QObject {
    Q_OBJECT
public:

    int                     num_groups = 8;
    std::vector<QString>    list_names = {tr("Oval Low"), tr("Oval Upper"), tr("Brows"), tr("Eyes"), tr("Nose Ridge"), tr("Node Shape"), tr("Mouth Outer"), tr("Mouth Inner")};
    std::vector<QAction*>   actions;

    void addMenusToButton(QMenu *button, QObject *parent);

};


#endif //FLAT_LMSGROUPSBUTTON_H

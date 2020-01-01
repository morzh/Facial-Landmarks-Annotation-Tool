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
    void addMenusToButton(QMenu *button, QObject *parent);

    int               num_groups = 10;
    QList<QString>    list_names = {tr("Oval Low"),    tr("Oval Upper"),
                                    tr("Brows Right"), tr("Brows Left"),
                                    tr("Eyes Right"),  tr("Eyes Left"),
                                    tr("Nose Ridge"),  tr("Node Shape"),
                                    tr("Mouth Outer"), tr("Mouth Inner")};

    QList<QAction*>   actions;

};


#endif //FLAT_LMSGROUPSBUTTON_H

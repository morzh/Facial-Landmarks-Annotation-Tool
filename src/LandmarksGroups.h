//
// Created by morzh on 01.01.2020.
//

#ifndef FLAT_LANDMARKSGROUPS_H
#define FLAT_LANDMARKSGROUPS_H


#include <QtCore/QString>
#include <vector>
#include <QtWidgets/QAction>
#include <QMenu>


struct Range{
    Range(int start, int end): start(start), end(end) {}
    int start, end;
};

class LandmarksGroups: public QObject {
    Q_OBJECT
public:
    void createActions();
    void addMenusToButton(QMenu *button, QObject *parent);

    int               num_groups = 10;
    QList<QString>    list_names = {tr("Oval Low"),    tr("Oval Upper"),
                                    tr("Brows Right"), tr("Brows Left"),
                                    tr("Eyes Right"),  tr("Eyes Left"),
                                    tr("Nose Ridge"),  tr("Node Shape"),
                                    tr("Mouth Outer"), tr("Mouth Inner")};

    QList<QAction*>   actions;
    QList<Range>      ranges = { Range(0,16), Range(17,27)};
    QList<QString>    interpRanges;

};


#endif //FLAT_LANDMARKSGROUPS_H

//
// Created by morzh on 01.01.2020.
//

#ifndef FLAT_LANDMARKSGROUPS_H
#define FLAT_LANDMARKSGROUPS_H


#include <QtCore/QString>
#include <vector>
#include <QtWidgets/QAction>
#include <QMenu>
#include <QtXml/QDomElement>


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
    /*
    QList<QString>    sNames = {tr("Oval Low"),    tr("Oval Upper"),
                                    tr("Brows Right"), tr("Brows Left"),
                                    tr("Eyes Right"),  tr("Eyes Left"),
                                    tr("Nose Ridge"),  tr("Node Shape"),
                                    tr("Mouth Outer"), tr("Mouth Inner")};
    */

    QList<QString>    sNames;
    QList<QString>    sIndices;
    QList<QString>    sInterpolation;
    QList<QAction*>   actions;
    QList<Range>      ranges = { Range(0,16), Range(17,27)};
    QList<QString>    interpRanges;

    bool loadFromXML(QDomElement lmsGroups);
    void saveToXML(QDomElement &oParent) const ;
    void parseIndices();
    void parseInterpolation();
};


#endif //FLAT_LANDMARKSGROUPS_H

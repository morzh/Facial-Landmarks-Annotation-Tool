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
    Range(){}
    int start, end;

    QList<int> unroll() {

        QList<int> indices;

        for (int idx=start; idx<=end; ++idx)
            indices.push_back(idx);

        return indices;
    }
};

class LandmarksGroups: public QObject {
    Q_OBJECT
public:
    void genActionsMenu(QMenu *menu);

    int               num_groups = 10;
    /*
    QList<QString>    sNames = {tr("Oval Low"),    tr("Oval Upper"),
                                    tr("Brows Right"), tr("Brows Left"),
                                    tr("Eyes Right"),  tr("Eyes Left"),
                                    tr("Nose Ridge"),  tr("Node Shape"),
                                    tr("Mouth Outer"), tr("Mouth Inner")};
    */

    QList<QString>              sNames;
    QList<QString>              sIndices;
    QList<QString>              sInterpolations;
    QList<QAction*>             actions;
    QList<Range>                iIndices;
    QList<QList<QList<int>>>    iInterpolations;

    bool loadFromXML(QDomElement lmsGroups);
    void saveToXML(QDomElement &oParent) const ;

    void genMenuActions(QObject *parent);
    void printIndices();
    void printInterpolationsIndices();
    void parseData();

private:
    void parseIndices();
    void parseInterpolation();

    QList<int> extractIndices(const QString &substring);
};


#endif //FLAT_LANDMARKSGROUPS_H

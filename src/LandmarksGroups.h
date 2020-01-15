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
#include <QtCore/QSignalMapper>


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

    virtual ~LandmarksGroups();

    const QObject * getMapper();
    void            getMatchedRange             (const QString &sType, int *pStart, int *pEnd, bool *pIsChecked);
    void            genActionsMenu              ( QMenu *menu);
    bool            loadFromXML                 ( QDomElement lmsGroups);
    void            saveToXML                   ( QDomElement &oParent) const ;
    void            genMenuActions              ( QObject *parent);
    void            parseData                   ( );
    void addSignalMapper(QObject *parent);
    void            removeSignalMapper          ( );
    void            printInterpolationsIndices  ( );
    void            printIndices                ( );

    int                         num_groups = 10;
    QList<QString>              sNames;
    QList<QString>              sIndices;
    QList<QString>              sInterpolations;
    QList<QAction*>             actions;
    QList<Range>                iIndices;
    QList<QList<QList<int>>>    iInterpolations;

private:
    void                parseIndices();
    void                parseInterpolation();
    QList<int>          extractIndices(const QString &substring);

    QSignalMapper*      mapper = nullptr;

};


#endif //FLAT_LANDMARKSGROUPS_H

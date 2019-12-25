//
// Created by morzh on 25.12.2019.
//

#ifndef FLAT_ITEMDELEGATE_H
#define FLAT_ITEMDELEGATE_H


#include <QItemDelegate>
#include <QObject>

class ItemDelegate: public QItemDelegate {
 Q_OBJECT
public:
    explicit  ItemDelegate(QObject *parent =0);
};


#endif //FLAT_ITEMDELEGATE_H

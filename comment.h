
#ifndef COMMENT_H
#define COMMENT_H


#include "product.h"
#include "qboxlayout.h"
#include "qlabel.h"
#include <QObject>
#include <QWidget>


class Comment : public QWidget
{
    Q_OBJECT
    QLabel *l[3];
    QHBoxLayout *h;
    QVBoxLayout *v, *vl;
    QSpacerItem *s[3];

public:
    Comment(pair<QString, QString> c,  QVBoxLayout *vl, QWidget *parent = 0);
    ~Comment();
};

#endif // COMMENT_H


#ifndef COMMENTCONTAINER_H
#define COMMENTCONTAINER_H


#include "comment.h"
#include "qboxlayout.h"
#include <QObject>
#include <QWidget>

#include <bits/stdc++.h>
using namespace std;

class CommentContainer : public QWidget
{
    Q_OBJECT
private:
    vector<Comment*> comments;
    QVBoxLayout *v;

public:
    CommentContainer(vector<pair<QString, QString>> c, QVBoxLayout *v, QWidget *parent = 0);
    void AddComment(QString name, QString comment);
    ~CommentContainer();
};

#endif // COMMENTCONTAINER_H

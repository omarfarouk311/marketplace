
#include "commentcontainer.h"

CommentContainer::CommentContainer(vector<pair<QString, QString>> c, QVBoxLayout *v, QWidget *parent) : QWidget(parent)
{
    for(pair<QString, QString> &i : c) {
        comments.push_back(new Comment(i,v));
        v->addWidget(comments.back());
    }
    this->v = v;

}

void CommentContainer::AddComment(QString name, QString comment)
{
    comments.push_back(new Comment({name, comment}, v));
    v->addWidget(comments.back());
}

CommentContainer::~CommentContainer(){
    for(auto &i : comments) {
        v->removeWidget(i);
        delete i;
    }
}

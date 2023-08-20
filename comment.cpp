
#include "comment.h"

Comment::Comment(pair<QString, QString> c, QVBoxLayout *vl, QWidget *parent) : QWidget(parent)
{
    for(auto &i : l) {
        i = new QLabel();
    }
    this->vl = vl;
    h = new QHBoxLayout();
    v = new QVBoxLayout();
    for(auto &i : s) {
        i = new QSpacerItem(40 , 20, QSizePolicy::Expanding, QSizePolicy::Expanding);
    }

    l[0]->setPixmap(QPixmap(":/new/prefix1/assets/CommentImage.png").scaled(50, 50));

    //name
    l[1]->setText(c.first);
    l[1]->setStyleSheet("font: 700 9pt \"Calibri\";");
    //comment
    l[2]->setText(c.second);
    l[2]->setWordWrap(true);

    v->addItem(s[1]), v->addWidget(l[1]), v->addWidget(l[2]), v->addItem(s[2]);
    h->addWidget(l[0]), h->addLayout(v), h->addItem(s[0]);
    vl->addLayout(h);

}

Comment::~Comment() {
    vl->removeItem(h);
    h->removeWidget(l[0]), h->removeItem(v), h->removeItem(s[0]);
    v->removeItem(s[1]), v->removeWidget(l[1]), v->removeWidget(l[2]), v->removeItem(s[2]);

    for(auto &i : l) {
        delete i;
    }
    delete v;
    delete h;
}

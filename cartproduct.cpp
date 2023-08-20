
#include "cartproduct.h"
#include "qboxlayout.h"



CartProduct::CartProduct(PRODUCT p, QVBoxLayout *lout, QWidget *parent) : QWidget(parent)
{

    this->c = CurrentUser::GetCustomer();
    quantity = c->getCart().GetQuantity(p.getID());
    this->p = p;
    this->lout = lout;

    setStyleSheet("font: 300 16pt \"Calibri\";");


    for(auto &i:s)
    {
        i = new QSpacerItem(100,20,QSizePolicy::Expanding, QSizePolicy::Expanding);
    }
    for(auto &i: l) {
        i = new QLabel;
    }

    for(auto &i: button) {
        i = new QPushButton();
    }

    if(quantity == p.getQuantity())
    {
        button[0]->setDisabled(1);
    }
    for(auto &i: button)
    {
        i->setFlat(1);
    }

    connect(button[0],SIGNAL(clicked()),this,SLOT(button0()));
    connect(button[1],SIGNAL(clicked()),this,SLOT(button1()));
    connect(button[2],SIGNAL(clicked()),this,SLOT(button2()));


    l[0]->setPixmap(QPixmap(p.getPath()).scaled(150, 200));
    l[1]->setText(p.getName());
    float totalPrice = quantity * p.getPrice();
    l[2]->setText(QString::number(totalPrice) + "$");
    v = new QVBoxLayout();

    button[0]->setIcon(QIcon(":/new/prefix1/assets/increment.png"));
    button[0]->setIconSize(QSize(30,30));
    l[3]->setText(QString::number(quantity));
    button[1]->setIcon(QIcon(":/new/prefix1/assets/decrement.png"));
    button[1]->setIconSize(QSize(20,30));
    button[2]->setIcon(QIcon(":/new/prefix1/assets/trash.png"));
    button[2]->setIconSize(QSize(30,30));

    h[0] = new QHBoxLayout();
    h[0]->addWidget(l[2]), h[0]->addItem(s[3]), h[0]->addWidget(button[1]), h[0]->addWidget(l[3]),
        h[0]->addWidget(button[0]), h[0]->addItem(s[1]), h[0]->addWidget(button[2]);

    v->addItem(s[2]), v->addWidget(l[1]), v->addLayout(h[0]), v->addItem(s[0]);
    h[1] = new QHBoxLayout(this);
    h[1]->addWidget(l[0]), h[1]->addLayout(v);
    lout->addWidget(this);
}



void CartProduct::button0()
{

    if(quantity == 0)
    {
        button[1]->setEnabled(1);
    }
    if(quantity+1 == p.getQuantity())
    {
        button[0]->setDisabled(1);
    }
    if(quantity+1 <= p.getQuantity())
    {
        quantity++;
        CART cart;
        l[3]->setText(QString::number(quantity));
        l[2]->setText(QString::number(p.getPrice() * quantity) + "$");
        cart = c->getCart();
        cart.remove(p.getID(),-1);
        c->setCart(cart);
        emit changed();
    }

}

void CartProduct::button1()
{
    if(quantity == p.getQuantity())
    {
        button[0]->setEnabled(1);
    }
    if(quantity-1 == 0)
    {
        button[1]->setDisabled(1);
        button2();
    }
    else if(quantity-1 <= p.getQuantity())
    {
        quantity--;
        CART cart;
        l[3]->setText(QString::number(quantity));
        l[2]->setText(QString::number(p.getPrice() * quantity) + "$");
        cart = c->getCart();
        cart.remove(p.getID(),1);
        c->setCart(cart);
        emit changed();
    }

}

void CartProduct::button2()
{

    CART cart;
    cart = c->getCart();
    cart.remove(p.getID(),cart.GetQuantity(p.getID()));
    c->setCart(cart);
    quantity = 0;
    emit changed();
    this->hide();
}

CartProduct::~CartProduct()
{
    lout->removeWidget(this);

    v->removeItem(s[2]), v->removeWidget(l[1]), v->removeItem(h[0]), v->removeItem(s[0]);

    h[0]->removeWidget(l[2]), h[0]->removeItem(s[3]), h[0]->removeWidget(button[1]), h[0]->removeWidget(l[3]),
        h[0]->removeWidget(button[0]), h[0]->removeItem(s[1]), h[0]->removeWidget(button[2]);

    disconnect(button[0],SIGNAL(clicked()),this,SLOT(button0()));
    disconnect(button[1],SIGNAL(clicked()),this,SLOT(button1()));
    disconnect(button[2],SIGNAL(clicked()),this,SLOT(button2()));

    h[1]->removeItem(v);

    for(auto i : button)
    {
        delete i;
    }
    for(auto i : l)
    {
        delete i;
    }
    for(auto i: s)
    {
        delete i;
    }
    delete h[0];
    delete h[1];
    delete v;
}

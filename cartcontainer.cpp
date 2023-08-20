
#include "cartcontainer.h"
#include "cartproduct.h"




CartContainer::CartContainer(QVBoxLayout *l, QWidget *parent) : QWidget(parent)
{
    CUSTOMER* c = CurrentUser::GetCustomer();
    lout = l;
    s = new QSpacerItem(40,20,QSizePolicy::Expanding,QSizePolicy::Expanding);
    vector<PRODUCT> p;
    for(auto i: c->getCart().getProducts_taken_by_user())
    {
        if(i.second)
            p.push_back(UTILITY::GetProduct(i.first));
    }


    for(auto &i : p)
    {

        CartProduct *x = new CartProduct(i,lout);
        cp.push_back(x);
        connect(cp.back(), &CartProduct::changed, this, &CartContainer::ChangedReceiver);
    }

    lout->addItem(s);
}


void CartContainer::ChangedReceiver()
{
    emit recalculate();
}

CartContainer::~CartContainer()
{
    lout->removeItem(s);

    for(auto i : cp)
    {
        if(i)
            delete i;
    }
}


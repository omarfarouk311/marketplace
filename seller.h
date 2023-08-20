#ifndef SELLER_H
#define SELLER_H
#include <bits/stdc++.h>
#include "product.h"
#include "person.h"
#include "utility.h"

class SELLER : public PERSON
{
private:
    vector<int> products_IDs;

public:
    SELLER();
    SELLER(int id,QString email,QString password,QString name,QString address,CreditCard creditCard,QString Phone_num,
             QString securityQuestion,QString securityAnswer,int BirthDay,int BirthMonth,int BirthYear,vector<int> &products_IDs);

    void Addproduct(QString path,QString description,QString name,int quantity,float price,QString category);
    vector<int> getProducts_IDs();
    void setProducts_IDs(vector<int> &newProducts_IDs);
};

#endif // SELLER_H

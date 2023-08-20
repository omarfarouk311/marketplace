#include "seller.h"


SELLER::SELLER(){}

SELLER::SELLER(int id, QString email, QString password, QString name, QString address, CreditCard creditCard, QString Phone_num,
               QString securityQuestion, QString securityAnswer, int BirthDay, int BirthMonth, int BirthYear,
               vector<int> &products_IDs) : PERSON(id,email,password,name,address,creditCard,Phone_num, securityQuestion,securityAnswer,BirthDay,BirthMonth,BirthYear)
{
    this->products_IDs = products_IDs;
}

vector<int> SELLER::getProducts_IDs()
{
    return products_IDs;
}

void SELLER::setProducts_IDs(vector<int> &newProducts_IDs)
{
    products_IDs = newProducts_IDs;
}

void SELLER::Addproduct(QString path, QString description, QString name, int quantity, float price, QString category)
{
    PRODUCT product(path,description,name,quantity,price,UTILITY::RetrieveCategoryID(category),getId());
    products_IDs.push_back(product.getID());
    UTILITY::AddProduct(product);
}

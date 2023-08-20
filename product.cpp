#include "product.h"
#include <QString>
#include <bits/stdc++.h>
#include "utility.h"

using namespace std;

PRODUCT::PRODUCT() {}

PRODUCT::PRODUCT(QString path, QString description, QString name, int quantity, float price, int category, int seller_id)
{
    this->path=path;
    this->description=description;
    this->name=name;
    this->quantity=quantity;
    this->price=price;
    this->category=category;
    this->seller_ID = seller_id;
    this->ID = UTILITY::GetProducts().size();
    numberSold = rating = numberOfRatings = 0;
    comments = {};
}

PRODUCT::PRODUCT(QString path, QString description, QString name, int quantity, float price, int category, int seller_id, int ID,
                 int numberSold, float rating, vector<pair<QString, QString>> &comments, int numberOfRatings)
{
    this->path=path;
    this->description=description;
    this->name=name;
    this->quantity=quantity;
    this->price=price;
    this->category=category;
    this->seller_ID = seller_id;
    this->ID = ID;
    this->numberSold = numberSold;
    this->rating = rating;
    this->comments = comments;
    this->numberOfRatings = numberOfRatings;
}

void PRODUCT::setSeller_ID(int newSeller_ID)
{
    seller_ID = newSeller_ID;
}

void PRODUCT::setDescription(QString newDescription)
{
    description = newDescription;
}

void PRODUCT::setName( QString newName)
{
    name = newName;
}

void PRODUCT::setQuantity(int newQuantity)
{
    quantity = newQuantity;
}

void PRODUCT::setPrice(float newPrice)
{
    price = newPrice;
}

void PRODUCT::setPath(QString newPath)
{
    path = newPath;
}

void PRODUCT::setCategory(int newCategory)
{
    category = newCategory;
}

void PRODUCT::setID(int newID)
{
    ID = newID;
}

void PRODUCT::setNumberSold(int newNumberSold)
{
    numberSold = newNumberSold;
}

vector<pair<QString, QString> > PRODUCT::getComments()
{
    return comments;
}

void PRODUCT::setComments(vector<pair<QString, QString> > &newComments)
{
    comments = newComments;
}

void PRODUCT::setNumberOfRatings(int newNumberOfRatings)
{
    numberOfRatings = newNumberOfRatings;
}

void PRODUCT::decrement(int value)
{

    this->quantity-=value;
    this->numberSold+=value;
}

void PRODUCT::Addcomment(QString name, QString comment)
{
    comments.emplace_back(name,comment);
}

QString PRODUCT::getPath()
{
    return this->path;
}

void PRODUCT::Increment_Rating()
{
    this->numberOfRatings++;
}

int PRODUCT::getCategory()
{
    return this->category;
}

QString PRODUCT::getName()
{
    return this->name;
}

int PRODUCT::getID()
{
    return this->ID;
}

float PRODUCT::getPrice()
{
    return this->price;
}

int PRODUCT::getNumberOfRatings()
{
    return this->numberOfRatings;
}

void PRODUCT::setRating(float Rating)
{
    this->rating = Rating;
}

int PRODUCT::getNumberSold()
{
    return this->numberSold;
}

float PRODUCT::getRating()
{
    return this->rating;
}

int PRODUCT::getQuantity()
{
    return this->quantity;
}

int PRODUCT::getSeller_ID()
{
    return this->seller_ID;
}

QString PRODUCT::getdescription()
{
    return this->description;
}

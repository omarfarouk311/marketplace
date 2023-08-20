#ifndef PRODUCT_H
#define PRODUCT_H
#include <bits/stdc++.h>
#include <QString>

using namespace std;

class PRODUCT
{
private:
    int seller_ID;
    QString description;
    QString name;
    int quantity;
    float price;
    QString path;
    int category;
    int ID;
    int numberSold;
    float rating;
    vector<pair<QString,QString>> comments;
    int numberOfRatings;

public:
    PRODUCT();
    PRODUCT(QString path,QString description,QString name,int quantity,float price,int category,int seller_id);
    PRODUCT(QString path,QString description,QString name,int quantity,float price,int category,int seller_id,int ID,int numberSold,
            float rating,vector<pair<QString,QString>> &comments,int numberOfRatings);

    void decrement(int value);
    void Addcomment(QString name,QString comment);
    int getSeller_ID();
    QString getdescription();
    QString getName();
    int getQuantity();
    float getPrice();
    QString getPath();
    void Increment_Rating();
    int getCategory();
    int getID();
    int getNumberSold();
    float getRating();
    int getNumberOfRatings();
    void setRating(float Rating);
    void setSeller_ID(int newSeller_ID);
    void setDescription(QString newDescription);
    void setName(QString newName);
    void setQuantity(int newQuantity);
    void setPrice(float newPrice);
    void setPath(QString newPath);
    void setCategory(int newCategory);
    void setID(int newID);
    void setNumberSold(int newNumberSold);
    vector<pair<QString, QString> > getComments();
    void setComments(vector<pair<QString, QString> > &newComments);
    void setNumberOfRatings(int newNumberOfRatings);
};

#endif // PRODUCT_H

#ifndef PERSON_H
#define PERSON_H
#include "creditcard.h"
#include<QString>
#include <bits/stdc++.h>
#include "utility.h"
using namespace std;


class PERSON
{
private:
    int id;
    QString name,email,password,address,phone_num,securityQuestion,securityAnswer;
    int BirthDay,BirthMonth,BirthYear;
    CreditCard creditCard;

public:
    PERSON();
    PERSON(int id,QString email,QString password,QString name,QString address,CreditCard creditCard,QString Phone_num,
           QString securityQuestion,QString securityAnswer,int BirthDay,int BirthMonth,int BirthYear);

    void SIGN_UP(QString email,QString password,QString name,QString address,CreditCard creditCard,QString Phone_num,int type,
                    QString securityQuestion,QString securityAnswer,int BirthDay,int BirthMonth,int BirthYear);

    //setters and getters
    QString GetName();
    QString GetPassword();
    QString GetEmail();
    QString GetSecurtyQuestion();
    QString GetSecurityAnswer();
    CreditCard getCreditCard();
    void setCreditCard(CreditCard &obj);
    QString getAddress();
    QString getPhone_num();
    int getId();
    void setName(QString newName);
    void setEmail(QString newEmail);
    void setPassword( QString newPassword);
    void setAddress( QString newAddress);
    void setPhone_num(QString newPhone_num);
    QString getSecurityQuestion() ;
    void setSecurityQuestion(QString newSecurityQuestion);
    void setSecurityAnswer(QString newSecurityAnswer);
    int getBirthDay();
    void setBirthDay(int newBirthDay);
    int getBirthMonth();
    void setBirthMonth(int newBirthMonth);
    int getBirthYear();
    void setBirthYear(int newBirthYear);
    void setId(int newId);
};

#endif // PERSON_H

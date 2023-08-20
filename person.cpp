#include "person.h"
#include<userdata.h>

void PERSON::setId(int newId)
{
    id = newId;
}

PERSON::PERSON() {}

PERSON::PERSON(int id, QString email, QString password, QString name, QString address, CreditCard creditCard, QString Phone_num,
               QString securityQuestion, QString securityAnswer, int BirthDay, int BirthMonth, int BirthYear)
{
    this->id = id;
    this->email=email;
    this->password=password;
    this->name=name;
    this->address = address;
    this->phone_num=Phone_num;
    this->securityQuestion=securityQuestion;
    this->securityAnswer=securityAnswer;
    this->creditCard=creditCard;
    this->BirthDay = BirthDay;
    this->BirthMonth = BirthMonth;
    this->BirthYear = BirthYear;
}

void PERSON::SIGN_UP(QString email, QString password, QString name, QString address,CreditCard creditCard ,QString Phone_num,
                        int type, QString securityQuestion, QString securityAnswer,int BirthDay,int BirthMonth,int BirthYear)
{
    this->email=email;
    this->password=password;
    this->name=name;
    this->address = address;
    this->phone_num=Phone_num;
    this->securityQuestion=securityQuestion;
    this->securityAnswer=securityAnswer;
    this->creditCard=creditCard;
    this->BirthDay = BirthDay;
    this->BirthMonth = BirthMonth;
    this->BirthYear = BirthYear;

    // check if this person is customer or seller
    if(type==1){
        string t1="1"+to_string(UserData::GetCustomers().size());
        this->id=stoi(t1);

    }

    else {
        string t1="2"+to_string(UserData::GetSellers().size());
        this->id=stoi(t1);
    }

    UTILITY::AddVerification(id,password);
    UTILITY::AddQuestion(id,{securityQuestion,securityAnswer});
    UTILITY::AddEmailToId(email,id);
}

int PERSON::getBirthDay()
{
    return BirthDay;
}

void PERSON::setBirthDay(int newBirthDay)
{
    BirthDay = newBirthDay;
}

int PERSON::getBirthMonth()
{
    return BirthMonth;
}

void PERSON::setBirthMonth(int newBirthMonth)
{
    BirthMonth = newBirthMonth;
}

int PERSON::getBirthYear()
{
    return BirthYear;
}

void PERSON::setBirthYear(int newBirthYear)
{
    BirthYear = newBirthYear;
}

void PERSON::setName(QString newName)
{
    name = newName;
}

void PERSON::setEmail(QString newEmail)
{
    email = newEmail;
}

void PERSON::setPassword(QString newPassword)
{
    password = newPassword;
}

void PERSON::setAddress(QString newAddress)
{
    address = newAddress;
}

void PERSON::setPhone_num(QString newPhone_num)
{
    phone_num = newPhone_num;
}

QString PERSON::getSecurityQuestion()
{
    return securityQuestion;
}

void PERSON::setSecurityQuestion(QString newSecurityQuestion)
{
    securityQuestion = newSecurityQuestion;
}

void PERSON::setSecurityAnswer(QString newSecurityAnswer)
{
    securityAnswer = newSecurityAnswer;
}

QString PERSON::GetName()
{
    return name;
}

QString PERSON::GetPassword()
{
    return password;
}

QString PERSON::GetEmail()
{
    return email;
}

QString PERSON::GetSecurtyQuestion()
{
    return securityQuestion;
}

QString PERSON::GetSecurityAnswer()
{
    return securityAnswer;
}

CreditCard PERSON::getCreditCard()
{
    return creditCard;
}

void PERSON::setCreditCard(CreditCard &obj)
{
    creditCard = obj;
}

QString PERSON::getAddress()
{
    return address;
}

QString PERSON::getPhone_num()
{
    return phone_num;
}

int PERSON::getId()
{
    return id;
}

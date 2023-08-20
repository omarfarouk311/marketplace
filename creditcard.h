#ifndef CREDITCARD_H
#define CREDITCARD_H
#include<QString>
#include<iostream>
using namespace std;

class CreditCard
{
private:
    long long number;
    int csv,expiry_month,expiry_year;

public:
    CreditCard();
    CreditCard(long long number,int csv,int expiry_month,int expiry_year);

    long long getNumber();
    void setNumber(long long newNumber);
    int getCsv();
    void setCsv(int newCsv);
    int getExpiry_month();
    void setExpiry_month(int newExpiry_month);
    int getExpiry_year();
    void setExpiry_year(int newExpiry_year);
};

#endif // CREDITCARD_H

#include "creditcard.h"

CreditCard::CreditCard() {}

CreditCard::CreditCard(long long number, int csv, int expiry_month, int expiry_year)
{
    this->number = number;
    this->csv = csv;
    this->expiry_month = expiry_month;
    this->expiry_year = expiry_year;
}

int CreditCard::getExpiry_month()
{
    return expiry_month;
}

void CreditCard::setExpiry_month(int newExpiry_month)
{
    expiry_month = newExpiry_month;
}

int CreditCard::getExpiry_year()
{
    return expiry_year;
}

void CreditCard::setExpiry_year(int newExpiry_year)
{
      expiry_year = newExpiry_year;
}

long long CreditCard::getNumber()
{
    return number;
}

void CreditCard::setNumber(long long newNumber)
{
        number=newNumber;
}

int CreditCard::getCsv()
{
    return csv;
}

void CreditCard::setCsv(int newCsv) {
        csv=newCsv;
}


#include "userdata.h"



SELLER UserData::GetSeller(int id)
{
    string s = to_string(id);
    return sellers[stoi(s.substr(1))];
}

CUSTOMER UserData::GetCustomer(int id)
{
    string s = to_string(id);
    return customers[stoi(s.substr(1))];
}

void UserData::AddSellers(SELLER &s)
{
    sellers.push_back(s);
}

void UserData::AddCustomer(CUSTOMER &c)
{
    customers.push_back(c);
}

void UserData::ModifyUser(int ID, QString password)
{
    string s = to_string(ID);
    if(s[0] == '1') {
        customers[stoi(s.substr(1))].setPassword(password);
    }
    else {
        sellers[stoi(s.substr(1))].setPassword(password);
    }
}

void UserData::ModifyCustomer(CUSTOMER &c)
{
    CART cart;
    c.setCart(cart);
    customers[stoi(to_string(c.getId()).substr(1))] = c;
}

void UserData::ModifySeller(SELLER &s)
{
    sellers[stoi(to_string(s.getId()).substr(1))] = s;
}


vector<CUSTOMER> UserData::GetCustomers()
{
    return customers;
}

vector<SELLER> UserData::GetSellers()
{
    return sellers;
}

#ifndef USERDATA_H
#define USERDATA_H
#include "CUSTOMER.h"
#include "seller.h"

class UserData
{
private:
    static inline vector<SELLER> sellers;
    static inline vector<CUSTOMER> customers;

public:
    static SELLER GetSeller(int id);
    static CUSTOMER GetCustomer(int id);
    static void AddSellers(SELLER &s);
    static void AddCustomer(CUSTOMER &c);
    static void ModifyUser(int ID, QString password);
    static vector<CUSTOMER> GetCustomers();
    static vector<SELLER> GetSellers();
    static void ModifyCustomer(CUSTOMER &c);
    static void ModifySeller(SELLER &s);
};

#endif // USERDATA_H

#ifndef CURRENTUSER_H
#define CURRENTUSER_H
#include "CUSTOMER.h"
#include "seller.h"
#include "userdata.h"


class CurrentUser
{

private:
    static inline char t;
    static inline SELLER s;
    static inline CUSTOMER c;
    static inline bool ini = 0;


public:
    static  void SetUser(int ID,char type);
    static  char GetType();
    static  CUSTOMER* GetCustomer();
    static  SELLER* GetSeller();
    static  void LogOut();


};

#endif // CURRENTUSER_H

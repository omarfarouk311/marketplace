
#include "currentuser.h"




void CurrentUser::SetUser(int ID, char type)
{
    ini = 1;
    t = type;

    if(type == '1')
    {
        c = UserData::GetCustomer(ID);
    }
    else
    {
        s = UserData::GetSeller(ID);
    }

}

char CurrentUser::GetType()
{
    return t;
}

CUSTOMER *CurrentUser::GetCustomer()
{
    return &c;
}

SELLER *CurrentUser::GetSeller()
{
    return &s;
}

void CurrentUser::LogOut()
{
    if(!ini) return;
    if(t == '1')
    {
        UserData::ModifyCustomer(c);
    }
    else
    {
        UserData::ModifySeller(s);
    }

}

#include "cart.h"
#include <QString>
#include <bits/stdc++.h>
using namespace std;


CART::CART() {
}

unordered_map<int, int> CART::getProducts_taken_by_user()
{
    return products_taken_by_user;
}

void CART::setProducts_taken_by_user(unordered_map<int, int> &newProducts_taken_by_user)
{
    products_taken_by_user = newProducts_taken_by_user;
}

int CART::GetQuantity(int id)
{
    return products_taken_by_user[id];
}

void CART::buy(unordered_map<int,int> &cust_History)
{
    for(auto&i:products_taken_by_user){
        cust_History[i.first] += i.second;
        UTILITY::IncrementCategories(i.first,i.second);
    }
    products_taken_by_user.clear();
}

float CART::TotalPrice()
{
    float RetTotalPrice=0.0;
    for(auto&i:products_taken_by_user){

        PRODUCT obj=UTILITY::GetProduct(i.first);
        RetTotalPrice+=(i.second*obj.getPrice());
    }
    return RetTotalPrice;
}

bool CART::add(int id, int quan)
{
    if(products_taken_by_user[id]+quan <= UTILITY::GetProduct(id).getQuantity()) {
        products_taken_by_user[id]+=quan;
        return 1;
    }
    return 0;
}

void CART::remove(int id, int quantity)
{
    if(products_taken_by_user[id] - quantity >= 0)
    products_taken_by_user[id] -= quantity;
}

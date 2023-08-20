#ifndef CART_H
#define CART_H
#include<bits/stdc++.h>
#include "utility.h"
using namespace std;


class CART
{
private:
    unordered_map<int,int> products_taken_by_user;

public:
    CART();
    void buy(unordered_map<int,int> &cust_History);
    float TotalPrice();
    bool add(int id,int quan);
    void remove(int id, int quantity);
    unordered_map<int, int> getProducts_taken_by_user();
    void setProducts_taken_by_user(unordered_map<int, int> &newProducts_taken_by_user);
    int GetQuantity(int id);
};

#endif // CART_H

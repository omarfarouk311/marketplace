#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "CART.h"
#include"person.h"
#include<bits/stdc++.h>
#include "utility.h"


class CUSTOMER : public PERSON
{
private:
    CART cart;
    //first -> product ID, second -> 1 or 0 (used or not)
    unordered_map<int,int> shopping_histroy,wishlist;
    //first -> promo code, second -> 1 or 0 (used or not)
    unordered_map<int,int> used_promo_code;
    // first -> product id, second -> number of stars (rating)
    unordered_map<int,int>starsofproduct;
    // first -> seller id, second -> number of stars (rating)
    unordered_map<int,int>startsofseller;

public:
    CUSTOMER();

    CUSTOMER(int id, QString email, QString password, QString name, QString address, CreditCard creditCard, QString Phone_num,
             QString securityQuestion, QString securityAnswer, int BirthDay, int BirthMonth, int BirthYear,
             unordered_map<int,int> &shopping_histroy, unordered_map<int,int> &wishlist, unordered_map<int,int> &used_promo_code,
             unordered_map<int, int> mp1,unordered_map<int, int> mp2);

    //
    void Checkout();
    //
    void RateSeller(int seller_id,int rating);
    //
    void RateProduct(int prod_id,int rate);
    //
    bool Promo_isUsed(int promo_code);
    //
    int checkWishlist(int id);
    //
    void modify_wishlist(int id);
    //setters and getters
    int getProductStars(int prodId);
    int getStarsseller(int sellerId);
    CART getCart();
    void setCart(CART &newCart);
    unordered_map<int,int> Get_wishlist();
    void setWishlist( unordered_map<int, int> &newWishlist);
    unordered_map<int,int> Get_shopping_history();
    void setShopping_histroy( unordered_map<int, int> &newShopping_histroy);
    unordered_map<int, int> getUsed_promo_code() ;
    void setUsed_promo_code(unordered_map<int, int> &newUsed_promo_code);
    unordered_map<int, int> GetProductStars_Files();
    void setProductStars_Files(unordered_map<int,int>mp);
    unordered_map<int, int> GetSellerStars_Files();
    void setPSellerStars_Files(unordered_map<int,int>mp);
};

#endif // CUSTOMER_H

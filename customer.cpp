#include "customer.h"

CUSTOMER::CUSTOMER() {}

CUSTOMER::CUSTOMER(int id, QString email, QString password, QString name, QString address, CreditCard creditCard, QString Phone_num,
                   QString securityQuestion, QString securityAnswer, int BirthDay, int BirthMonth, int BirthYear,
                   unordered_map<int, int> &shopping_histroy, unordered_map<int, int> &wishlist,
                   unordered_map<int, int> &used_promo_code,unordered_map<int,int>mp1,unordered_map<int, int> mp2) : PERSON(id,email,password,name,address,creditCard,Phone_num, securityQuestion,securityAnswer,BirthDay,BirthMonth,BirthYear)
{

    this->shopping_histroy = shopping_histroy;
    this->wishlist = wishlist;
    this->used_promo_code = used_promo_code;
    this->starsofproduct = mp1;
    this->startsofseller = mp2;
}

void CUSTOMER::setShopping_histroy(unordered_map<int, int> &newShopping_histroy)
{
    shopping_histroy = newShopping_histroy;
}

void CUSTOMER::setWishlist(unordered_map<int, int> &newWishlist)
{
    wishlist = newWishlist;
}

unordered_map<int, int> CUSTOMER::getUsed_promo_code()
{
    return used_promo_code;
}

void CUSTOMER::setUsed_promo_code(unordered_map<int, int> &newUsed_promo_code)
{
    used_promo_code = newUsed_promo_code;
}

CART CUSTOMER::getCart()
{
    return cart;
}

void CUSTOMER::setCart(CART &newCart)
{
    cart = newCart;
}

///////////////////////////////

int CUSTOMER::getProductStars(int prodId)
{
    return starsofproduct[prodId];
}

unordered_map<int,int> CUSTOMER::GetProductStars_Files()
{
    return starsofproduct;
}

void CUSTOMER::setPSellerStars_Files(unordered_map<int,int> mp)
{
    startsofseller=mp;
}

int CUSTOMER::getStarsseller(int sellerId)
{
    return startsofseller[sellerId];
}

unordered_map<int,int> CUSTOMER::GetSellerStars_Files()
{
    return this->startsofseller;
}

void CUSTOMER::setProductStars_Files(unordered_map<int,int> mp)
{
    starsofproduct=mp;
}

void CUSTOMER::Checkout()
{
    cart.buy(shopping_histroy);
}

void CUSTOMER::RateSeller(int seller_id, int rating)
{
    UTILITY::ModifySellerRating(seller_id,rating);
    startsofseller[seller_id] = rating;
}

bool CUSTOMER::Promo_isUsed(int promo_code)
{
    return(used_promo_code[promo_code]);
}

void CUSTOMER::RateProduct(int prod_id, int rating)
{
    UTILITY::ChangeProductRating(prod_id,rating);
    starsofproduct[prod_id] = rating;
}

void CUSTOMER::modify_wishlist(int id)
{
    wishlist[id]^=1;
}

int CUSTOMER::checkWishlist(int id)
{
    return (wishlist[id]>0);
}

unordered_map<int,int> CUSTOMER::Get_wishlist()
{
    return wishlist;
}

unordered_map<int,int> CUSTOMER::Get_shopping_history()
{
    return shopping_histroy;
}


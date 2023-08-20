#include <bits/stdc++.h>
#include "product.h"
#include <QString>
#include<QDate>
#include "creditcard.h"
#ifndef UTILITY_H
#define UTILITY_H
using namespace std;


class UTILITY
{
private:
    //first -> seller id, second -> {total rating,number of ratings}
    static inline unordered_map<int, pair<int, int>> SellerRate;
    //first -> promo code, second -> discount rate
    static inline unordered_map<int, float> promo_codes = {{74390,0.05},{43036,0.10},{10358,0.15},{11946,0.20},{20305,0.40}};
    //index -> product ID, values-> products
    static inline vector<PRODUCT> products;
    //index -> category id, values-> sold quantity
    static inline vector<int> soldByCategories;
    //first -> sold quantity, second -> product ID
    static inline set<pair<int,int>> sortedBestSelling;
    //first -> category name, second -> category ID
    static inline unordered_map<QString, int> categoryID = {{"Furniture" , 0}, {"Men's wear" , 1}, {"Women's wear" , 2},{"Kid's wear" , 3},{"Makeup" , 4}, {"Laptops" , 5},{"Video games" , 6},{"Mobile phones" , 7},{"Tablets" , 8},{"Sports" , 9},{"Health and personal care" , 10},{"Pet supplies" , 11},{"Books" , 12}};
    //first -> user ID, second -> password
    static inline unordered_map<int, QString> verification;
    //first -> user ID, second -> {question,answer}
    static inline unordered_map<int,pair<QString, QString>> questions;
    //first -> email, second -> id
    static inline unordered_map<QString, int> emailToID;

public:
    //resize soldByCategories vector(13)
    static void Init();
    //mapping user email to his ID
    static void AddEmailToId(QString email,int id);
    //mapping user ID to his security questions
    static void AddQuestion(int id,pair<QString,QString>p);
    //mapping user ID to his password
    static void AddVerification(int id,QString pass);
    //modify sellerRate map
    static void ModifySellerRating(int sellerID, float rate);
    //push a new product in the vector
    static void AddProduct(PRODUCT p);
    //uses trie to search
    static vector<int> Search(string s);
    //returns a specific product based on the passed ID
    static PRODUCT &GetProduct(int ID);
    //return the best selling products (top n products based on the passed number)
    static vector<PRODUCT> BestSelling(int numberOfProducts);
    //increment the sold quantity in soldbycategory map and bestSelling map and decrement the remaining quantity of this product
    static void IncrementCategories(int ID, int quantity);
    //return the ID of the passed category name
    static int RetrieveCategoryID(QString s);
    //sorting the products based on type -> best selling/rating/price in each categor/wishlist/buy again window
    static void SortProducts(vector<PRODUCT> &v ,int type);
    //return the security question of the user
    static QString GetQuestion(int UserID);
    //checking if the user answer matches the answer for his security question
    static bool VerifyAns(int UserID, QString ans);
    //returns the id of the user
    static int GetUserID(QString email);
    //checking if the password matches the user password
    static bool VerifyPassword(int UserID, QString password);
    static vector<PRODUCT> GetCatogeryProducts(int catId);
    //returns the size of products vector to generate new ID based on it
    static int GetNumberOfProducts();
    //verify that the email isn't used and if it's true it calls signup function
    static bool AddAccount(QString email, QString password, QString name, QString address,CreditCard creditCard ,QString Phone_num,
                           int type, QString securityQuestion, QString securityAnswer,int BirthDay,int BirthMonth,int BirthYear);
    //display top n categories based on the passed number
    static vector<int> TopCategories(int numberOfCategories);
    //modifies user password if the he provided right answer for the security question
    static void ModifyPassword(int UserId, QString password);
    //calculates the product rating
    static void ChangeProductRating(int id, float addedRating);
    //checks if the promo code exists
    static float CheckPromo(int code);
    //setters and getters to store the containers in files
    static vector<PRODUCT> GetProducts();
    static float GetSellerRating(int sellerID);
    static unordered_map<int, pair<int, int> > getSellerRate();
    static void setSellerRate(unordered_map<int, pair<int, int> > &newSellerRate);
    static unordered_map<int, float> getPromo_codes();
    static void setPromo_codes(unordered_map<int, float> &newPromo_codes);
    static vector<int> getsoldByCategories();
    static void setsoldByCategories(vector<int> &newCategories);
    static set<pair<int, int> > getSortedBestSelling();
    static void setSortedBestSelling(set<pair<int, int> > &newSortedBestSelling);
    static unordered_map<QString, int> getCategoryID();
    static void setCategoryID(unordered_map<QString, int> &newCategoryID);
    static void setProducts(vector<PRODUCT> &newProducts);
    static unordered_map<int, QString> getVerification();
    static void setVerification(unordered_map<int, QString> &newVerification);
    static unordered_map<int, pair<QString, QString> > getQuestions();
    static void setQuestions(unordered_map<int, pair<QString, QString> > &newQuestions);
    static unordered_map<QString, int> getEmailToID();
    static void setEmailToID(unordered_map<QString, int> &newEmailToID);

    //trie to use it in search bar
    struct TrieNode {

        TrieNode* children[96];
        vector<int>v;
        bool isWordEnd;
    };

    struct trie{
        TrieNode *root;

        trie(){
            root=new TrieNode();
        }

        void insert(string s,int id)
        {
            for(auto &i: s) {
                if(i >= 'A' && i <= 'Z') {
                    i += 32;
                }
            }
            TrieNode* pnode = root;
            for (int i = 0; i < s.length(); i++) {
                int index = s[i] - ' ';
                //if(s[i] == ' ') index = 96;
                if (!pnode->children[index])
                    pnode->children[index] = new TrieNode();

                pnode = pnode->children[index];
            }
            pnode->v.push_back(id);
            pnode->isWordEnd = true;
        }


        void search(TrieNode *cur,string currPrefix,bool ch,vector<int>&ret)
        {
            if(ch){
                for(int i=0;i<currPrefix.size();i++){
                    int cha=currPrefix[i]-' ';
                    //if(currPrefix[i] == ' ') cha = 75;
                    if(cur->children[cha])
                        cur=cur->children[cha];
                    else {
                        return;
                    }
                }
            }

            if (cur->isWordEnd) {
                for(int i=0;i<cur->v.size();i++){
                    ret.push_back(cur->v[i]);
                }
            }

            for (int i = 0; i <= 95; i++)
                if (cur->children[i]) {
                    //char child = 'a' + i;
                    search(cur->children[i]," ",0,ret);
                }

        }
    };

private:
    static inline trie t;

};

#endif // UTILITY_H

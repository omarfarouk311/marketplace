#include "utility.h"
#include"person.h"
#include "userdata.h"

unordered_map<int, pair<int, int> > UTILITY::getSellerRate()
{
    return SellerRate;
}

void UTILITY::setSellerRate(unordered_map<int, pair<int, int> > &newSellerRate)
{
    SellerRate = newSellerRate;
}

unordered_map<int, float> UTILITY::getPromo_codes()
{
    return promo_codes;
}

void UTILITY::setPromo_codes(unordered_map<int, float> &newPromo_codes)
{
    promo_codes = newPromo_codes;
}

vector<int> UTILITY::getsoldByCategories()
{
    return soldByCategories;
}

void UTILITY::setsoldByCategories(vector<int> &newCategories)
{
    soldByCategories = newCategories;
}

set<pair<int, int> > UTILITY::getSortedBestSelling()
{
    return sortedBestSelling;
}

void UTILITY::setSortedBestSelling(set<pair<int, int> > &newSortedBestSelling)
{
    sortedBestSelling = newSortedBestSelling;
}

unordered_map<QString, int> UTILITY::getCategoryID()
{
    return categoryID;
}

void UTILITY::setCategoryID(unordered_map<QString, int> &newCategoryID)
{
    categoryID = newCategoryID;
}

void UTILITY::setProducts(vector<PRODUCT> &newProducts)
{
    products = newProducts;
}

unordered_map<int, QString> UTILITY::getVerification()
{
    return verification;
}

void UTILITY::setVerification(unordered_map<int, QString> &newVerification)
{
    verification = newVerification;
}

unordered_map<int, pair<QString, QString> > UTILITY::getQuestions()
{
    return questions;
}

void UTILITY::setQuestions(unordered_map<int, pair<QString, QString> > &newQuestions)
{
    questions = newQuestions;
}

unordered_map<QString, int> UTILITY::getEmailToID()
{
    return emailToID;
}

void UTILITY::setEmailToID(unordered_map<QString, int> &newEmailToID)
{
    emailToID = newEmailToID;
}

void UTILITY::Init()
{
    soldByCategories.resize(13);
}

void UTILITY::AddEmailToId(QString email, int id)
{
    emailToID[email]=id;
}

void UTILITY::AddQuestion(int id, pair<QString, QString> p)
{
    questions[id]=p;
}

void UTILITY::AddVerification(int id, QString pass)
{
    verification[id]=pass;
}

void UTILITY::ModifySellerRating(int sellerID, float rate)
{
    SellerRate[sellerID].first += rate;
    SellerRate[sellerID].second++;
}

vector<PRODUCT> UTILITY::GetProducts()
{
    return products;
}

void UTILITY::AddProduct(PRODUCT p)
{
    products.push_back(p);
    sortedBestSelling.insert({0, p.getID()});
    t.insert(p.getName().toStdString(), p.getID());
}

vector<int> UTILITY::Search(string s)
{
    std::vector<int> ret;
    t.search(t.root, s, 1, ret);
    return ret;
}

PRODUCT &UTILITY::GetProduct(int ID)
{

    return products[ID];
}

vector<PRODUCT> UTILITY::BestSelling(int numberOfProducts)
{
    vector<PRODUCT> ret;
    auto it=sortedBestSelling.end();
    if(!sortedBestSelling.empty()) it--;
    for (int i = 0 ; i < min(numberOfProducts,(int)products.size()) ; i++ ) {
        ret.push_back(products[it->second]);
        it--;
    }
    return ret;
}

void UTILITY::IncrementCategories(int productID, int quantity)
{
    soldByCategories[products[productID].getCategory()] += quantity;
    sortedBestSelling.insert({products[productID].getNumberSold() + quantity, productID});
    sortedBestSelling.erase({products[productID].getNumberSold(), productID});
    products[productID].decrement(quantity);
}

int UTILITY::RetrieveCategoryID(QString s)
{
    return categoryID[s];    
}


void UTILITY::SortProducts(vector<PRODUCT> &v, int type)
{
    if(type == 0)
        sort(v.begin(), v.end(), [](PRODUCT &x, PRODUCT &y) { return x.getRating() > y.getRating(); });
    else if(type == 1)
        sort(v.begin(), v.end(), [](PRODUCT &x, PRODUCT &y) { return x.getPrice() > y.getPrice(); });
    else if(type == 2)
        sort(v.begin(), v.end(), [](PRODUCT &x, PRODUCT &y) { return x.getNumberSold() > y.getNumberSold(); });
}

QString UTILITY::GetQuestion(int UserID)
{
    return questions[UserID].first;
}

bool UTILITY::VerifyAns(int UserID, QString ans)
{
    return (questions[UserID].second == ans);
}

int UTILITY::GetUserID(QString email)
{
    return emailToID[email];
}

bool UTILITY::VerifyPassword(int UserID, QString password)
{
    return (verification[UserID] == password);
}

vector<PRODUCT> UTILITY::GetCatogeryProducts(int catId)
{
    vector<PRODUCT> ret;

    for(auto &i : products) {
        if(i.getCategory() == catId)
            ret.push_back(i);
    }

    return ret;
}

int UTILITY::GetNumberOfProducts()
{
    return products.size();
}

bool UTILITY::AddAccount(QString email, QString password, QString name, QString address,CreditCard creditCard ,QString Phone_num,
                             int type, QString securityQuestion, QString securityAnswer,int BirthDay,int BirthMonth,int BirthYear)
{
    if(!emailToID[email]){
        if(type == 1){
            CUSTOMER obj;
            obj.SIGN_UP(email,password,name,address,creditCard,Phone_num,type,securityQuestion,securityAnswer,BirthDay,BirthMonth,BirthYear);
            UserData::AddCustomer(obj);
        }
        else {
            SELLER obj;
            obj.SIGN_UP(email,password,name,address,creditCard,Phone_num,type,securityQuestion,securityAnswer,BirthDay,BirthMonth,BirthYear);
            UserData::AddSellers(obj);
        }
        return true;
    }
    return false;
}

void UTILITY::ModifyPassword(int UserId, QString password)
{
    verification[UserId] = password;
    UserData::ModifyUser(UserId, password);
}

void UTILITY::ChangeProductRating(int id, float addedRating)
{
    float newRating = products[id].getRating() * products[id].getNumberOfRatings();
    newRating += addedRating;
    products[id].Increment_Rating();
    newRating /= products[id].getNumberOfRatings();
    products[id].setRating(newRating);
}

float UTILITY::CheckPromo(int code)
{
    return promo_codes[code];
}

float UTILITY::GetSellerRating(int sellerID)
{
    if(SellerRate[sellerID].second)
        return (SellerRate[sellerID].first / SellerRate[sellerID].second);
    return 0;
}

vector<int> UTILITY::TopCategories(int numberOfCategories)
{
    //numbersold, category ID
    vector<pair<int, int>> temp;
    for (int i = 0; i < soldByCategories.size(); i++) {
        temp.emplace_back(soldByCategories[i], i);
    }
    sort(temp.rbegin(), temp.rend());
    vector<int> ret;
    for (int i = 0; i < min(numberOfCategories, (int)temp.size()); ++i) {
        ret.push_back(temp[i].second);
    }
    return ret;
}

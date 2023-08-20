#include "files.h"

FILES::FILES() {}


// starsfiles need to be updated
void FILES::read_customer()
{
    //opening the file
    ifstream file("customer.txt",ios::in);
    if(!file) return;
    //reading until the end of the file
    int id;
    while(file >> id) {

        //declaring the variables that the data from the file will be stored in
        string email,name,password,address,phone_num,securityQuestion,securityAnswer;
        long long number;
        int csv,expiry_month,expiry_year,BirthDay,BirthMonth,BirthYear;
        pair<int,int> tmp;
        unordered_map<int,int> productStars,sellerStars;
        unordered_map<int,int> cart,shopping_histroy,wishlist,used_promo_code;
        //reading person data
        file >> email >> name >> password >> address >> phone_num >> securityQuestion >> securityAnswer >> BirthDay
            >> BirthMonth >> BirthYear >> number >> csv >> expiry_month >> expiry_year;

        //replace % with space
        for(int i=0;i<securityQuestion.size();i++){
            if(securityQuestion[i]=='%')
                securityQuestion[i]=' ';
        }

        for(int i=0;i<securityAnswer.size();i++){
            if(securityAnswer[i]=='%')
                securityAnswer[i]=' ';
        }


        for(int i=0;i<address.size();i++){
            if(address[i]=='%')
                address[i]=' ';
        }

        //reading shopping history data
        file >> tmp.first >> tmp.second;
        while(tmp.first != -1) {
            shopping_histroy.insert(tmp);
            file >> tmp.first >> tmp.second;
        }
        //reading wishlist data
        file >> tmp.first >> tmp.second;
        while(tmp.first != -1) {
            wishlist.insert(tmp);
            file >> tmp.first >> tmp.second;
        }
        //reading promo codes data
        file >> tmp.first >> tmp.second;
        while(tmp.first != -1) {
            used_promo_code.insert(tmp);
            file >> tmp.first >> tmp.second;
        }
        //reading product stars data
        file >> tmp.first >> tmp.second;
        while(tmp.first!=-1){
             productStars.insert(tmp);
            file >> tmp.first >> tmp.second;
        }
        //reading seller stars data
        file >> tmp.first >> tmp.second;
        while(tmp.first!=-1){
             sellerStars.insert(tmp);
            file >> tmp.first >> tmp.second;
        }
        //setting credit card data
        CreditCard credit(number,csv,expiry_month,expiry_year);
        //setting all customer data
        CUSTOMER customer(id,QString::fromStdString(email),QString::fromStdString(password),QString::fromStdString(name),
                          QString::fromStdString(address),credit,QString::fromStdString(phone_num),
                          QString::fromStdString(securityQuestion),QString::fromStdString(securityAnswer),BirthDay,BirthMonth,
                          BirthYear,shopping_histroy,wishlist,used_promo_code, productStars,sellerStars);
        //pushing customer to the vector
        UserData::AddCustomer(customer);
    }
}

void FILES::write_customer()
{
    //opening file
    ofstream file("customer.txt");
    //counter to avoid inserting new line in the end of the file
    int cnt = UserData::GetCustomers().size();
    //looping on customers vector
    for(auto &i : UserData::GetCustomers()) {
        --cnt;
        //writing person data
        QString Q=i.GetSecurtyQuestion();
        for(int i=0;i<Q.size();i++){
            if(Q[i]==' ')
                Q[i]='%';
        }

        QString ans=i.GetSecurityAnswer();
        for(int i=0;i<ans.size();i++){
            if(ans[i]==' ')
                ans[i]='%';
        }

        QString address=i.getAddress();
        for(int i=0;i<address.size();i++) {
            if(address[i]==' ')
                address[i]='%';
        }

        file << i.getId() << ' ' << i.GetEmail().toStdString() << ' ' << i.GetName().toStdString() << ' ' << i.GetPassword().toStdString()
             << ' ' << address.toStdString() << ' ' << i.getPhone_num().toStdString()
             << ' ' << Q.toStdString() << ' ' << ans.toStdString()
             << ' ' << i.getBirthDay() << ' ' << i.getBirthMonth() << ' ' << i.getBirthYear()
             << ' ' << i.getCreditCard().getNumber() << ' ' << i.getCreditCard().getCsv() << ' ' << i.getCreditCard().getExpiry_month()
             << ' ' << i.getCreditCard().getExpiry_year() << endl;
        //writing shopping history data
        auto mp1 = i.Get_shopping_history();
        for(auto &i : mp1) {
            file << i.first << ' ' << i.second << endl;
        }
        file << -1 << ' ' << -1 << endl;
        //writing wishlist data
        mp1 = i.Get_wishlist();
        for(auto &i : mp1) {
            file << i.first << ' ' << i.second << endl;
        }
        file << -1 << ' ' << -1 << endl;
        //writing promo code data
        mp1 = i.getUsed_promo_code();
        for(auto &i : mp1) {
            file << i.first << ' ' << i.second << endl;
        }
        file << -1 << ' ' << -1 << endl;
        //writing product stars data
        auto stars = i.GetProductStars_Files();
        for(auto &i : stars){
            file << i.first << ' ' << i.second << endl;
        }
        file << -1 << ' ' << -1 << endl;
        //writing seller stars data
        stars = i.GetSellerStars_Files();
        for(auto &i : stars){
            file << i.first << ' ' << i.second << endl;
        }
        file << -1 << ' ' << -1;
        if(cnt) file << endl;
    }
}

void FILES::read_products()
{
    //opening the file
    ifstream file("product.txt",ios::in);
    if(!file) return;
    //reading until the end of the file
    int seller_ID;
    while(file >> seller_ID) {
        //declaring the variables that the data from the file will be stored in
        int quantity,category,ID,numberSold,rating,numberOfRatings;
        string name,path,description;
        float price;
        pair<string,string> tmp;
        vector<pair<QString,QString>> v;
        //reading product data
        file >> description >> name >> quantity >> price >> path >> category >> ID >> numberSold >> rating
            >> numberOfRatings;

        for(int i=0;i<name.size();i++){
            if(name[i]=='%')
                name[i]=' ';
        }

        for(int i=0;i<description.size();i++){
            if(description[i]=='%')
                description[i]=' ';
        }

        for(int i=0;i<path.size();i++){
            if(path[i]=='%')
                path[i]=' ';
        }
        //reading comments data
        file >> tmp.first >> tmp.second;
        while(tmp.first != "~") {
            string username=tmp.first;
            string com=tmp.second;
            for(int i=0;i<username.size();i++){
                if(username[i]=='%')
                    username[i]=' ';
            }
            for(int i=0;i<com.size();i++){
                if(com[i]=='%')
                    com[i]=' ';
            }
            v.push_back({QString::fromStdString(username),QString::fromStdString(com)});
            file >> tmp.first >> tmp.second;
        }
        //setting all product data
        PRODUCT product(QString::fromStdString(path),QString::fromStdString(description),QString::fromStdString(name),quantity,price,
                        category,seller_ID,ID,numberSold,rating,v,numberOfRatings);
        //pushing product to the vector
        UTILITY::AddProduct(product);
    }
}

void FILES::write_products()
{
    //opening file
    ofstream file("product.txt");
    //counter to avoid inserting new line in the end of the file
    int cnt = UTILITY::GetProducts().size();
    //looping on products vector
    for(auto &i : UTILITY::GetProducts()) {
        --cnt;
        QString name=i.getName();
        for(int i=0;i<name.size();i++){
            if(name[i]==' ')
                name[i]='%';
        }

        QString desc=i.getdescription();
        for(int i=0;i<desc.size();i++){
            if(desc[i]==' ')
                desc[i]='%';
        }

        QString pth=i.getPath();
        for(int i=0;i<pth.size();i++){
            if(pth[i]==' ')
                pth[i]='%';
        }

        //writing product data
        file << i.getSeller_ID() << ' ' << desc.toStdString() << ' ' << name.toStdString() << ' '
             << i.getQuantity() << ' ' << i.getPrice() << ' ' << pth.toStdString() << ' ' << i.getCategory() << ' '
             << i.getID() << ' ' << i.getNumberSold() << ' ' << i.getRating() << ' ' << i.getNumberOfRatings() << endl;

        //writing comments data
        auto v = i.getComments();
        for(auto &i : v) {
            string qu=i.first.toStdString();
            string ans=i.second.toStdString();
            for(int i=0;i<qu.size();i++){
                if(qu[i]==' ')
                    qu[i]='%';
            }

            for(int i=0;i<ans.size();i++){
                if(ans[i]==' ')
                    ans[i]='%';
            }
            file<< qu <<' '<< ans << endl;
        }
        file << "~" << ' ' << "~";
        if(cnt) file << endl;
    }
}

void FILES::read_seller()
{
    //opening the file
    ifstream file("seller.txt",ios::in);
    if(!file) return;
    //reading until the end of the file
    int id;
    while(file >> id) {
        //declaring the variables that the data from the file will be stored in
        string email,name,password,address,phone_num,securityQuestion,securityAnswer;
        long long number;
        int csv,expiry_month,expiry_year,BirthDay,BirthMonth,BirthYear,x;
        vector<int> v;
        //reading person data
        file >> email >> name >> password >> address >> phone_num >> securityQuestion >> securityAnswer >> BirthDay
            >> BirthMonth >> BirthYear >> number >> csv >> expiry_month >> expiry_year;
        //reding vector of products IDs

        for(int i=0;i<securityQuestion.size();i++){
            if(securityQuestion[i]=='%')
                securityQuestion[i]=' ';
        }

        for(int i=0;i<securityAnswer.size();i++){
            if(securityAnswer[i]=='%')
                securityAnswer[i]=' ';
        }


        for(int i=0;i<address.size();i++){
            if(address[i]=='%')
                address[i]=' ';
        }

        file >> x;
        while(x != -1) {
            v.push_back(x);
            file >> x;
        }
        //setting credit card data
        CreditCard credit(number,csv,expiry_month,expiry_year);
        //setting all customer data
        SELLER seller(id,QString::fromStdString(email),QString::fromStdString(password),QString::fromStdString(name),
                      QString::fromStdString(address),credit,QString::fromStdString(phone_num),
                      QString::fromStdString(securityQuestion),QString::fromStdString(securityAnswer),BirthDay,BirthMonth,
                      BirthYear,v);
        //pushing seller to the vector
        UserData::AddSellers(seller);
    }
}

void FILES::write_seller()
{
    //opening file
    ofstream file("seller.txt");
    //counter to avoid inserting new line in the end of the file
    int cnt = UserData::GetSellers().size();
    //looping on sellers vector
    for(auto &i : UserData::GetSellers()) {
        --cnt;
        QString Q=i.GetSecurtyQuestion();
        for(int i=0;i<Q.size();i++){
            if(Q[i]==' ')
                Q[i]='%';
        }

        QString ans=i.GetSecurityAnswer();
        for(int i=0;i<ans.size();i++){
            if(ans[i]==' ')
                ans[i]='%';
        }

        QString address=i.getAddress();
        for(int i=0;i<address.size();i++)
            if(address[i]==' ')
                address[i]='%';

        //writing person data
        file << i.getId() << ' ' << i.GetEmail().toStdString() << ' ' << i.GetName().toStdString() << ' ' << i.GetPassword().toStdString()
             << ' ' << address.toStdString() << ' ' << i.getPhone_num().toStdString()
             << ' ' << Q.toStdString() << ' ' << ans.toStdString()
             << ' ' << i.getBirthDay() << ' ' << i.getBirthMonth() << ' ' << i.getBirthYear()
             << ' ' << i.getCreditCard().getNumber() << ' ' << i.getCreditCard().getCsv() << ' ' << i.getCreditCard().getExpiry_month()
             << ' ' << i.getCreditCard().getExpiry_year() << ' ';
        //writing IDs data
        auto v = i.getProducts_IDs();
        for(auto &i : v) {
            file << i << ' ';
        }
        file << -1;
        if(cnt) file << endl;
    }
}

void FILES::read_SellerRate()
{
    ifstream file("SellerRate.txt",ios::in);
    if(!file) return;

    pair<int,pair<int,int>> tmp;
    unordered_map<int,pair<int,int>> mp;
    //looping until the end of the file
    while(file >> tmp.first) {
        file >> tmp.second.first >> tmp.second.second;
        mp.insert({tmp.first,{tmp.second.first,tmp.second.second}});
    }
    //read from file
    UTILITY::setSellerRate(mp);
    file.close();
}

void FILES::write_SellerRate()
{
    ofstream file("SellerRate.txt");
    auto mp = UTILITY::getSellerRate();
    int cnt = mp.size();
    //write into file
    for(auto &i : mp) {
        --cnt;
        file << i.first << ' ' << i.second.first << ' ' << i.second.second;
        if(cnt) file << endl;
    }
    file.close();
}

void FILES::read_soldByCategories()
{
    ifstream file("soldByCategories.txt",ios::in);
    if(!file) return;

    int x;
    vector<int> v;
    //looping until the end of the file
    while(file >> x) {
        v.push_back(x);
    }
    //read from file
    UTILITY::setsoldByCategories(v);
    file.close();
}

void FILES::write_soldByCategories()
{
    ofstream file("soldByCategories.txt");
    auto v = UTILITY::getsoldByCategories();
    int cnt = v.size();
    //write into file
    for(auto &i : v) {
        --cnt;
        file << i;
        if(cnt) file << endl;
    }
    file.close();
}

void FILES::read_verification()
{
    ifstream file("verification.txt",ios::in);
    if(!file) return;

    pair<int,string> tmp;
    unordered_map<int,QString> mp;
    //looping until the end of the file
    while(file >> tmp.first) {
        file >> tmp.second;
        mp.insert({tmp.first,QString::fromStdString(tmp.second)});
    }
    //read from file
    UTILITY::setVerification(mp);
    file.close();
}

void FILES::write_verification()
{
    ofstream file("verification.txt");
    auto mp = UTILITY::getVerification();
    int cnt = mp.size();
    //write into file
    for(auto &i : mp) {
        --cnt;
        file << i.first << ' ' << i.second.toStdString();
        if(cnt) file << endl;
    }
    file.close();
}

void FILES::read_questions()
{
    ifstream file("questions.txt",ios::in);
    if(!file) return;

    pair<int,pair<string, string>> tmp;
    unordered_map<int,pair<QString, QString>> mp;
    //looping until the end of the file
    while(file >> tmp.first ) {
        file >> tmp.second.first >> tmp.second.second;
        string qu=tmp.second.first;
        string ans=tmp.second.second;
        for(int i=0;i<qu.size();i++){
            if(qu[i]=='%')
                qu[i]=' ';
        }

        for(int i=0;i<ans.size();i++){
            if(ans[i]=='%')
                ans[i]=' ';
        }
        mp.insert({tmp.first,{QString::fromStdString(qu),QString::fromStdString((ans))}});
    }
    //read from file
    UTILITY::setQuestions(mp);
    file.close();
}

void FILES::write_questions()
{
    ofstream file("questions.txt");
    auto mp = UTILITY::getQuestions();
    int cnt = mp.size();
    //write into file
    for(auto &i : mp) {
        --cnt;
        string qu=i.second.first.toStdString();
        string ans=i.second.second.toStdString();
        for(int i=0;i<qu.size();i++){
            if(qu[i]==' ')
                qu[i]='%';
        }

        for(int i=0;i<ans.size();i++){
            if(ans[i]==' ')
                ans[i]='%';
        }
        file << i.first << ' ' << qu << ' ' << ans;
        if(cnt) file << endl;
    }
    file.close();
}

void FILES::read_emailToID()
{
    ifstream file("emailToID.txt",ios::in);
    if(!file) return;

    pair<string,int> tmp;
    unordered_map<QString,int> mp;
    //looping until the end of the file
    while(file >> tmp.first) {
        file >> tmp.second;
        mp.insert({QString::fromStdString(tmp.first),tmp.second});
    }
    //read from file
    UTILITY::setEmailToID(mp);
    file.close();
}

void FILES::write_emailToID()
{
    ofstream file("emailToID.txt");
    auto mp = UTILITY::getEmailToID();
    int cnt = mp.size();
    //write into file
    for(auto &i : mp) {
        --cnt;
        file << i.first.toStdString() << ' ' << i.second;
        if(cnt) file << endl;
    }
    file.close();
}

void FILES::read_sortedBestSelling()
{
    ifstream file("sortedBestSelling.txt",ios::in);
    if(!file) return;
    //
    pair<int,int> tmp;
    set<pair<int,int>> st;
    //looping until the end of the file
    while(file >> tmp.first) {
        file >> tmp.second;
        st.insert(tmp);
    }
    //read from file
    UTILITY::setSortedBestSelling(st);
    file.close();
}

void FILES::write_sortedBestSelling()
{
    ofstream file("sortedBestSelling.txt");
    auto st = UTILITY::getSortedBestSelling();
    int cnt = st.size();
    //write into file
    for(auto &i : st) {
        --cnt;
        file << i.first << ' ' << i.second;
        if(cnt) file << endl;
    }
    file.close();
}

void FILES::read_all()
{
    read_customer();
    read_seller();
    read_products();
    read_SellerRate();
    read_soldByCategories();
    read_verification();
    read_questions();
    read_emailToID();
    read_sortedBestSelling();
}

void FILES::write_all()
{
    write_customer();
    write_seller();
    write_products();
    write_SellerRate();
    write_soldByCategories();
    write_verification();
    write_questions();
    write_emailToID();
    write_sortedBestSelling();
}


#include "mainwindow.h"
#include "cartcontainer.h"
#include "currentuser.h"
#include "customer.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QCompleter>
#include "files.h"
#include <QGraphicsView>
#include "product_page.h"
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    FILES::read_all();

    resize(1000,1000);
    ui->setupUi(this);

    // index 5 is the beggining of app
    ui->stackedWidget->setCurrentIndex(2);

    UTILITY::Init();
    setCategory();

    ui->comboBox_6->addItem("Highest Rating");
    ui->comboBox_6->addItem("Lowest Rating");
    ui->comboBox_6->addItem("Price: High to Low");
    ui->comboBox_6->addItem("Price: Low to High");
    ui->comboBox_6->addItem("Best Selling");



    ui->lineEdit_12->hide();
    ui->lineEdit_13->hide();
    ui->label_41->hide();

    ui->pushButton_4->setIcon(QIcon(":/new/prefix1/SearchIcon.png"));
    ui->pushButton_4->setIconSize(QSize(30,30));




    ui->pushButton_10->setIcon(QIcon(":/new/prefix1/logo"));
    ui->pushButton_10->setIconSize(QSize(150,120));


    ui->pushButton_11->setIcon(QIcon(":/new/prefix1/profilepic"));
    ui->pushButton_11->setIconSize(QSize(30,30));

    ui->pushButton_2->setIcon(QIcon(":/new/prefix1/assets/pencil.png"));
    ui->pushButton_2->setIconSize(QSize(30,30));

    ui->pushButton_13->setIcon(QIcon(":/new/prefix1/assets/pencil.png"));
    ui->pushButton_13->setIconSize(QSize(30,30));

    ui->pushButton_36->setIcon(QIcon(":/new/prefix1/assets/pencil.png"));
    ui->pushButton_36->setIconSize(QSize(30,30));

    connect(ui->widget, SIGNAL(back()), this, SLOT(ProductPageBack()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(PlaceOrder()));
    connect(ui->widget_2, SIGNAL(submited()), this, SLOT(ProductSubmited()));



    connect(ui->pushButton_12, SIGNAL(clicked()), this, SLOT(passIndexToCategory_0()));
    connect(ui->pushButton_14, SIGNAL(clicked()), this, SLOT(passIndexToCategory_1()));
    connect(ui->pushButton_15, SIGNAL(clicked()), this, SLOT(passIndexToCategory_2()));
    connect(ui->pushButton_16, SIGNAL(clicked()), this, SLOT(passIndexToCategory_3()));
    connect(ui->pushButton_28, SIGNAL(clicked()), this, SLOT(passIndexToCategory_4()));
    connect(ui->pushButton_29, SIGNAL(clicked()), this, SLOT(passIndexToCategory_5()));

    on_pushButton_7_clicked();
    SignUp();
    SignIn();
    SetTopCategory();
    SetCategoryPath();
    SetBestProduct();
    SetBestProductPath();
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    CurrentUser::LogOut();
    FILES::write_all();
    QMainWindow::closeEvent(event);
}

void MainWindow::passIndexToCategory_1()
{
    ui->comboBox_5->setCurrentIndex(CategoreyMap[1]);
    on_comboBox_5_currentIndexChanged(CategoreyMap[1]);
}

void MainWindow::passIndexToCategory_2()
{
    ui->comboBox_5->setCurrentIndex(CategoreyMap[2]);
    on_comboBox_5_currentIndexChanged(CategoreyMap[2]);
}

void MainWindow::passIndexToCategory_3()
{
    ui->comboBox_5->setCurrentIndex(CategoreyMap[3]);
    on_comboBox_5_currentIndexChanged(CategoreyMap[3]);
}

void MainWindow::passIndexToCategory_4()
{
    ui->comboBox_5->setCurrentIndex(CategoreyMap[4]);
    on_comboBox_5_currentIndexChanged(CategoreyMap[4]);
}

void MainWindow::passIndexToCategory_5()
{
    ui->comboBox_5->setCurrentIndex(CategoreyMap[5]);
    on_comboBox_5_currentIndexChanged(CategoreyMap[5]);
}

void MainWindow::passIndexToCategory_0()
{
    ui->comboBox_5->setCurrentIndex(CategoreyMap[0]);
    on_comboBox_5_currentIndexChanged(CategoreyMap[0]);
}


void MainWindow::SetTopCategory()
{
    BestCategory=UTILITY::TopCategories(6);
}

void MainWindow::SetCategoryPath()
{
    //  pb12->1
    //  pb14->2
    //  pb15->3
    //  pb16->4;
    //  pb28->5
    //  pb29->6
    //  pb30->1 (product)
    //  pb31->2 (product)
    //  pb32->3 (product)
    //  pb33->4 (product)
    //  pb34->5 (product)
    //  pb45->6 (product)


    for(auto itt:BestCategory)
    {
        if(itt==0)
        {
            BestCategoryPath[itt]=":/new/prefix1/assets/Furniture.jpg";
        }
        if(itt==1)
        {
            BestCategoryPath[itt]=":/new/prefix1/assets/Menwear.jpg";
        }
        if(itt==2)
        {
            BestCategoryPath[itt]=":/new/prefix1/assets/womenwear.jpeg";
        }
        if(itt==3)
        {
            BestCategoryPath[itt]=":/new/prefix1/assets/kidwear.jpeg";
        }
        if(itt==4)
        {
            BestCategoryPath[itt]=":/new/prefix1/assets/makeup.jpg";
        }
        if(itt==5)
        {
            BestCategoryPath[itt]=":/new/prefix1/assets/laptops.jpeg";
        }
        if(itt==6)
        {
            BestCategoryPath[itt]=":/new/prefix1/assets/videogames.jpeg";
        }
        if(itt==7)
        {
            BestCategoryPath[itt]=":/new/prefix1/assets/mobilephones.jpeg";
        }
        if(itt==8)
        {
            BestCategoryPath[itt]=":/new/prefix1/assets/tablets.jpeg";
        }
        if(itt==9)
        {
            BestCategoryPath[itt]=":/new/prefix1/assets/sports.jpeg";
        }
        if(itt==10)
        {
            BestCategoryPath[itt]=":/new/prefix1/assets/healthandpersonalcare.jpeg";
        }
        if(itt==11)
        {
            BestCategoryPath[itt]=":/new/prefix1/assets/petsupplies.jpeg";
        }
        if(itt==12)
        {
            BestCategoryPath[itt]=":/new/prefix1/assets/books.jpeg";
        }
    }

    int cnt=0;
    for(auto it:BestCategory)
    {
        if(cnt==0)
        {
            ui->pushButton_12->setIcon(QIcon(BestCategoryPath[it]));
            ui->pushButton_12->setIconSize(QSize(300, 300));
        }
        if(cnt==1)
        {
            ui->pushButton_14->setIcon(QIcon(BestCategoryPath[it]));
            ui->pushButton_14->setIconSize(QSize(200, 200));
        }
        if(cnt==2)
        {
            ui->pushButton_15->setIcon(QIcon(BestCategoryPath[it]));
            ui->pushButton_15->setIconSize(QSize(200, 200));
        }
        if(cnt==3)
        {
            ui->pushButton_16->setIcon(QIcon(BestCategoryPath[it]));
            ui->pushButton_16->setIconSize(QSize(200, 200));
        }
        if(cnt==4)
        {
            ui->pushButton_28->setIcon(QIcon(BestCategoryPath[it]));
            ui->pushButton_28->setIconSize(QSize(200, 200));
        }
        if(cnt==5)
        {
            ui->pushButton_29->setIcon(QIcon(BestCategoryPath[it]));
            ui->pushButton_29->setIconSize(QSize(100, 100));
        }
        CategoreyMap[cnt]=it;
        cnt++;
    }
}

MainWindow::~MainWindow()
{
    disconnect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(PlaceOrder()));
    disconnect(ui->widget, SIGNAL(back()), this, SLOT(ProductPageBack()));
    disconnect(ui->widget_2, SIGNAL(submited()), this, SLOT(ProductSubmited()));

    disconnect(ui->pushButton_12, SIGNAL(clicked()), this, SLOT(passIndexToCategory_0()));
    disconnect(ui->pushButton_14, SIGNAL(clicked()), this, SLOT(passIndexToCategory_1()));
    disconnect(ui->pushButton_15, SIGNAL(clicked()), this, SLOT(passIndexToCategory_2()));
    disconnect(ui->pushButton_16, SIGNAL(clicked()), this, SLOT(passIndexToCategory_3()));
    disconnect(ui->pushButton_28, SIGNAL(clicked()), this, SLOT(passIndexToCategory_4()));
    disconnect(ui->pushButton_29, SIGNAL(clicked()), this, SLOT(passIndexToCategory_5()));
    delete ui;
}

void MainWindow::search(bool find)
{
    QCompleter *c;
    QStringList list;
    if(ui->comboBox_6->isHidden()) ui->comboBox_6->show();
    if(container) {
        container->RemoveWidgets(ui->gridLayout_2);
        disconnect(container, SIGNAL(View()), this, SLOT(ViewProduct()));
        delete container;
        container = nullptr;
    }
    string s = ui->lineEdit->text().toStdString();
    for(auto &i: s) {
        if(i >= 'A' && i <= 'Z') {
            i += 32;
        }
    }

    vector<int> p = UTILITY::Search(s);
    vector<PRODUCT> v;
    for(auto i:p) {
        string s = UTILITY::GetProduct(i).getName().toStdString();
        list << QString::fromStdString(s);
        v.push_back(UTILITY::GetProduct(i));
    }
    c = new QCompleter(list);
    c->setCaseSensitivity(Qt::CaseInsensitive);
    curProducts = v;
    ui->lineEdit->setCompleter(c);
    if(find) {
        container = new CustomContainer(v , ui->gridLayout_2);
        connect(container, SIGNAL(View()), this, SLOT(ViewProduct()));
    }
}

void MainWindow::SetBestProduct()
{
    BestProduct=UTILITY::BestSelling(6);
}


void MainWindow::SetBestProductPath()
{
    //  pb30->1 (product)
    //  pb31->2 (product)
    //  pb32->3 (product)
    //  pb33->4 (product)
    //  pb34->5 (product)
    //  pb35->6 (product)
    if(BestProduct.size()) {
        ui->pushButton_30->show();
        ui->pushButton_30->setIcon(QIcon(BestProduct[0].getPath()));
        ui->pushButton_30->setIconSize(QSize(200, 200));
        ProductMap[0]=BestProduct[0].getID();
    }
    else ui->pushButton_30->hide();

    if(BestProduct.size() >= 2) {
        ui->pushButton_31->show();
        ui->pushButton_31->setIcon(QIcon(BestProduct[1].getPath()));
        ui->pushButton_31->setIconSize(QSize(200, 200));
        ProductMap[1]=BestProduct[1].getID();
    }
    else ui->pushButton_31->hide();

    if(BestProduct.size() >= 3) {
        ui->pushButton_32->show();
        ui->pushButton_32->setIcon(QIcon(BestProduct[2].getPath()));
        ui->pushButton_32->setIconSize(QSize(200, 200));
        ProductMap[2]=BestProduct[2].getID();
    }
    else ui->pushButton_32->hide();
    if(BestProduct.size() >= 4) {
        ui->pushButton_33->show();
        ui->pushButton_33->setIcon(QIcon(BestProduct[3].getPath()));
        ui->pushButton_33->setIconSize(QSize(200, 200));
        ProductMap[3]=BestProduct[3].getID();
    }
    else ui->pushButton_33->hide();
    if(BestProduct.size() >= 5) {
        ui->pushButton_34->show();
        ui->pushButton_34->setIcon(QIcon(BestProduct[4].getPath()));
        ui->pushButton_34->setIconSize(QSize(200, 200));
        ProductMap[4]=BestProduct[4].getID();
    }
    else ui->pushButton_34->hide();
    if(BestProduct.size() >= 6) {
        ui->pushButton_35->show();
        ui->pushButton_35->setIcon(QIcon(BestProduct[5].getPath()));
        ui->pushButton_35->setIconSize(QSize(200, 200));
        ProductMap[5]=BestProduct[5].getID();
    }
    else ui->pushButton_35->hide();
}

void MainWindow::ClearSignIn() {
    ui->label_32->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_8->clear();
}

void MainWindow::SetProfile()
{
    /*
    label_33 ---> username
    label_34 ---> email
    label_37 ---> phone_num
    label_35 ---> address
    label_36 ---> BD
    label_38 ---> user_type
    */

    if(type == '1') {
        CUSTOMER c = UserData::GetCustomer(userId);
        QDate bD(c.getBirthYear(), c.getBirthMonth(), c.getBirthDay());
        ui->label_33->setText(c.GetName());
        ui->label_34->setText(c.GetEmail());
        ui->label_37->setText(c.getPhone_num());
        ui->label_35->setText(c.getAddress());
        ui->label_36->setText(bD.toString("dd/MM/yy"));
        ui->label_38->setText("Customer");
    }
    else {
        SELLER s = UserData::GetSeller(userId);
        QDate bD(s.getBirthYear(), s.getBirthMonth(), s.getBirthDay());
        ui->label_33->setText(s.GetName());
        ui->label_34->setText(s.GetEmail());
        ui->label_37->setText(s.getPhone_num());
        ui->label_35->setText(s.getAddress());
        ui->label_36->setText(bD.toString("dd/MM/yy"));
        ui->label_38->setText("Seller");
    }
}

void MainWindow::calculate()
{
    float total = 0;
    total = (ui->label_61->text().toFloat() * (1 - (ui->label_63->text().toFloat() / 100))) + 20;
    ui->label_66->setText(QString::number(total));
}

void MainWindow::SignIn() {
    ui->pushButton_25->setIcon(QIcon(":/new/prefix1/assets/211686_back_arrow_icon.png"));
    ui->pushButton_26->setIcon(QIcon(":/new/prefix1/assets/211686_back_arrow_icon.png"));
    ui->pushButton_27->setIcon(QIcon(":/new/prefix1/assets/211686_back_arrow_icon.png"));
    ui->label_10->setPixmap(QPixmap(":/new/prefix1/login.png").scaledToWidth(600));
    ui->lineEdit_9->setEchoMode(QLineEdit::Password);
    ui->lineEdit_8->setEchoMode(QLineEdit::Password);
    ui->lineEdit_10->setEchoMode(QLineEdit::Password);
}

void MainWindow::setCategory()
{
    ui->comboBox_5->addItem("Furniture");
    ui->comboBox_5->addItem("Men's wear");
    ui->comboBox_5->addItem("Women's wear");
    ui->comboBox_5->addItem("Kid's wear");
    ui->comboBox_5->addItem("Makeup");
    ui->comboBox_5->addItem("Laptops");
    ui->comboBox_5->addItem("Video games");
    ui->comboBox_5->addItem("Mobile phones");
    ui->comboBox_5->addItem("Tablets");
    ui->comboBox_5->addItem("Sports");
    ui->comboBox_5->addItem("Health and personal care");
    ui->comboBox_5->addItem("Pet supplies");
    ui->comboBox_5->addItem("Books");


}


void MainWindow::SignUp() {
    QDate x;
    for (int i = x.currentDate().year(); i < x.currentDate().year() + 21; ++i) {
        ui->comboBox_4->addItem(QString::number(i));
    }
    for (int i = 1; i <= 12; ++i) {
        ui->comboBox_3->addItem(QString::number(i));
    }
    ui->lineEdit_33->setEchoMode(QLineEdit::Password);
    ui->lineEdit_34->setEchoMode(QLineEdit::Password);

    ui->pushButton_20->setIcon(QIcon(":/new/prefix1/assets/211686_back_arrow_icon.png"));
    ui->pushButton_5->setIcon(QIcon(":/new/prefix1/assets/calender.png"));
    ui->pushButton_5->setIconSize(QSize(50,50));

    ui->comboBox_2->addItem("@gmail.com");
    ui->comboBox_2->addItem("@yahoo.com");
    ui->comboBox_2->addItem("@hotmail.com");
    ui->comboBox_2->addItem("@outlook.com");
    ui->comboBox_2->addItem("@icloud.com");

    ui->comboBox->addItem("What was the name of your elementry school?");
    ui->comboBox->addItem("Who is your favorite football player?");
    ui->comboBox->addItem("what is your pet's name?");
    ui->comboBox->addItem("What is the middle name of your youngest child?");

}



void MainWindow::on_pushButton_7_clicked()
{
    ui->widget->Clear();
    ui->widget_2->Clear();
    ui->comboBox_6->hide();
    ResetProfile();
    ui->comboBox_5->setCurrentIndex(-1);
    if(container) {
        container->RemoveWidgets(ui->gridLayout_2);
        disconnect(container, SIGNAL(View()), this, SLOT(ViewProduct()));
        delete container;
        container = nullptr;
    }

    container = new CustomContainer(UTILITY::BestSelling(UTILITY::GetNumberOfProducts()) , ui->gridLayout_2);
    connect(container, SIGNAL(View()), this, SLOT(ViewProduct()));
    ui->stackedWidget_2->setCurrentIndex(1);
}


void MainWindow::on_pushButton_6_clicked()
{
    ui->widget->Clear();
    if(ui->comboBox_6->isHidden()) ui->comboBox_6->show();
    ResetProfile();
    ui->comboBox_5->setCurrentIndex(-1);
    if(type == '1') {
        if(container) {
            container->RemoveWidgets(ui->gridLayout_2);
            disconnect(container, SIGNAL(View()), this, SLOT(ViewProduct()));
            delete container;
            container = nullptr;
        }

        vector<PRODUCT> history;
        for(auto i : CurrentUser::GetCustomer()->Get_shopping_history()) {
            if(i.second) history.push_back(UTILITY::GetProduct(i.first));
        }
        curProducts = history;

        container = new CustomContainer(history , ui->gridLayout_2);
        connect(container, SIGNAL(View()), this, SLOT(ViewProduct()));
    }
    ui->stackedWidget_2->setCurrentIndex(1);
}


void MainWindow::on_pushButton_10_clicked()
{
    ui->widget->Clear();
    ui->widget_2->Clear();
    ResetProfile();
    ui->comboBox_5->setCurrentIndex(-1);
    ui->stackedWidget_2->setCurrentIndex(0);
    SetTopCategory();
    SetCategoryPath();
    SetBestProduct();
    SetBestProductPath();
}


void MainWindow::on_pushButton_11_clicked()
{
    ui->widget->Clear();
    ui->widget_2->Clear();
    ResetProfile();
    if(type == '1') {
        ui->label_56->hide();
        ui->label_70->hide();
    }
    else if(type == '2') {
        ui->label_56->show();
        ui->label_70->show();
        ui->label_70->setText(QString::number(UTILITY::GetSellerRating(userId)));
    }
    ui->comboBox_5->setCurrentIndex(-1);
    ui->stackedWidget_2->setCurrentIndex(3);
}


void MainWindow::on_pushButton_18_clicked()
{
    bool valid = 1;
    for(QChar i : ui->lineEdit_2->text()) {
        if(i == ' ') {
            valid = 0;
            break;
        }
    }

    if(ui->lineEdit_2->text().isEmpty()) valid = 0;

    if(!valid) {
        ui->label_32->setText("Either email or password is incorrect");
        return;
    }

    int ID = UTILITY::GetUserID(ui->lineEdit_2->text());
    if(!ID || !UTILITY::VerifyPassword(ID, ui->lineEdit_8->text())) {
        ui->label_32->setText("Either email or password is incorrect");
    }
    else {
        userId = ID;
        type = to_string(userId)[0];
        SetProfile();
        ChangeUI();
        ui->stackedWidget_2->setCurrentIndex(0);
        ui->stackedWidget->setCurrentIndex(0);
        ClearSignIn();
        CurrentUser::SetUser(userId, type);

    }
}


void MainWindow::on_pushButton_19_clicked()
{
    ClearSignIn();
    ui->stackedWidget->setCurrentIndex(1);
}

// when click in logout
void MainWindow::on_pushButton_clicked()
{
    ui->widget->Clear();
    ui->widget_2->Clear();
    ui->lineEdit->clear();
    ResetProfile();
    ui->comboBox_5->setCurrentIndex(-1);
    CurrentUser::LogOut();
    userId = 0;

    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_pushButton_17_clicked()
{
    /*
    LineEdit_31; ------> username
    LineEdit_32 ;------> email
    comboBox_2 ------> email
    LineEdit_33; ------> password
    LineEdit_34 ;------> confirm_password
    LineEdit_35 ;------> phone_num
    LineEdit_36 ;------> address
    LineEdit_4 ;------> Birth_date
    LineEdit_5 ;------> credit_card
    comboBox_3 ;------> expiry(month)
    comboBox_4 ;------> expiry(year)
    LineEdit_6 ;------> csv
    comboBox ------> questions
    LineEdit_37 ------> answers
    label_11; ------> username
    label_12; ------> email
    label_13; ------> password
    label_14; ------> confirm_password
    label_15; ------> phone_num
    label_16; ------> address
    label_17; ------> Birth_Date
    label_18; ------> credit_card
    label_19; ------> expiry
    label_20; ------> csv
    label_21; ------> questions
    label_22; ------> answers
    label_24; ------> Type
    radioButton -----> Customer
    radioButton_2 -----> Seller
    */
    int valid = 0;

    // Username
    QString username = ui->lineEdit_31->text();
    if(!username.size()) valid |= 1, ui->label_11->setText("This field is required");
    for(auto i : username) {
        if(i == ' ') {
            ui->label_11->setText("Must not contain spaces");
            valid |= 1;
            break;
        }
    }
    if(!(valid & 1)) ui->label_11->clear();

    // Email
    QString email = ui->lineEdit_32->text();
    if(!email.size()) valid |= (1 << 1) , ui->label_12->setText("This field is required");
    for(auto i : email) {
        if(i == ' ') {
            valid |= (1 << 1);
            ui->label_12->setText("Must not contain spaces");
            break;
        }
    }
    if(ui->comboBox_2->currentIndex() == -1) {
        valid |= (1 << 1);
        ui->label_12->setText("This field is required");
    }
    else if(!(valid & (1 << 1)))
    {
        email += ui->comboBox_2->currentText();
        ui->label_12->clear();
    }

    //Password
    QString password = ui->lineEdit_33->text();
    if(password.size() < 8) valid |= (1 << 2) , ui->label_13->setText("Password must contain at least 8 charaters");
    for(auto i: password) {
        if(i == ' ') {
            valid |= (1 << 2), ui->label_13->setText("Password must not contain spaces");
            break;
        }
    }
    if(!(valid & (1 << 2))) ui->label_13->clear();

    //confirm pass
    if(password != ui->lineEdit_34->text()) valid |= (1 << 3),  ui->label_14->setText("Password does not match");
    else if(!(valid & (1 << 3))) ui->label_14->clear();

    //phone number
    QString phoneNum = ui->lineEdit_35->text();
    if(phoneNum.size() < 11) valid |= (1 << 4),  ui->label_15->setText("Invalid phone number");

    for(auto i: phoneNum) {
        if(i < '0' || i > '9') {
            valid |= (1 << 4), ui->label_15->setText("Invalid phone number");
            break;
        }
    }
    if(!(valid & (1 << 4))) ui->label_15->clear();

    //address
    QString address = ui->lineEdit_36->text();
    if(!address.size()) valid |= (1 << 5),  ui->label_16->setText("This field is required");

    if(!(valid & (1 << 5))) ui->label_16->clear();

    //birth date

    QString bDate = ui->lineEdit_4->text();
    int BirthDay,BirthMonthh,BirthYearr;

    if(!bDate.size()) valid |= (1 << 6),  ui->label_17->setText("This field is required");
    else if(!(valid & (1 << 6)))
    {
        BirthDay = stoi(bDate.toStdString().substr(0,2));
        BirthMonthh = stoi(bDate.toStdString().substr(3,5));
        BirthYearr = stoi(bDate.toStdString().substr(6,10));
        ui->label_17->clear();
    }

    //credit card
    CreditCard cc;
    QString creditCard = ui->lineEdit_5->text();
    if(creditCard.size() < 16) valid |= (1 << 7),  ui->label_18->setText("Invalid credit card number");
    for(auto i: creditCard) {
        if(i < '0' || i > '9') {
            valid |= (1 << 7), ui->label_18->setText("Invalid credit card number");
            break;
        }
    }
    if(!(valid & (1 << 7)))
    {
        cc.setNumber(creditCard.toLongLong());
        ui->label_18->clear();
    }

    //expiry
    QDate currentDate;
    QString month = ui->comboBox_3->currentText();
    QString year = ui->comboBox_4->currentText();
    if(!year.size() || !month.size()) valid |= (1 << 8),  ui->label_19->setText("This field is required");
    else if(year.toInt() == currentDate.currentDate().year() && month.toInt() <= currentDate.currentDate().month())
        valid |= (1 << 8),  ui->label_19->setText("Invalid expiry date");

    else if(!(valid & (1 << 8)))
    {
        cc.setExpiry_month(month.toInt());
        cc.setExpiry_year(year.toInt());
        ui->label_19->clear();
    }

    //csv
    QString csv = ui->lineEdit_6->text();
    if(csv.size() < 3) valid |= (1 << 9),  ui->label_20->setText("Invalid CSV");
    for(auto i: csv) {
        if(i < '0' || i > '9') {
            valid |= (1 << 9), ui->label_20->setText("Invalid CSV");
            break;
        }
    }
    if(!(valid & (1 << 9)))
    {
        cc.setCsv(csv.toInt());
        ui->label_20->clear();
    }

    //question
    if(ui->comboBox->currentIndex() == -1) valid |= (1 << 10),  ui->label_21->setText("This field is required");
    QString question = ui->comboBox->currentText();

    if(!(valid & (1 << 10))) ui->label_21->clear();

    //answers
    QString answer = ui->lineEdit_37->text();
    if(!answer.size()) valid |= (1 << 11),  ui->label_22->setText("This field is required");

    if(!(valid & (1 << 11))) ui->label_22->clear();

    //Type
    if(ui->radioButton->isChecked()) type = 1;
    else if(ui->radioButton_2->isChecked()) type = 2;
    else if(!ui->radioButton->isChecked() && !ui->radioButton_2->isChecked()) valid |= (1 << 12),  ui->label_24->setText("This field is required");
    if(!(valid & (1 << 12))) ui->label_24->clear();

    if(!valid) {
        bool notUsed = UTILITY::AddAccount(email,  password,  username,  address, cc , phoneNum, type,  question,  answer, BirthDay, BirthMonthh, BirthYearr);
        if(!notUsed)
        {
            ui->label_12->setText("This email already exists");
            goto end;
        }
        userId = UTILITY::GetUserID(email);
        type = to_string(userId)[0];
        SetProfile();
        ui->stackedWidget->setCurrentIndex(0);
        ui->stackedWidget_2->setCurrentIndex(3);
        ChangeUI();
        ClearSignUp();
        CurrentUser::SetUser(userId, type);
        if(type == '1' && !ui->label_56->isHidden()) {
            ui->label_56->hide();
            ui->label_70->hide();
        }
        else if(type == '2' && ui->label_56->isHidden()) {
            ui->label_56->show();
            ui->label_70->show();
            ui->label_70->setText(QString::number(UTILITY::GetSellerRating(userId)));
        }

    }
    end:;
    ui->scrollArea->verticalScrollBar()->setValue(0);

}

void MainWindow::ClearSignUp() {


    ui->comboBox_2->setCurrentIndex(-1);
    ui->comboBox_3->setCurrentIndex(-1);
    ui->comboBox_4->setCurrentIndex(-1);
    ui->comboBox->setCurrentIndex(-1);

    ui->lineEdit_31->clear();
    ui->lineEdit_32->clear();
    ui->lineEdit_33->clear();
    ui->lineEdit_34->clear();
    ui->lineEdit_35->clear();
    ui->lineEdit_36->clear();
    ui->lineEdit_37->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
    ui->lineEdit_6->clear();

    ui->label_11->clear();
    ui->label_12->clear();
    ui->label_13->clear();
    ui->label_14->clear();
    ui->label_15->clear();
    ui->label_16->clear();
    ui->label_17->clear();
    ui->label_18->clear();
    ui->label_19->clear();
    ui->label_20->clear();
    ui->label_21->clear();
    ui->label_22->clear();
    ui->label_24->clear();

    ui->radioButton->setAutoExclusive(0);
    ui->radioButton_2->setAutoExclusive(0);
    ui->radioButton->setChecked(0);
    ui->radioButton_2->setChecked(0);
    ui->radioButton->setAutoExclusive(1);
    ui->radioButton_2->setAutoExclusive(1);
}


void MainWindow::on_pushButton_5_clicked()
{
    Dialog d;
    d.setModal(1);
    //d.show();
    d.exec();
    ui->lineEdit_4->setText(d.ret->text());
}




void MainWindow::on_pushButton_20_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    ClearSignUp();
}




void MainWindow::on_pushButton_21_clicked()
{
    ClearSignIn();
    ClearPassReset();
    ui->stackedWidget_3->setCurrentIndex(2);
    ui->stackedWidget->setCurrentIndex(3);
}


void MainWindow::on_pushButton_22_clicked()
{
    int ID = UTILITY::GetUserID(ui->lineEdit_3->text());
    if(ID) {
        type = to_string(ID)[0];
        QString question = UTILITY::GetQuestion(ID);
        ui->label_9->setText(question);
        ui->stackedWidget_3->setCurrentIndex(0);
        ui->label_28->clear();
    }
    else ui->label_28->setText("Email does not exist");
}


void MainWindow::on_pushButton_23_clicked()
{
    QString ans = ui->lineEdit_7->text();

    if(UTILITY::VerifyAns(UTILITY::GetUserID(ui->lineEdit_3->text()), ans)) {
        ui->stackedWidget_3->setCurrentIndex(1);
        ui->label_29->clear();
    }
    else ui->label_29->setText("The answer is invalid");
}

void MainWindow::ClearPassReset()
{
    ui->lineEdit_3->clear();
    ui->lineEdit_7->clear();
    ui->lineEdit_9->clear();
    ui->lineEdit_10->clear();
    ui->label_28->clear();
    ui->label_31->clear();
    ui->label_30->clear();
    ui->label_29->clear();
}


void MainWindow::on_pushButton_24_clicked()
{
    bool valid = 1;
    QString password = ui->lineEdit_9->text();
    if(password.size() < 8) valid = 0, ui->label_30->setText("Password must contain at least 8 charaters");
    for(auto i: password) {
        if(i == ' ') {
            valid = 0;
            ui->label_30->setText("Password must not contain spaces");
            break;
        }
    }
    if(valid) ui->label_30->clear();

    //confirm pass
    if(password != ui->lineEdit_10->text()) valid &= 0, ui->label_31->setText("Password does not match");
    else ui->label_31->clear();

    if(valid) {
        if(type == '1')
            CurrentUser::GetCustomer()->setPassword(password);
        else
            CurrentUser::GetSeller()->setPassword(password);
        UTILITY::ModifyPassword(userId? userId : UTILITY::GetUserID(ui->lineEdit_3->text()), password);
        ui->stackedWidget->setCurrentIndex((userId? 0 : 2));
        ClearPassReset();
    }
}


void MainWindow::on_pushButton_27_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    ClearPassReset();
}


void MainWindow::on_pushButton_25_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(2);
    ui->label_29->clear();
    ui->lineEdit_7->clear();
}


void MainWindow::on_pushButton_26_clicked()
{
    ui->label_30->clear();
    ui->label_31->clear();
    ui->lineEdit_9->clear();
    ui->lineEdit_10->clear();
    if(!userId)
        ui->stackedWidget_3->setCurrentIndex(0);
    else ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pushButton_2_clicked()
{
    ResetProfile();
    ui->stackedWidget->setCurrentIndex(3);
    ui->stackedWidget_3->setCurrentIndex(1);
}




void MainWindow::on_pushButton_9_clicked()
{
    ui->widget->Clear();
    ui->widget_2->Clear();
    ResetProfile();
    ui->comboBox_5->setCurrentIndex(-1);
    if(type == '1')
    {
        if(cartC) {
            ui->verticalLayout_28->removeWidget(cartC);
            disconnect(cartC, SIGNAL(recalculate()), this, SLOT(ChangePrice()));
            delete cartC;
        }
        cartC = new CartContainer(ui->verticalLayout_28);
        ui->verticalLayout_28->addWidget(cartC);
        connect(cartC, SIGNAL(recalculate()), this, SLOT(ChangePrice()));
        ui->stackedWidget_2->setCurrentIndex(2);
        ChangePrice();
        ui->radioButton_4->setChecked(1);
        ui->label_63->setText("0");
    }
    else
        ui->stackedWidget_2->setCurrentIndex(6);
}


void MainWindow::on_comboBox_5_currentIndexChanged(int index)
{
    ui->widget->Clear();
    if(ui->comboBox_6->isHidden() && ~ui->comboBox_5->currentIndex()) ui->comboBox_6->show();
    if(container) {
        container->RemoveWidgets(ui->gridLayout_2);
        disconnect(container, SIGNAL(View()), this, SLOT(ViewProduct()));
        delete container;
        container = nullptr;
    }
    curProducts = UTILITY::GetCatogeryProducts(index);
    container = new CustomContainer(curProducts, ui->gridLayout_2);
    connect(container, SIGNAL(View()), this, SLOT(ViewProduct()));
    ui->stackedWidget_2->setCurrentIndex(1);
}

void MainWindow::ChangeUI()
{

    if(type == '2') {
        ui->pushButton_3->setText("My Products");
        ui->pushButton_6->hide();
        ui->pushButton_9->setIcon(QIcon(":/new/prefix1/assets/pngwing.com.png"));
        ui->pushButton_9->setIconSize(QSize(30,30));
    }
    else{
        ui->pushButton_3->setText("Wishlist");
        ui->pushButton_6->show();
        ui->pushButton_9->setIcon(QIcon(":/new/prefix1/cart.png"));
        ui->pushButton_9->setIconSize(QSize(30,30)); 
    }
    CurrentUser::SetUser(userId, type);
}


void MainWindow::on_pushButton_3_clicked()
{
    ui->widget->Clear();
    ui->widget_2->Clear();
    if(ui->comboBox_6->isHidden()) ui->comboBox_6->show();
    ResetProfile();
    ui->comboBox_5->setCurrentIndex(-1);
    if(container) {
        container->RemoveWidgets(ui->gridLayout_2);
        disconnect(container, SIGNAL(View()), this, SLOT(ViewProduct()));
        delete container;
        container = nullptr;
    }

    if(type == '1') {
        vector<PRODUCT> wishlist;
        for(auto i : CurrentUser::GetCustomer()->Get_wishlist()) {
            if(i.second) wishlist.push_back(UTILITY::GetProduct(i.first));
        }
        curProducts = wishlist;

        container = new CustomContainer(wishlist , ui->gridLayout_2);
        connect(container, SIGNAL(View()), this, SLOT(ViewProduct()));

    }
    else {
        vector<PRODUCT> history;
        for(auto i : CurrentUser::GetSeller()->getProducts_IDs()) {
            history.push_back(UTILITY::GetProduct(i));
        }
        curProducts = history;

        container = new CustomContainer(history , ui->gridLayout_2);
        connect(container, SIGNAL(View()), this, SLOT(ViewProduct()));
    }
    ui->stackedWidget_2->setCurrentIndex(1);
}


void MainWindow::on_pushButton_4_clicked()
{
    if(ui->lineEdit->text().size()) {
        ui->widget->Clear();
        ui->widget_2->Clear();
        ResetProfile();
        search(1);
        ui->comboBox_5->setCurrentIndex(-1);
        ui->stackedWidget_2->setCurrentIndex(1);
    }
}

void MainWindow::ChangePrice()
{
    CART cart = CurrentUser::GetCustomer()->getCart();
    ui->label_61->setText(QString::number(cart.TotalPrice()));
    calculate();
}


void MainWindow::on_lineEdit_11_returnPressed()
{
    bool valid = 1;
    for(auto i: ui->lineEdit_11->text()) {
        if(i < '0' || i > '9') {
            valid = 0;
            break;
        }
    }
    if(!CurrentUser::GetCustomer()->Promo_isUsed(ui->lineEdit_11->text().toInt()) && valid) {
        ui->label_63->setText(QString::number(UTILITY::CheckPromo(ui->lineEdit_11->text().toInt()) * 100));
        calculate();
        ui->lineEdit_11->clear();
    }

}

void MainWindow::PlaceOrder()
{
    CurrentUser::GetCustomer()->Checkout();
    SetTopCategory();
    SetCategoryPath();
    ui->stackedWidget_2->setCurrentIndex(0);
}

void MainWindow::ViewProduct()
{
    ui->widget->setProduct(-1);
    ui->stackedWidget_2->setCurrentIndex(5);
}

void MainWindow::ProductPageBack()
{

    ui->widget->Clear();
    ui->stackedWidget_2->setCurrentIndex(1);

}

void MainWindow::ProductSubmited()
{
    if(container) {
        container->RemoveWidgets(ui->gridLayout_2);
        disconnect(container, SIGNAL(View()), this, SLOT(ViewProduct()));
        delete container;
        container = nullptr;
    }
    vector<PRODUCT> history;
    for(auto i : CurrentUser::GetSeller()->getProducts_IDs()) {
        history.push_back(UTILITY::GetProduct(i));
    }
    curProducts = history;

    container = new CustomContainer(history , ui->gridLayout_2);
    connect(container, SIGNAL(View()), this, SLOT(ViewProduct()));
    ui->stackedWidget_2->setCurrentIndex(1);
}


void MainWindow::on_pushButton_13_clicked()
{
    ui->lineEdit_12->setMaxLength(32);
    ui->label_35->hide();
    ui->pushButton_13->hide();
    ui->lineEdit_12->setText(ui->label_35->text());
    ui->lineEdit_12->show();
    ui->lineEdit_12->setFocus();
    ui->lineEdit_12->selectAll();
}


void MainWindow::on_lineEdit_12_returnPressed()
{
    if(ui->lineEdit_12->text().size()) {
        if(type == '1') {
            CurrentUser::GetCustomer()->setAddress(ui->lineEdit_12->text());
        }
        else CurrentUser::GetSeller()->setAddress(ui->lineEdit_12->text());
        ui->label_35->setText(ui->lineEdit_12->text());
        ui->lineEdit_12->clear();
    }

    ui->label_35->show();
    ui->pushButton_13->show();
    ui->lineEdit_12->hide();
}


void MainWindow::on_lineEdit_13_returnPressed()
{
    bool valid = 1;
    for(auto i : ui->lineEdit_13->text()) {
        if(i < '0' || i > '9')
            valid = 0;
    }


    if(ui->lineEdit_13->text().size() == 11 && valid) {
        if(type == '1') {
            CurrentUser::GetCustomer()->setPhone_num(ui->lineEdit_13->text());
        }
        else CurrentUser::GetSeller()->setPhone_num(ui->lineEdit_13->text());
        ui->label_37->setText(ui->lineEdit_13->text());
        ui->lineEdit_13->clear();
        ui->label_37->show();
        ui->pushButton_36->show();
        ui->lineEdit_13->hide();
        if(!ui->label_41->isHidden())
            ui->label_41->hide();
    }
    else {
        if(ui->label_41->isHidden())
            ui->label_41->show();
        ui->label_41->setText("Invalid phone number");
    }


}


void MainWindow::on_pushButton_36_clicked()
{
    ui->lineEdit_13->setMaxLength(11);
    ui->label_37->hide();
    ui->pushButton_36->hide();
    ui->lineEdit_13->setText(ui->label_37->text());
    ui->lineEdit_13->show();
    ui->lineEdit_13->setFocus();
    ui->lineEdit_13->selectAll();
}

void MainWindow::ResetProfile()
{
    if(ui->lineEdit_12->text().size()) {
        ui->lineEdit_12->clear();
        ui->label_35->show();
        ui->pushButton_13->show();
        ui->lineEdit_12->hide();
    }
    if(ui->lineEdit_13->text().size()) {
        ui->lineEdit_13->clear();
        ui->label_37->show();
        ui->label_41->hide();
        ui->pushButton_36->show();
        ui->lineEdit_13->hide();
    }
}


void MainWindow::on_comboBox_5_activated(int index)
{
    ResetProfile();
    ui->widget_2->Clear();
}


void MainWindow::on_lineEdit_returnPressed()
{
    on_pushButton_4_clicked();
}


void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    search(0);
}


void MainWindow::on_comboBox_6_currentIndexChanged(int index)
{
    if(container) {
        container->RemoveWidgets(ui->gridLayout_2);
        disconnect(container, SIGNAL(View()), this, SLOT(ViewProduct()));
        delete container;
        container = nullptr;
    }

    UTILITY::SortProducts(curProducts, (int)ui->comboBox_6->currentIndex()/2);
    if(ui->comboBox_6->currentIndex()%2) {
        reverse(curProducts.begin(), curProducts.end());
    }
    container = new CustomContainer(curProducts , ui->gridLayout_2);
    connect(container, SIGNAL(View()), this, SLOT(ViewProduct()));
}



void MainWindow::on_pushButton_30_clicked()
{
    ui->widget->setProduct(ProductMap[0]);
    ui->stackedWidget_2->setCurrentIndex(5);
}


void MainWindow::on_pushButton_31_clicked()
{
    ui->widget->setProduct(ProductMap[1]);
    ui->stackedWidget_2->setCurrentIndex(5);
}


void MainWindow::on_pushButton_32_clicked()
{
    ui->widget->setProduct(ProductMap[2]);
    ui->stackedWidget_2->setCurrentIndex(5);
}


void MainWindow::on_pushButton_33_clicked()
{
    ui->widget->setProduct(ProductMap[3]);
    ui->stackedWidget_2->setCurrentIndex(5);
}


void MainWindow::on_pushButton_34_clicked()
{
    ui->widget->setProduct(ProductMap[4]);
    ui->stackedWidget_2->setCurrentIndex(5);
}


void MainWindow::on_pushButton_35_clicked()
{
    ui->widget->setProduct(ProductMap[5]);
    ui->stackedWidget_2->setCurrentIndex(5);
}


#include "product_page.h"
#include "ui_product_page.h"
#include "utility.h"
#include "product.h"

product_page::product_page(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::product_page)
{
    ui->setupUi(this);
    /*
    label ---> pic path 1
    label_4 ---> price 1
    label_2 ---> name 1
    label_5 ---> rate 1
    label_12 ---> quantity 1
    label_3 ---> description 1
    label_9 ---> textPrice 1
    label_7 ---> textName 1
    label_10 ---> textRate 1
    pushButton ---> addToCart
    pushButton_2 ---> addToCart
    label_8 ---> textDescription 1
    pushButton_4 ---> backButton
    lineEdit_5 ---> comment
    label_6 ---> commenter
    label_11 ---> ratePicture
    label-14 ---> sellerIDtext
    label_13 ---> seller
    pushButton_103 -> 1 star
    pushbutton_6 -> 2 star
    pushbutton_7 -> 3 star
    pushbutton_5 -> 4 star
    pushbutton_8 -> 5 star
    push14 -> 1 star
    push10 -> 2 star
    push11 -> 3 star
    push12 -> 4 star
    push13 -> 5 star
     */

    //vector<pair<QString,QString>> s;




}

void product_page::setProduct(int idd)
{
    if(~idd)
    {
        product = &UTILITY::GetProduct(idd);
    }
    else
    {
        product = &UTILITY::GetProduct(id);
    }

    ui->label_100->setPixmap(QPixmap(product->getPath()).scaled(200, 200));
    ui->label_109->setText(QString::number(product->getPrice()));
    ui->label_109->setWordWrap(true);
    ui->label_107->setText(product->getName());
    ui->label_107->setWordWrap(true);
    ui->label_110->setText(QString::number(product->getRating()));
    ui->label_110->setWordWrap(true);
    ui->label_108->setText(product->getdescription());
    ui->label_108->setWordWrap(true);
    ui->label_114->setText(UserData::GetSeller(product->getSeller_ID()).GetName());
    ui->label_114->setWordWrap(true);

    int stars = round(UTILITY::GetSellerRating(product->getSeller_ID()));
    ui->label_151->setText(QString::number(stars));

    //For seller buttons stars & back
    ui->pushButton_103->setIcon(QIcon(":/new/prefix1/assets/star_off.png")); //1 star
    ui->pushButton_106->setIcon(QIcon(":/new/prefix1/assets/star_off.png")); //2 star
    ui->pushButton_107->setIcon(QIcon(":/new/prefix1/assets/star_off.png")); //3 star
    ui->pushButton_105->setIcon(QIcon(":/new/prefix1/assets/star_off.png")); //4 star
    ui->pushButton_108->setIcon(QIcon(":/new/prefix1/assets/star_off.png")); //5 star

    //Customer rating stars
    ui->pushButton_114->setIcon(QIcon(":/new/prefix1/assets/star_off.png")); //1 star
    ui->pushButton_110->setIcon(QIcon(":/new/prefix1/assets/star_off.png")); //2 star
    ui->pushButton_111->setIcon(QIcon(":/new/prefix1/assets/star_off.png")); //3 star
    ui->pushButton_112->setIcon(QIcon(":/new/prefix1/assets/star_off.png")); //4 star
    ui->pushButton_113->setIcon(QIcon(":/new/prefix1/assets/star_off.png")); //5 star
    ui->pushButton_104->setIcon(QIcon(":/new/prefix1/assets/211686_back_arrow_icon.png")); //back button

    setCustomer();
    pre();
    preSeller();


    int checkWishlist = curCustomer->checkWishlist(product->getID());
    if(checkWishlist)
    {
        ui->pushButton_102->setText("Remove from wishlist");
    }
    else
    {
        ui->pushButton_102->setText("Add to wishlist");
    }
    comments = new CommentContainer(product->getComments() ,ui->verticalLayout_150);

    if(!product->getQuantity() && !ui->pushButton_100->isHidden()) {
        ui->pushButton_100->hide();
    }
    if(product->getQuantity() && ui->pushButton_100->isHidden()) {
        ui->pushButton_100->show();
    }

    ChangeUI();
}

void product_page::setCustomer()
{
    curCustomer=CurrentUser::GetCustomer();
}


product_page::~product_page()
{
    delete ui;
}

void product_page::on_pushButton_103_clicked()
{
    if(check)
    {
        return;
    }
    check=true;
    ui->pushButton_103->setIcon(QIcon(":/new/prefix1/assets/star_on.png"));
    ui->pushButton_106->setIcon(QIcon(":/new/prefix1/assets/star_off.png"));
    ui->pushButton_107->setIcon(QIcon(":/new/prefix1/assets/star_off.png"));
    ui->pushButton_105->setIcon(QIcon(":/new/prefix1/assets/star_off.png"));
    ui->pushButton_108->setIcon(QIcon(":/new/prefix1/assets/star_off.png"));
    if(!numofstarsOfseller)
        curCustomer->RateSeller(product->getSeller_ID(),1);
    int stars = round(UTILITY::GetSellerRating(product->getSeller_ID()));
    ui->label_151->setText(QString::number(stars));
}


void product_page::on_pushButton_106_clicked()
{
    if(check)
    {
        return;
    }
    check=true;
    ui->pushButton_103->setIcon(QIcon(":/new/prefix1/assets/star_on.png"));
    ui->pushButton_106->setIcon(QIcon(":/new/prefix1/assets/star_on.png"));
    ui->pushButton_107->setIcon(QIcon(":/new/prefix1/assets/star_off.png"));
    ui->pushButton_105->setIcon(QIcon(":/new/prefix1/assets/star_off.png"));
    ui->pushButton_108->setIcon(QIcon(":/new/prefix1/assets/star_off.png"));
    if(!numofstarsOfseller)
        curCustomer->RateSeller(product->getSeller_ID(),2);
    int stars = round(UTILITY::GetSellerRating(product->getSeller_ID()));
    ui->label_151->setText(QString::number(stars));
}


void product_page::on_pushButton_107_clicked()
{
    if(check)
    {
        return;
    }
    check=true;
    ui->pushButton_103->setIcon(QIcon(":/new/prefix1/assets/star_on.png"));
    ui->pushButton_106->setIcon(QIcon(":/new/prefix1/assets/star_on.png"));
    ui->pushButton_107->setIcon(QIcon(":/new/prefix1/assets/star_on.png"));
    ui->pushButton_105->setIcon(QIcon(":/new/prefix1/assets/star_off.png"));
    ui->pushButton_108->setIcon(QIcon(":/new/prefix1/assets/star_off.png"));
    if(!numofstarsOfseller)
        curCustomer->RateSeller(product->getSeller_ID(),3);
    int stars = round(UTILITY::GetSellerRating(product->getSeller_ID()));
    ui->label_151->setText(QString::number(stars));
}


void product_page::on_pushButton_105_clicked()
{
    if(check)
    {
        return;
    }
    check=true;
    ui->pushButton_103->setIcon(QIcon(":/new/prefix1/assets/star_on.png"));
    ui->pushButton_106->setIcon(QIcon(":/new/prefix1/assets/star_on.png"));
    ui->pushButton_107->setIcon(QIcon(":/new/prefix1/assets/star_on.png"));
    ui->pushButton_105->setIcon(QIcon(":/new/prefix1/assets/star_on.png"));
    ui->pushButton_108->setIcon(QIcon(":/new/prefix1/assets/star_off.png"));
    if(!numofstarsOfseller)
        curCustomer->RateSeller(product->getSeller_ID(),4);
    int stars = round(UTILITY::GetSellerRating(product->getSeller_ID()));
    ui->label_151->setText(QString::number(stars));
}


void product_page::on_pushButton_108_clicked()
{
    if(check)
    {
        return;
    }
    check=true;
    ui->pushButton_103->setIcon(QIcon(":/new/prefix1/assets/star_on.png"));
    ui->pushButton_106->setIcon(QIcon(":/new/prefix1/assets/star_on.png"));
    ui->pushButton_107->setIcon(QIcon(":/new/prefix1/assets/star_on.png"));
    ui->pushButton_105->setIcon(QIcon(":/new/prefix1/assets/star_on.png"));
    ui->pushButton_108->setIcon(QIcon(":/new/prefix1/assets/star_on.png"));
    if(!numofstarsOfseller)
        curCustomer->RateSeller(product->getSeller_ID(),5);
    int stars = round(UTILITY::GetSellerRating(product->getSeller_ID()));
    ui->label_151->setText(QString::number(stars));
}


//This function must be called in order for the logged in customer add a comment *setCustomer(CUSTOMER cust)*

void product_page::on_pushButton_109_clicked()
{
    if(ui->lineEdit_105->text().size()) {
        comments->AddComment(curCustomer->GetName(),ui->lineEdit_105->text());
        product->Addcomment(curCustomer->GetName(),ui->lineEdit_105->text());
        ui->lineEdit_105->clear();
    }
}


void product_page::on_pushButton_114_clicked()
{
    if(check2)
    {
        return;
    }
    check2=true;
    ui->pushButton_114->setIcon(QIcon(":/new/prefix1/assets/star_on.png")); //1 star
    ui->pushButton_110->setIcon(QIcon(":/new/prefix1/assets/star_off.png")); //2 star
    ui->pushButton_111->setIcon(QIcon(":/new/prefix1/assets/star_off.png")); //3 star
    ui->pushButton_112->setIcon(QIcon(":/new/prefix1/assets/star_off.png")); //4 star
    ui->pushButton_113->setIcon(QIcon(":/new/prefix1/assets/star_off.png")); //5 star
    if(!numofStars)
        curCustomer->RateProduct(product->getID(),1);
}


void product_page::on_pushButton_110_clicked()
{
    if(check2)
    {
        return;
    }
    check2=true;
    ui->pushButton_114->setIcon(QIcon(":/new/prefix1/assets/star_on.png")); //1 star
    ui->pushButton_110->setIcon(QIcon(":/new/prefix1/assets/star_on.png")); //2 star
    ui->pushButton_111->setIcon(QIcon(":/new/prefix1/assets/star_off.png")); //3 star
    ui->pushButton_112->setIcon(QIcon(":/new/prefix1/assets/star_off.png")); //4 star
    ui->pushButton_113->setIcon(QIcon(":/new/prefix1/assets/star_off.png")); //5 star
    if(!numofStars)
        curCustomer->RateProduct(product->getID(),2);
}


void product_page::on_pushButton_111_clicked()
{
    if(check2)
    {
        return;
    }
    check2=true;
    ui->pushButton_114->setIcon(QIcon(":/new/prefix1/assets/star_on.png")); //1 star
    ui->pushButton_110->setIcon(QIcon(":/new/prefix1/assets/star_on.png")); //2 star
    ui->pushButton_111->setIcon(QIcon(":/new/prefix1/assets/star_on.png")); //3 star
    ui->pushButton_112->setIcon(QIcon(":/new/prefix1/assets/star_off.png")); //4 star
    ui->pushButton_113->setIcon(QIcon(":/new/prefix1/assets/star_off.png")); //5 star
    if(!numofStars)
        curCustomer->RateProduct(product->getID(),3);
}


void product_page::on_pushButton_112_clicked()
{
    if(check2)
    {
        return;
    }
    check2=true;
    ui->pushButton_114->setIcon(QIcon(":/new/prefix1/assets/star_on.png")); //1 star
    ui->pushButton_110->setIcon(QIcon(":/new/prefix1/assets/star_on.png")); //2 star
    ui->pushButton_111->setIcon(QIcon(":/new/prefix1/assets/star_on.png")); //3 star
    ui->pushButton_112->setIcon(QIcon(":/new/prefix1/assets/star_on.png")); //4 star
    ui->pushButton_113->setIcon(QIcon(":/new/prefix1/assets/star_off.png")); //5 star
    if(!numofStars)
        curCustomer->RateProduct(product->getID(),4);
}


void product_page::on_pushButton_113_clicked()
{
    if(check2)
    {
        return;
    }
    check2=true;
    ui->pushButton_114->setIcon(QIcon(":/new/prefix1/assets/star_on.png")); //1 star
    ui->pushButton_110->setIcon(QIcon(":/new/prefix1/assets/star_on.png")); //2 star
    ui->pushButton_111->setIcon(QIcon(":/new/prefix1/assets/star_on.png")); //3 star
    ui->pushButton_112->setIcon(QIcon(":/new/prefix1/assets/star_on.png")); //4 star
    ui->pushButton_113->setIcon(QIcon(":/new/prefix1/assets/star_on.png")); //5 star
    if(!numofStars)
        curCustomer->RateProduct(product->getID(),5);
}


//Add to cart button
void product_page::on_pushButton_100_clicked()
{
    if(!(product->getQuantity() - 1) && !ui->pushButton_100->isHidden()) {
        ui->pushButton_100->hide();
    }
    if(product->getQuantity() - 1 && ui->pushButton_100->isHidden()) {
        ui->pushButton_100->show();
    }

    ui->label_115->setText("Added successfully");
    ui->label_115->setStyleSheet("color: rgb(0, 200, 0);");
    curCart=curCustomer->getCart();
    curCart.add(product->getID(), 1);
    curCustomer->setCart(curCart);
}

//Add to wishlist button
void product_page::on_pushButton_102_clicked()
{
    curCustomer->modify_wishlist(product->getID());
    if(ui->pushButton_102->text()=="Remove from wishlist")
    {
        ui->label_116->setText("Removed successfully to wishlist");
        ui->pushButton_102->setText("Add to wishlist");
    }
    else
    {
        ui->label_116->setText("Added successfully to wishlist");
        ui->pushButton_102->setText("Remove from wishlist");
    }
}


void product_page::pre(){
    
    numofStars=curCustomer->getProductStars(product->getID());
    check2 = false;
    if(!numofStars)
        return;
    if(numofStars==1)
        on_pushButton_114_clicked();
    else if(numofStars==2)
        on_pushButton_110_clicked();
    else if(numofStars==3)
        on_pushButton_111_clicked();
    else if(numofStars==4)
        on_pushButton_112_clicked();
    else
        on_pushButton_113_clicked();


}

void product_page::preSeller()
{
    numofstarsOfseller=curCustomer->getStarsseller(product->getSeller_ID());
    check = false;
    if(!numofstarsOfseller)
        return ;
    if(numofstarsOfseller==1)
        on_pushButton_103_clicked();
    else if(numofstarsOfseller==2)
        on_pushButton_106_clicked();
    else if(numofstarsOfseller==3)
        on_pushButton_107_clicked();
    else if(numofstarsOfseller==4)
        on_pushButton_105_clicked();
    else
        on_pushButton_108_clicked();
}

void product_page::setId(int x)
{
    id = x;
}

void product_page::ChangeUI()
{
    if(CurrentUser::GetType() == '2' && !ui->pushButton_102->isHidden()){
        ui->pushButton_100->hide();
        ui->pushButton_102->hide();
        ui->pushButton_109->hide();
        ui->pushButton_108->hide();
        ui->pushButton_105->hide();
        ui->pushButton_107->hide();
        ui->pushButton_106->hide();
        ui->pushButton_103->hide();
        ui->pushButton_114->hide();
        ui->pushButton_110->hide();
        ui->pushButton_111->hide();
        ui->pushButton_112->hide();
        ui->pushButton_113->hide();
        ui->lineEdit_105->hide();
        ui->label_160->hide();
    }
    else if(CurrentUser::GetType() == '1' && ui->pushButton_102->isHidden()) {
        ui->pushButton_102->show();
        ui->pushButton_109->show();
        ui->pushButton_108->show();
        ui->pushButton_105->show();
        ui->pushButton_107->show();
        ui->pushButton_106->show();
        ui->pushButton_103->show();
        ui->pushButton_114->show();
        ui->pushButton_110->show();
        ui->pushButton_111->show();
        ui->pushButton_112->show();
        ui->pushButton_113->show();
        ui->lineEdit_105->show();
        ui->label_160->show();
    }
}


void product_page::on_pushButton_104_clicked()
{
    emit back();
}

void product_page::Clear()
{
    ui->label_115->clear();
    ui->label_116->clear();
    ui->lineEdit_105->clear();
    if(comments)
    {
        delete comments;
        comments = nullptr;
    }
}


#ifndef PRODUCT_PAGE_H
#define PRODUCT_PAGE_H

#include "PRODUCT.h"
#include <QWidget>
#include "commentcontainer.h"
#include "customer.h"
#include "currentuser.h"

namespace Ui {
class product_page;
}

class product_page : public QWidget
{
    Q_OBJECT

    //price name rate quantity description comments
public:
    explicit product_page(QWidget *parent = nullptr);
    void setProduct(int id);
    void setProductRate(PRODUCT product);
    void setCustomer();
    void Clear();
    void pre();
    void preSeller();
    static void setId(int x);
    void ChangeUI();
    ~product_page();

   //void setProductForHomePage(int idd);
signals:
    void back();


private slots:


    void on_pushButton_103_clicked();

    void on_pushButton_106_clicked();

    void on_pushButton_107_clicked();

    void on_pushButton_105_clicked();

    void on_pushButton_108_clicked();

    void on_pushButton_109_clicked();

    void on_pushButton_114_clicked();

    void on_pushButton_110_clicked();

    void on_pushButton_111_clicked();

    void on_pushButton_112_clicked();

    void on_pushButton_113_clicked();

    void on_pushButton_100_clicked();

    void on_pushButton_102_clicked();

    void on_pushButton_104_clicked();

private:
    Ui::product_page *ui;
    bool check=false;
    bool check2=false;
    PRODUCT *product;
    static inline int id;
    CART curCart;
    CUSTOMER* curCustomer;
    CommentContainer *comments = nullptr;
    QString paths[6] = {":/new/prefix1/assets/s0.png", ":/new/prefix1/assets/s1.png", ":/new/prefix1/assets/s2.png", ":/new/prefix1/assets/s3.png",
                        ":/new/prefix1/assets/s4.png", ":/new/prefix1/assets/s5.png"};
    int numofStars;
    int numofstarsOfseller;


};

#endif // PRODUCT_PAGE_H


#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "PRODUCT.h"
#include "cartcontainer.h"
#include "customcontainer.h"
#include "product_page.h"
#include "qmenu.h"
#include "utility.h"
#include "userdata.h"
#include "creditcard.h"
#include "productui.h"
#include "qdatetime.h"
#include <QScrollBar>
#include "dialog.h"
#include <QMainWindow>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:


    void on_pushButton_7_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_23_clicked();

    void on_pushButton_24_clicked();

    void on_pushButton_27_clicked();

    void on_pushButton_25_clicked();

    void on_pushButton_26_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_9_clicked();

    void on_comboBox_5_currentIndexChanged(int index);

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void ChangePrice();

    void on_lineEdit_11_returnPressed();

    void PlaceOrder();

    void ViewProduct();

    void ProductPageBack();

    void ProductSubmited();     ///////update My products//////////

    void on_pushButton_13_clicked();

    void on_lineEdit_12_returnPressed();

    void on_lineEdit_13_returnPressed();

    void on_pushButton_36_clicked();

    void ResetProfile();

    void on_comboBox_5_activated(int index);

    void on_lineEdit_returnPressed();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_comboBox_6_currentIndexChanged(int index);

    void closeEvent(QCloseEvent *event);

    void passIndexToCategory_0();
    void passIndexToCategory_1();
    void passIndexToCategory_2();
    void passIndexToCategory_3();
    void passIndexToCategory_4();
    void passIndexToCategory_5();


   void on_pushButton_30_clicked();

    void on_pushButton_31_clicked();

   void on_pushButton_32_clicked();

    void on_pushButton_33_clicked();

   void on_pushButton_34_clicked();

    void on_pushButton_35_clicked();

   private:
    Ui::MainWindow *ui;

    int userId, page;
    char type;
    CustomContainer *container = nullptr;
    CartContainer *cartC = nullptr;
    unordered_map<int,int> CategoreyMap;
    unordered_map<int,int> ProductMap;
    product_page HomeProduct;
    vector<int> BestCategory;
    unordered_map <int,QString> BestCategoryPath;
    vector<PRODUCT> BestProduct;
    vector<PRODUCT> curProducts;


    void ChangeUI();

    void SignUp();

    void SignIn();

    void setCategory();

    void ClearSignUp();

    void ClearPassReset();

    void ClearSignIn();

    void SetProfile();

    void calculate();

    void SetTopCategory();

    void SetCategoryPath();

    void SetBestProductPath();

    void SetBestProduct();

    void search(bool find);
};

#endif // MAINWINDOW_H

#include <bits/stdc++.h>
#include "mainwindow.h"
#include <QApplication>
#include "customer.h"
#include "userdata.h"
#include "creditcard.h"
#include "cart.h"
#include "files.h"

using namespace std;

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    MainWindow w;
    w.show();


    return a.exec();

}

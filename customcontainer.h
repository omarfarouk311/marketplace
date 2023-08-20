
#ifndef CUSTOMCONTAINER_H
#define CUSTOMCONTAINER_H


#include "productui.h"

#include <QWidget>


class CustomContainer : public QWidget
{
    Q_OBJECT
private:
    vector<ProductUI*> widgets;

private slots:
    void SendSignal();
signals:
    void View();

public:
    CustomContainer(vector<PRODUCT> products, QGridLayout *grid, QWidget *parent = 0);
    void RemoveWidgets(QGridLayout *grid);
    ~CustomContainer();
};

#endif // CUSTOMCONTAINER_H

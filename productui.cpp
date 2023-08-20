

#include "productui.h"
#include "product_page.h"
#include <QWidget>

ProductUI::ProductUI(PRODUCT p, QWidget *parent): QWidget(parent)
{
    this->p = p;
    QString paths[6] = {":/new/prefix1/assets/s0.png", ":/new/prefix1/assets/s1.png", ":/new/prefix1/assets/s2.png", ":/new/prefix1/assets/s3.png",
                        ":/new/prefix1/assets/s4.png", ":/new/prefix1/assets/s5.png"};
    button = new QPushButton("View");
    layout = new QVBoxLayout();
    for (int i = 0; i < 5; ++i) {
        l1[i] = new QLabel();
    }
    setStyleSheet("color:rgb(150, 100, 20);");

    // product picture
    l1[0]->setPixmap(QPixmap(p.getPath()).scaled(QSize(150, 200)));
    l1[0]->setAlignment(Qt::AlignCenter);
    l1[0]->resize(QSize(100, 100));

    // product name
    l1[1]->setText(p.getName());
    l1[1]->setFont(QFont("calibri", 14));

    int stars = round(p.getRating());
    l1[2]->setPixmap(QPixmap(paths[stars]).scaled(QSize(100, 30)));

    // price
    l1[3]->setText(QString::number(p.getPrice()) + '$');
    l1[3]->setFont(QFont("calibri", 20));

    if(p.getQuantity()) l1[4]->hide();
    l1[4]->setText("Out of Stock");
    l1[4]->setStyleSheet("font: 700 12pt \"Calibri\";background-color: rgb(150, 150, 150);");
    for (int i = 0; i < 5; ++i) {
        layout->addWidget(l1[i]);
    }
    layout->addWidget(button);
    setLayout(layout);
    setMaximumSize(QSize(300, 400));
    connect(button , SIGNAL(clicked()), this, SLOT(BClicked()));
}


void ProductUI::BClicked()
{
    product_page::setId(p.getID());
    emit VProduct();
}

ProductUI::~ProductUI() {
    disconnect(button , SIGNAL(clicked()), this, SLOT(BClicked()));
    for (int i = 0; i < 5; i++) {
        if(l1[i]) {
            layout->removeWidget(l1[i]);
            delete l1[i];
        }
    }
    if(button) {
        layout->removeWidget(button);
        delete button;
    }
    if(layout) {

        delete layout;
    }

}

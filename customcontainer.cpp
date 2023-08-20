
#include "customcontainer.h"



CustomContainer::CustomContainer(vector<PRODUCT> products, QGridLayout *grid, QWidget *parent) : QWidget(parent)
{
    int row = 0, col = 0;


    for(auto &i : products){
        ProductUI* x = new ProductUI(i);
        widgets.push_back(x);
    }

    for(auto &i : widgets) {
        grid->addWidget(i , row, col);
        connect(i, SIGNAL(VProduct()), this, SLOT(SendSignal()));
        col++;
        if(col == 3) row++, col = 0;
    }


}
void CustomContainer::SendSignal()
{
    emit View();
}

void CustomContainer::RemoveWidgets(QGridLayout *grid)
{
    for(int i = 0; i < widgets.size(); i++) {
        if(widgets[i])
            grid->removeWidget(widgets[i]);
    }
}

CustomContainer::~CustomContainer() {
    for(auto i : widgets) {
        disconnect(i, SIGNAL(VProduct()), this, SLOT(SendSignal()));
        if(i)
            delete i;
    }
}


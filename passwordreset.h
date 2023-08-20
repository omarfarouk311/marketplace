#ifndef PASSWORDRESET_H
#define PASSWORDRESET_H

#include <QDialog>

namespace Ui {
class passwordreset;
}

class passwordreset : public QDialog
{
    Q_OBJECT

public:
    explicit passwordreset(QWidget *parent = nullptr);
    ~passwordreset();

private:
    Ui::passwordreset *ui;
};

#endif // PASSWORDRESET_H

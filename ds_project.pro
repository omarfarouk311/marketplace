QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addproduct.cpp \
    comment.cpp \
    commentcontainer.cpp \
    currentuser.cpp \
    customer.cpp \
    dialog.cpp \
    productui.cpp \
    seller.cpp \
    product.cpp \
    cart.cpp \
    creditcard.cpp \
    person.cpp \
    utility.cpp \
    userdata.cpp \
    mainwindow.cpp \
    main.cpp \
    cartcontainer.cpp \
    cartproduct.cpp \
    customcontainer.cpp \
    product_page.cpp \
    files.cpp

HEADERS += \
    addproduct.h \
    cartcontainer.h \
    comment.h \
    commentcontainer.h \
    currentuser.h \
    customer.h \
    dialog.h \
    productui.h \
    seller.h \
    product.h \
    cart.h \
    creditcard.h \
    person.h \
    utility.h \
    userdata.h \
    mainwindow.h \
    cartproduct.h \
    customcontainer.h \
    product_page.h \
    files.h

FORMS += \
    addproduct.ui \
    dialog.ui \
    mainwindow.ui \
    product_page.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc

DISTFILES += \
    assets/calender.png


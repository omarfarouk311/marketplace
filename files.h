#ifndef FILES_H
#define FILES_H
#include<fstream>
#include "customer.h"
#include "product.h"
#include "seller.h"
#include "utility.h"
#include "userdata.h"
#include "cart.h"

class FILES
{
public:
    FILES();

    static void read_customer();
    static void write_customer();

    static void read_seller();
    static void write_seller();

    static void read_products();
    static void write_products();

    static void read_SellerRate();
    static void write_SellerRate();

    static void read_soldByCategories();
    static void write_soldByCategories();

    static void read_verification();
    static void write_verification();

    static void read_questions();
    static void write_questions();

    static void read_emailToID();
    static void write_emailToID();

    static void read_sortedBestSelling();
    static void write_sortedBestSelling();

    static void read_all();
    static void write_all();
};

#endif // FILES_H

#ifndef ITEM_TO_PURCHASE_H
#define ITEM_TO_PURCHASE_H

#include <string>
using namespace std;

class ItemToPurchase {

public:
    ItemToPurchase();
    ItemToPurchase(string Name, string Description, int Price, int Quantity);
    void SetName(string Name);
    void SetDescription(string Description);
    void PrintItemCost();
    void SetPrice(int Price);
    void SetQuantity(int Quantity);
    void PrintItemDescription();
    string GetName();
    string GetDescription();
    int GetPrice();
    int GetQuantity();
private:
    string I_Name;
    string I_Description;
    int I_Price;
    int I_Quantity;

};



#endif
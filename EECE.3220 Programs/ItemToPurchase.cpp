#include <iostream>
using namespace std;

#include "ItemToPurchase.h"
ItemToPurchase::ItemToPurchase() {
    I_Name = "none";
    I_Description = "none";
    I_Price = 0;
    I_Quantity = 0;
}
ItemToPurchase::ItemToPurchase(string Name, string Description, int Price, int Quantity) {
    I_Name = Name;
    I_Description = Description;
    I_Price = Price;
    I_Quantity = Quantity;
}

void ItemToPurchase::SetName(string Name) {
    I_Name = Name;
}
void ItemToPurchase::SetDescription(string Description) {
    I_Description = Description;
}
void ItemToPurchase::SetQuantity(int Quantity) {
    I_Quantity = Quantity;
}
void ItemToPurchase::SetPrice(int Price) {
    I_Price = Price;
}
string ItemToPurchase::GetName() {
    return I_Name;
}
string ItemToPurchase::GetDescription() {
    return I_Description;
}
int ItemToPurchase::GetPrice() {
    return I_Price;
}
int  ItemToPurchase::GetQuantity() {
    return I_Quantity;
}
void ItemToPurchase::PrintItemCost() {
    int n = I_Price * I_Quantity;
    cout << I_Name << " " << I_Quantity << " @ $" << I_Price << " = $" << n << endl;
}
void ItemToPurchase::PrintItemDescription() {
    cout << I_Name << ": " << I_Description << endl;
}
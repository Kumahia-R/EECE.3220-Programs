#pragma once
#ifndef SHOPPING_CART_H
#define SHOPPING_CART_H

#include <vector>
#include "ItemToPurchase.h"
using namespace std;
class ShoppingCart {
public:
    ShoppingCart();
    ShoppingCart(string customerName, string Inputdate);
    void AddItem(ItemToPurchase addNewItem);
    void RemoveItem(string I_Name);
    void ModifyItem(ItemToPurchase Mod_Item);
    string GetCustomerName();
    string GetDate();
    int GetNumItemsInCart();
    int GetCostOfCart();
    void PrintTotal();
    void PrintDescriptions();

private:
    string nameEntered;
    string dateEntered;
    vector<ItemToPurchase> cartItems;
};
#endif // !SHOPPING_CART_H
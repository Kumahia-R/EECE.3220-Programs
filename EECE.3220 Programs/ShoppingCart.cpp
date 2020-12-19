#include <iostream>
using namespace std;

#include "ShoppingCart.h"
ShoppingCart::ShoppingCart() {
    nameEntered = "none";
    dateEntered = "January 1, 2016";
}
ShoppingCart::ShoppingCart(string customerName, string Inputdate) {
    nameEntered = customerName;
    dateEntered = Inputdate;
}
void ShoppingCart::AddItem(ItemToPurchase addNewItem) {
    cartItems.push_back(addNewItem);
}
void ShoppingCart::RemoveItem(string I_Name) {
    int ItemSearch = 0;
    int n = cartItems.size();
    for (int i = 0; i < n; i++) {
        
        if (cartItems.at(i).GetName() == I_Name) {
            ItemSearch = 1;
            cartItems.erase(cartItems.begin() + i);
        }
    }
    if (!ItemSearch) {
        cout << "Item not found in cart. Nothing removed." << endl;
    }
}
void ShoppingCart::ModifyItem(ItemToPurchase Mod_Item) {
    int ItemToMod = 0;
    if (!ItemToMod) {
        cout << "Item not found in cart. Nothing modified." << endl;
    }
    int n = cartItems.size();
    for (int i = 0; i < n; i++) {
        if (cartItems.at(i).GetName() == Mod_Item.GetName()) {
            cartItems.at(i).SetQuantity(Mod_Item.GetQuantity());
            ItemToMod = 1;
        }
    }

}
string ShoppingCart::GetCustomerName() {
    return nameEntered;
}
string ShoppingCart::GetDate() {
    return dateEntered;
}
int ShoppingCart::GetNumItemsInCart() {
    int i = 0, n = cartItems.size();
    int Cart_Items = 0;
    while (i < n) {
        Cart_Items = Cart_Items + cartItems.at(i).GetQuantity();
        i++;
    }
    return Cart_Items;
}

int ShoppingCart::GetCostOfCart() {
    int total = 0, i = 0, n = cartItems.size();
    if (n == 0) {
        return 0;
    }
    while (i < n) {
        total = total + cartItems.at(i).GetPrice() * cartItems.at(i).GetQuantity();
        i++;
    }
    return total;
}
void ShoppingCart::PrintTotal() {
    cout << nameEntered << "'s Shopping Cart - " << dateEntered << endl;
    cout << "Number of Items: " << GetNumItemsInCart() << endl << endl;
    int n = cartItems.size();
    if (n == 0) {
        cout << "SHOPPING CART IS EMPTY" << endl;
    }

    else {
        int i = 0, n = cartItems.size();
        while (i < n) {
            cartItems.at(i).PrintItemCost();
            i++;
        }

    }
    cout << endl << "Total: $" << GetCostOfCart() << endl;
}
void ShoppingCart::PrintDescriptions() {
    cout << nameEntered << "'s Shopping Cart - " << dateEntered << endl << endl;
    cout << "Item Descriptions" << endl;
    int i = 0, n = cartItems.size();
    while (i < n) {
        cartItems.at(i).PrintItemDescription();
        i++;
    }
}

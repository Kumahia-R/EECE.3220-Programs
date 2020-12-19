#include <iostream>
using namespace std;
#include <string>
#include "ItemToPurchase.h"
#include "ShoppingCart.h"



void PrintMenu(ShoppingCart shoppingCart) {
    string nameofItem;
    string itemDescription;
    string modName;
    int itemPrice = 0;
    int itemQuantity = 0;
    int newQuantity = 0;
    ItemToPurchase Item_new;
    ItemToPurchase Item_mod;

    cout << endl << "MENU" << endl << endl;
    cout << "a - Add item to cart" << endl;
    cout << "d - Remove item from cart" << endl;
    cout << "c - Change item quantity" << endl;
    cout << "i - Output items' descriptions" << endl;
    cout << "o - Output shopping cart" << endl;
    cout << "q - Quit" << endl << endl;
    cout << "Choose an option: " << endl;
    char userInput;
    cin >> userInput;
    cin.ignore();

    while (userInput != 'a' && userInput != 'd' && userInput != 'c'
        && userInput != 'i' && userInput != 'o' && userInput != 'q') {
        cout << "Choose an option: " << endl;
        cin >> userInput;
    }
    while (userInput != 'q') {
    
        while (userInput != 'a' && userInput != 'd' && userInput != 'c'
            && userInput != 'i' && userInput != 'o' && userInput != 'q') {
            cout << "Choose an option: " << endl;
            cin >> userInput;
        }
        switch (userInput) {
        case 'a':
            cout << endl << "ADD ITEM TO CART" << endl << endl;
            cout << "Enter the item name: ";
            getline(cin, nameofItem);
            cout << endl << "Enter the item description: ";
            getline(cin, itemDescription);
            cout << endl << "Enter the item price: ";
            cin >> itemPrice;
            cout << endl << "Enter the item quantity: ";
            cin >> itemQuantity;
            Item_new.SetName(nameofItem);
            Item_new.SetDescription(itemDescription);
            Item_new.SetPrice(itemPrice);
            Item_new.SetQuantity(itemQuantity);
            shoppingCart.AddItem(Item_new);
            break;


        case 'd':
            
            cout << endl << "REMOVE ITEM FROM CART" << endl;
            cout << "Enter name of item to remove: " << endl;
            getline(cin, modName);
            shoppingCart.RemoveItem(modName);
            break;


        case  'c':
            cout << endl << "CHANGE ITEM QUANTITY" << endl;
            cout << "Enter the item name: " << endl;
            cin.ignore();
            getline(cin, nameofItem);
            cout << endl << "Enter the new quantity: " << endl;
            cin >> newQuantity;
            Item_mod.SetName(nameofItem);
            Item_mod.SetQuantity(newQuantity);
            shoppingCart.ModifyItem(Item_mod);
            break;

        case 'o':
            cout << endl << "OUTPUT SHOPPING CART" << endl;
            shoppingCart.PrintTotal();
            break;


        case 'i':
            cout << endl << "OUTPUT ITEMS' DESCRIPTIONS" << endl << endl;
            shoppingCart.PrintDescriptions();
            break;

        }

        cout << endl << "MENU" << endl << endl;
        cout << "a - Add item to cart" << endl;
        cout << "d - Remove item from cart" << endl;
        cout << "c - Change item quantity" << endl;
        cout << "i - Output items' descriptions" << endl;
        cout << "o - Output shopping cart" << endl;
        cout << "q - Quit" << endl << endl;
        cout << "Choose an option: " << endl;
        cin >> userInput;
        cin.ignore();
    }



}

int main() {
    string userName;
    string date;

    cout << "Enter customer's name: " << endl;
    getline(cin, userName);
    cout << "Enter today's date: " << endl;
    getline(cin, date);
    cout << endl << "Customer name: " << userName << endl;
    cout << "Today's date: " << date << endl << endl;
    ShoppingCart Customer_Cart(userName, date);
    PrintMenu(Customer_Cart);

    return 0;

}

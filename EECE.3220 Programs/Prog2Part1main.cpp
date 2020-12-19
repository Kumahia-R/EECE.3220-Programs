#include <iostream>
using namespace std;

#include "ItemToPurchase.h"

int main() {
	string userName;
	int userPrice;
	int userQuantity;
	cout << "Item 1" << endl << "Enter the item name:" << endl;
	getline(cin, userName);
	cout << "Enter the item price:" << endl;
	cin >> userPrice;
	cout << "Enter the item quantity:" << endl << endl;
	cin >> userQuantity;
	ItemToPurchase item1;
	item1.SetName(userName);
	item1.SetPrice(userPrice);
	item1.SetQuantity(userQuantity);
	cin.ignore();
	cout << "Item 2" << endl << "Enter the item name:" << endl;
	getline(cin, userName);
	cout << "Enter the item price:" << endl;
	cin >> userPrice;
	cout << "Enter the item quantity:" << endl << endl;
	cin >> userQuantity;
	ItemToPurchase item2;
	item2.SetName(userName);
	item2.SetPrice(userPrice);
	item2.SetQuantity(userQuantity);
	int totPrice1 = item1.GetPrice() * item1.GetQuantity();
	int totPrice2 = item2.GetPrice() * item2.GetQuantity();
	cout << "TOTAL COST" << endl;
	cout << item1.GetName() << " " << item1.GetQuantity() << " @ $" << item1.GetPrice() << " = $" << totPrice1 << endl;
	cout << item2.GetName() << " " << item2.GetQuantity() << " @ $" << item2.GetPrice() << " = $" << totPrice2 << endl << endl;
	cout << "Total: $" << totPrice1 + totPrice2 << endl;
	/* Type your code here */

	return 0;
}
#include "Queue.h"
#include "QItem.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	ifstream file; 
	string fileName; 
	string line;
	Queue<QItem> expCus;
	Queue<QItem> normCus;
	
	cout << "Enter input file name: ";
	cin >> fileName;
	cout << "Reading " << fileName << " ..." << endl;
	file.open(fileName);

	int cusPos = 1;
	while (getline(file, line))
	{
		string arrive;
		string service;
		string lane;
		string letter;

		int index = 2;
		while (line.at(index) != ' ')
		{
			arrive.push_back(line.at(index));
			index++;
		}
		index++;
		service.push_back(line.at(index));
		QItem temp(cusPos, arrive, service);

		if (line.at(0) == 'E')
		{
			lane = "express";
			expCus.enqueue(temp);
		}
		else if (line.at(0) == 'N')
		{
			lane = "normal";
			normCus.enqueue(temp);
		}
		cout << "Customer " << cusPos << " to " << lane << " lane " << "(A = " << arrive << ", S = " << service << ")" << endl;
		cusPos++;
	}
	file.close();

	cout << "Done reading " << fileName << endl;

	int time = 0;

	int normieTime = 0;
	int expTime = 0;
	int normCusServ = 0;
	int ExpCusServ = 0;
	while (!expCus.empty() || !normCus.empty()) {
		if (normieTime == 0 && normCus.getFront().getArr() <= time && normCusServ == 0)
		{
			cout << "T=" << time << ": Serving customer " << normCus.getFront().getcNum() << " in normal lane" << endl;
			normieTime = normCus.getFront().getSvc();
			normCusServ = 1;
		}
		if (expTime == 0 && expCus.getFront().getArr() <= time && ExpCusServ == 0)
		{
			cout << "T=" << time << ": Serving customer " << expCus.getFront().getcNum() << " in express lane" << endl;
			expTime = expCus.getFront().getSvc();
			ExpCusServ = 1;
		}
		if (normieTime != 0) {
			normieTime--;
		}
		if (expTime != 0) {
			expTime--;
		}
		if (normieTime == 0 && normCusServ == 1) {
			cout << "T=" << time << ": Done serving customer " << normCus.getFront().getcNum() << " in normal lane" << endl;
			normCusServ = 0;
			normCus.dequeue();
		}
		if (expTime == 0 && ExpCusServ == 1) {
			cout << "T=" << time << ": Done serving customer " << expCus.getFront().getcNum() << " in express lane" << endl;
			ExpCusServ = 0;
			expCus.dequeue();
		}
		time++;
	}
	cout << "Done serving all customers" << endl;
	return 0;
}
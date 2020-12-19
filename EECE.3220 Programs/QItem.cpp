#include <iostream>
#include <string>
#include "QItem.h"

using namespace std;

QItem::QItem()
{
    cNum = 0;
    arrTime = '0';
    svcTime = '0';
}
QItem::QItem(int cust, string arr, string serv)
{
    cNum = cust;
    arrTime = stoi(arr);
    svcTime = stoi(serv);
}
int QItem::getcNum() {
    return cNum;
}
void QItem::setcNum(int num) {
    cNum = num;
}
int QItem::getArr() {
    return arrTime;
}
void QItem::setArr(int num) {
    arrTime = num;
}
int QItem::getSvc() {
    return svcTime;
}
void QItem::setSvc(int num) {
    svcTime = num;
}
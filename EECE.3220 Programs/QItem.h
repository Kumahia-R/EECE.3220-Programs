#ifndef QITEM_H
#define QITEM_H

#include <string>
using namespace std;

class QItem
{
public:
    QItem();
    QItem(int cNum, string arrTime, string svcTime);
    int getcNum();
    void setcNum(int num);
    int getArr();
    void setArr(int num);
    int getSvc();
    void setSvc(int num);

private:
    unsigned cNum;        // Customer number
    unsigned arrTime;    // Arrival time
    unsigned svcTime;    // Time required to service customer
};

#endif
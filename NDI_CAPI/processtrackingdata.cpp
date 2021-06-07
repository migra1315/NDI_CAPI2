#include "processtrackingdata.h"
using namespace std;


//构造函数
processTrackingData::processTrackingData(string str)
{
    this->data = str;
    evaluateData();
    if(dataIsValid)
    {
        getProbeCoordinate();
//        getProbeAttitude();
        getRigidCoordinate();
    }
}

//判断ndi返回的数据是否有效
void processTrackingData::evaluateData()
{
    int index1 = data.find("MISSING");
    int index2 = data.find("DISABLE");
    int dataLength = data.size();
    if ((index1 == -1) & (index2 == -1) & (dataLength==320)){
        dataIsValid = true;
        return;
    }
    else
    {
        dataIsValid = false;
        return;
    }
}

void processTrackingData::getProbeCoordinate()
{
    string x = string(data,28,7);
    probeTx = atoi(x.data())/100.0;

    string y = string(data,35,7);
    probeTy = atoi(y.data())/100.0;

    string z = string(data,42,7);
    probeTz = atoi(z.data())/100.0;

    string mx = string(data,74,7);
    probeMx = atoi(mx.data())/100.0;

    string my = string(data,81,7);
    probeMy = atoi(my.data())/100.0;

    string mz = string(data,89,7);
    probeMz = atoi(mz.data())/100.0;

}

void processTrackingData::getRigidCoordinate()
{
    string x1 = string(data,231,7);
    string y1 = string(data,238,7);
    string z1 = string(data,245,7);
    rigidx1 = atoi(x1.data())/100.0;rigidy1 = atoi(y1.data())/100.0;rigidz1 = atoi(z1.data())/100.0;

    string x2 = string(data,252,7);
    string y2 = string(data,259,7);
    string z2 = string(data,266,7);
    rigidx2 = atoi(x2.data())/100.0;rigidy2 = atoi(y2.data())/100.0;rigidz2 = atoi(z2.data())/100.0;

}

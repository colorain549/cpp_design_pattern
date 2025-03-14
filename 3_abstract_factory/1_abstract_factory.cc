// 家具工厂
// 1. 抽象产品
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

// 1. 抽象产品(沙发类)
class Sofa
{
public:
    virtual void produceSofa() const = 0;
};

// 1. 抽象产品(椅子类)
class Chair
{
public:
    virtual void produceChair() const = 0;
};

int main()
{
    return 0;
}
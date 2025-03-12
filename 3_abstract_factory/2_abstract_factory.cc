// 家具工厂
// 1. 抽象产品
// 2. 具体产品
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

// 2. 具体产品(现代沙发)
class ModernSofa : public Sofa
{
public:
    void produceSofa() const override
    {
        cout << "Modern Sofa" << endl;
    }
};

// 2. 具体产品(古典沙发)
class ClassicalSofa : public Sofa
{
public:
    void produceSofa() const override
    {
        cout << "Classical Sofa" << endl;
    }
};

// 1. 抽象产品(椅子类)
class Chair
{
public:
    virtual void produceChair() const = 0;
};

// 2. 具体产品(现代椅子)
class ModernChair : public Chair
{
public:
    void produceChair() const
    {
        cout << "Modern Chair" << endl;
    }
};

// 2. 具体产品(古典椅子)
class ClassicalChair : public Chair
{
public:
    void produceChair() const
    {
        cout << "Classical Chair" << endl;
    }
};

int main()
{
    return 0;
}
// 家具工厂
// 1. 抽象产品
// 2. 具体产品
// 3. 抽象工厂(接口是产品)
// 4. 具体工厂
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

// 3. 抽象工厂(接口是产品)
class Factory
{
public:
    virtual Sofa *sofaFactory() const = 0;
    virtual Chair *chairFactory() const = 0;
};

// 4. 具体工厂(现代类)
class ModernFactory : public Factory
{
public:
    Sofa *sofaFactory() const
    {
        Sofa *modernSofa = new ModernSofa();
        return modernSofa;
    }
    Chair *chairFactory() const
    {
        Chair *modernChair = new ModernChair();
        return modernChair;
    }
};

// 5. 具体工厂(古典类)
class ClassicalFactory : public Factory
{
public:
    Sofa *sofaFactory() const
    {
        Sofa *classicalSofa = new ClassicalSofa();
        return classicalSofa;
    }
    Chair *chairFactory() const
    {
        Chair *classicalChair = new ClassicalChair();
        return classicalChair;
    }
};

int main()
{
    // 
}
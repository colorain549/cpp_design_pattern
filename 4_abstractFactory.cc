// 抽象工厂
// 输入
// 3 modern classical modern
// 输出
// modern chair
// modern sofa
// classical chair
// classical sofa
// modern chair
// modern sofa

#include <iostream>
#include <memory>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::unique_ptr;

// 抽象沙发
class Sofa
{
public:
    virtual void produceSofa() = 0;
};

// 具体沙发
class ModernSofa : public Sofa
{
public:
    void produceSofa()
    {
        cout << "modern sofa" << endl;
    }
};
class ClassicalSofa : public Sofa
{
public:
    void produceSofa()
    {
        cout << "classical sofa" << endl;
    }
};

// 抽象椅子
class Chair
{
public:
    virtual void produceChair() = 0;
};

// 具体椅子
class ModernChair : public Chair
{
public:
    void produceChair()
    {
        cout << "modern chair" << endl;
    }
};
class ClassicalChair : public Chair
{
public:
    void produceChair()
    {
        cout << "classical chair" << endl;
    }
};

// 抽象工厂
class Factory
{
public:
    virtual Sofa *sofaFactory() = 0;
    virtual Chair *chairFactory() = 0;
};

// 具体工厂
class ModernFactory : public Factory
{
public:
    Sofa *sofaFactory()
    {
        Sofa *pModernSofa = new ModernSofa();
        return pModernSofa;
    }
    Chair *chairFactory()
    {
        Chair *pModernChair = new ModernChair();
        return pModernChair;
    }
};
class ClassicalFactory : public Factory
{
public:
    Sofa *sofaFactory()
    {
        Sofa *pClassicalSofa = new ClassicalSofa();
        return pClassicalSofa;
    }
    Chair *chairFactory()
    {
        Chair *pClassicalChair = new ClassicalChair();
        return pClassicalChair;
    }
};

int main()
{
    int times;
    cin >> times;
    string type;
    while (times--)
    {
        cin >> type;
        if ("modern" == type)
        {
            // Factory *pModernFactory = new ModernFactory();
            // Sofa *pModernSofa = pModernFactory->sofaFactory();
            // Chair *pModernChair = pModernFactory->chairFactory();
            unique_ptr<Factory> pModernFactory(new ModernFactory);
            unique_ptr<Sofa> pModernSofa(pModernFactory->sofaFactory());
            unique_ptr<Chair> pModernChair(pModernFactory->chairFactory());
            pModernChair->produceChair();
            pModernSofa->produceSofa();
        }
        else if ("classical" == type)
        {
            // Factory *pClassicalFactory = new ClassicalFactory();
            // Sofa *pClassicalSofa = pClassicalFactory->sofaFactory();
            // Chair *pClassicalChair = pClassicalFactory->chairFactory();
            unique_ptr<Factory> pClasscalFactory(new ClassicalFactory);
            unique_ptr<Sofa> pClassicalSofa(pClasscalFactory->sofaFactory());
            unique_ptr<Chair> pClassicalChair(pClasscalFactory->chairFactory());
            pClassicalChair->produceChair();
            pClassicalSofa->produceSofa();
        }
    }

    return 0;
}
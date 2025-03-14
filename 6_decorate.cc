// 8 咖啡加糖
// A 组件(定义Component接口)
// B 具体组件(实现 ConcreteComponent)
// C 装饰类(定义Decorator装饰类，继承自Component)
// D 具体装饰类(定义具体的装饰者实现，给具体组件对象添加功能)
#include <iostream>
#include <memory>

using std::cin;
using std::cout;
using std::endl;
using std::unique_ptr;

// 咖啡接口
class Coffee
{
public:
    virtual void brew() = 0;
    virtual ~Coffee() {}
};

// 具体的黑咖啡类
class BlackCoffee : public Coffee
{
public:
    void brew() override
    {
        cout << "Brewing Black Coffee" << endl;
    }
};

// 具体的拿铁类
class LatteCoffee : public Coffee
{
public:
    void brew() override
    {
        cout << "Brewing Latte" << endl;
    }
};

// 装饰者抽象类
class Decorate : public Coffee
{
public:
    Coffee *_coffee;

public:
    Decorate(Coffee *coffee) : _coffee(coffee) {}
    void brew() override
    {
        if (_coffee)
        {
            _coffee->brew();
        }
    }
};

// 具体的牛奶装饰者类
class MilkDecorate : public Decorate
{
public:
    MilkDecorate(Coffee *coffee) : Decorate(coffee) {}

    void brew() override
    {
        Decorate::brew();
        cout << "Adding Milk" << endl;
    }
};

// 具体的糖装饰者类
class SugarDecorator : public Decorate
{
public:
    SugarDecorator(Coffee *coffee) : Decorate(coffee) {}

    void brew()
    {
        Decorate::brew();
        cout << "Adding Sugar" << endl;
    }
};

int main()
{
    int coffeeType, condimentType;
    while (cin >> coffeeType >> condimentType)
    {
        // 根据输入制作咖啡
        Coffee *coffee;

        if (coffeeType == 1)
        {
            coffee = new MilkDecorate(coffee);
        }
        else if (coffeeType == 2)
        {
            coffee = new SugarDecorator(coffee);
        }
        else
        {
            cout << "Invalid condiment type" << endl;
            continue;
        }

        // 输出制作过程
        coffee->brew();
    }

    return 0;
}
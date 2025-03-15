// 咖啡加糖(Grind研磨、Brew冲泡、condiments配料)
// A 黑咖啡/拿铁
// B 牛奶/糖
// A + B
// 1 组件(定义Component接口)(Coffee类--brew()接口)
// 2 具体组件(实现 ConcreteComponent)
// 3 装饰类(定义Decorator装饰类，继承自Component)
// 4 具体装饰类(定义具体的装饰者实现，给具体组件对象添加功能)
// 5 测试
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

// 1 组件(定义Component接口)
class Coffee
{
public:
    virtual void brew() = 0;
    virtual ~Coffee() {}
};

// 2 具体组件(实现 ConcreteComponent)
class BlackCoffee : public Coffee
{
public:
    void brew() override
    {
        cout << "Brewing Black Coffee" << endl;
    }
};

// 2 具体组件(实现 ConcreteComponent)
class Lattee : public Coffee
{
public:
    void brew() override
    {
        cout << "Brewing Latte" << endl;
    }
};

// 3 装饰类(定义Decorator装饰类，继承自Component)
class Decorate : public Coffee
{
private:
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

// 4 具体装饰类(定义具体的装饰者实现，给具体组件对象添加功能)
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

// 4 具体装饰类(定义具体的装饰者实现，给具体组件对象添加功能)
class SugarDecorator : public Decorate
{
private:
    Coffee *_coffee;

public:
    SugarDecorator(Coffee *coffee) : Decorate(coffee) {}

    void brew() override
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
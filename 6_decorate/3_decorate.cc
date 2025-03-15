// 咖啡加糖(Grind研磨、Brew冲泡、 condiments配料)
// A 黑咖啡/拿铁
// B 牛奶/糖
// A + B
// 1 组件(定义Component接口)
// 2 具体组件(实现 ConcreteComponent)
// 3 装饰类(定义Decorator装饰类，继承自Component)
// 4 具体装饰类(定义具体的装饰者实现，给具体组件对象添加功能)
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

int main()
{
    return 0;
}
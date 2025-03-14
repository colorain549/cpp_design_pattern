// 咖啡馆(美式咖啡、拿铁咖啡)
// A 研磨咖啡豆 Grinding coffee beans
// B 冲泡咖啡 Brewing coffee
// C 添加调料 Adding condiments
// D 拿铁在添加调料时需要添加牛奶Adding milk
// 1 抽象类(模板方法、抽象方法1、抽象方法2)
// 2 具体类(抽象方法1、抽象方法2)
// 3 实现抽象类的框架
// 4 实现具体类的框架
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

// 1 抽象类(模板方法、抽象方法1、抽象方法2)
// 咖啡制作模板
// 3 实现抽象类的框架
class CoffeeMakerTemplate
{
public:
    // 构造函数
    CoffeeMakerTemplate(const string &coffeeName) : _coffeeName(coffeeName) {}

    // 模板方法定义咖啡制作过程
    virtual void coffeeMaker() {}

    // 具体的实现由子类提供
    virtual void grindCoffeeBeans() = 0;
    virtual void brewingCoffee() = 0;

    // 添加调料的默认实现
    virtual void addCondiments() {};

private:
    string _coffeeName;
};

// 2 具体类(抽象方法1、抽象方法2)
// 美式咖啡制作
// 4 实现具体类的框架
class AmericanCoffeeMaker : public CoffeeMakerTemplate
{
public:
    // !!!注意构造函数!!!
    AmericanCoffeeMaker() : CoffeeMakerTemplate("American Coffee") {}

    // override
    void grindCoffeeBeans() override {}
    void brewingCoffee() override {}
};

// 2 具体类(抽象方法1、抽象方法2)
// 拿铁咖啡制作
// 4 实现具体类的框架
class LatteCoffeeMaker : public CoffeeMakerTemplate
{
public:
    // !!!注意构造函数!!!
    LatteCoffeeMaker() : CoffeeMakerTemplate("Latte") {}

    // override
    void grindCoffeeBeans() override {}
    void brewingCoffee() override {}

    // 添加调料的特定实现override
    void addCondiments() override {}
};

int main()
{
    return 0;
}
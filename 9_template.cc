// 18 咖啡馆
// A 研磨咖啡豆 Grinding coffee beans
// B 冲泡咖啡 Brewing coffee
// C 添加调料 Adding condiments(拿铁需提前, 添加牛奶 Adding milk)
#include <iostream>
#include <string>
#include <memory>

using std::cin;
using std::cout;
using std::endl;
using std::string;

// 抽象类
class CoffeeMakerTemplate
{
public:
    CoffeeMakerTemplate(const string &coffeeName) : _coffeeName(coffeeName) {}

    // 模板方法定义咖啡制作方法
    virtual void makeCoffee()
    {
        cout << "Making " << _coffeeName << ":" << endl;
        grindCoffeeBeans();
        brewCoffee();
        addCondiments();
        cout << endl;
    }

    // 具体步骤的具体实现由子类实现
    virtual void grindCoffeeBeans() = 0;
    virtual void brewCoffee() = 0;

    // 添加调料的具体实现
    virtual void addCondiments()
    {
        cout << "Adding condiments" << endl;
    }

private:
    string _coffeeName;
};

// 具体的美式咖啡类
class AmericanCoffeeMaker : public CoffeeMakerTemplate
{
public:
    AmericanCoffeeMaker() : CoffeeMakerTemplate("American Coffee") {}

    void grindCoffeeBeans() override
    {
        cout << "Grinding coffee beans" << endl;
    }
    void brewCoffee() override
    {
        cout << "Brewing coffee" << endl;
    }
};

// 具体的拿铁咖啡类
class LatteCoffeeMaker : public CoffeeMakerTemplate
{
public:
    LatteCoffeeMaker() : CoffeeMakerTemplate("Latte") {}

    void grindCoffeeBeans() override
    {
        cout << "Grinding coffee beans" << endl;
    }
    void brewCoffee() override
    {
        cout << "Brewing coffee" << endl;
    }

    // 添加调料的特定实现
    void addCondiments() override
    {
        cout << "Adding milk" << endl;
        cout << "Adding condiments" << endl;
    }
};

int main()
{
    CoffeeMakerTemplate *coffeeMaker;

    int coffeeType;
    while (cin >> coffeeType)
    {
        if (coffeeType == 1)
        {
            coffeeMaker = new AmericanCoffeeMaker();
        }
        else if (coffeeType == 2)
        {
            coffeeMaker = new LatteCoffeeMaker();
        }
        else
        {
            cout << "Invalid coffee type" << endl;
            continue;
        }
        coffeeMaker->makeCoffee();
    }

    return 0;
}
// 咖啡馆(美式咖啡、拿铁咖啡)
// A 研磨咖啡豆 Grinding coffee beans
// B 冲泡咖啡 Brewing coffee
// C 添加调料 Adding condiments
// D 拿铁在添加调料时需要添加牛奶Adding milk
// 1 抽象类(模板方法、抽象方法1、抽象方法2)
// 2 具体类(抽象方法1、抽象方法2)
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

// 1 抽象类(模板方法、抽象方法1、抽象方法2)
// 咖啡制作模板
class CoffeeMakerTemplate
{
};

// 2 具体类(抽象方法1、抽象方法2)
// 美式咖啡制作
class AmericanCoffeeMaker : public CoffeeMakerTemplate
{
};

// 2 具体类(抽象方法1、抽象方法2)
// 拿铁咖啡制作
class LatteCoffeeMaker : public CoffeeMakerTemplate
{
};

int main()
{
    return 0;
}
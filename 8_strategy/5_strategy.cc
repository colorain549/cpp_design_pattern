// 超市打折
// A 九折优惠策略：原价的90%。
// B 满减优惠策略：购物满一定金额时，可以享受相应的减免优惠。
// 1. 策略类Strategy
// 2. 具体策略类ConcreteStrategy
// 3. 上下文类Context
// 4. 搭建框架
// 5. 策略类(算法接口)
// 6. 具体策略类(策略接口)
// 7. 上下文类(策略实例)
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

// 策略类(算法接口)
class DiscountStrategy
{
public:
    virtual int applyDiscount(int originalPrice) = 0;
    virtual ~DiscountStrategy() {}
};

// 具体策略类(九折优惠策略)(策略接口)
class NinetyPercentDiscountStrategy : public DiscountStrategy
{
public:
    int applyDiscount(int originalPrice) override {}
};

// 具体策略类(满减优惠策略)(策略接口)
class ReduceDiscountStrategy : public DiscountStrategy
{
public:
    int applyDiscount(int originalPrice) override {}
};

// 上下文类(策略实例)
class DiscountContext
{
public:
    void setDiscountStratagy(DiscountStrategy *discountStrategy) {}
    int applyDiscount(int originalPrice) {}
};

int main()
{
    return 0;
}
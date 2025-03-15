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
// 8. 完善框架(策略类+具体策略类)
// 9. 完善框架(上下文类)
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::round;

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
    int applyDiscount(int originalPrice) override
    {
        return static_cast<int>(round(originalPrice * 0.9));
    }
};

// 具体策略类(满减优惠策略)(策略接口)
class ReduceDiscountStrategy : public DiscountStrategy
{
private:
    // 阈值
    int thresholds[4] = {100, 150, 200, 300};
    int discounts[4] = {5, 15, 25, 40};

public:
    int applyDiscount(int originalPrice) override
    {
        // sizeof(thresholds) 返回 thresholds 数组的总字节数
        // 由于 thresholds 是一个 int 数组，每个 int 通常占 4 个字节
        // 因此 sizeof(thresholds) 的值为 4 * 4 = 16
        // sizeof(discounts[0]) 返回 discounts 数组中第一个元素的大小
        // 即 sizeof(int)，通常为 4 字节
        // sizeof(thresholds) / sizeof(discounts[0]) 计算 thresholds 数组的元素个数
        for (int i = sizeof(thresholds) / sizeof(discounts[0]) - 1; i >= 0; i--)
        {
            if (originalPrice >= thresholds[i])
            {
                return originalPrice - discounts[i];
            }
        }
        return originalPrice;
    }
};

// 上下文类(策略实例)
class DiscountContext
{
private:
    DiscountStrategy *_discountStrategy;

public:
    void setDiscountStrategy(DiscountStrategy *discountStrategy)
    {
        this->_discountStrategy = discountStrategy;
    }
    int applyDiscount(int originalPrice)
    {
        return _discountStrategy->applyDiscount(originalPrice);
    }
};

int main()
{
    return 0;
}
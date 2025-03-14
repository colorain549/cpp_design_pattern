// 14 超市打折
#include <iostream>
#include <vector>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;

// 抽象购物优惠策略接口
class DiscountStrategy
{
public:
    virtual int applyDiscount(int originalPrice) = 0;
    virtual ~DiscountStrategy() {}
};

// 九折策略优惠
class NinetyPecentDiscountStrategy : public DiscountStrategy
{
public:
    int applyDiscount(int originalPrice) override
    {
        return static_cast<int>(std::round(originalPrice * 0.9));
    }
};

// 满减优惠策略
class ReduceDiscountStrategy : public DiscountStrategy
{
private:
    int thresholds[4] = {100, 150, 200, 300};
    int discounts[4] = {5, 15, 25, 40};

public:
    int applyDiscount(int originalPrice) override
    {
        for (int i = sizeof(thresholds) / sizeof(thresholds[0]) - 1; i >= 0; i--)
        {
            if (originalPrice >= thresholds[i])
            {
                return originalPrice - discounts[i];
            }
        }
        return originalPrice;
    }
};

// 上下文类
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
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int M, strategyType;
        cin >> M >> strategyType;

        // 根据优惠策略设置相应的打折策略
        DiscountStrategy *discountStrategy;
        switch (strategyType)
        {
        case 1:
            discountStrategy = new NinetyPecentDiscountStrategy();
            break;
        case 2:
            discountStrategy = new ReduceDiscountStrategy();
            break;
        default:
            cout << "Unknown strategy type" << endl;
            return 1;
        }

        // 设置打折策略
        DiscountContext context;
        context.setDiscountStrategy(discountStrategy);

        // 应用打折策略并输出优惠后价格
        int discountPrice = context.applyDiscount(M);

        // 释放动态分配的打折策略对象
        delete discountStrategy;
    }

    return 0;
}
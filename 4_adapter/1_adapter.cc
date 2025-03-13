// 适配器
// A. TypeC的电脑
// B. USB的充电器
// C. 适配器(TypeC到USB)
// 1. TypeC和USB的抽象接口chargeWithUSB和charge
// 2. TypeC的电脑TypeC口
// 3. USB的充电器USB口
// 4. 适配器(TypeC到USB)
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

// 1. TypeC和USB的抽象接口chargeWithUSB和charge
class TypeC
{
public:
    virtual void charge() = 0;
};

// 1. TypeC和USB的抽象接口chargeWithUSB和charge
class USB
{
public:
    virtual void chargeWithUSB() = 0;
};

int main()
{
    return 0;
}
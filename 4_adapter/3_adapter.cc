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
    virtual void chargeWithTypeC() = 0;
};

// 1. TypeC和USB的抽象接口chargeWithUSB和charge
class USB
{
public:
    virtual void chargeWithUSB() = 0;
};

// 2. TypeC的电脑TypeC口
class Computer : public TypeC
{
public:
    void chargeWithTypeC() override
    {
        cout << "TypeC" << endl;
    }
};

// 3. USB的充电器USB口
class USBCharge : public USB
{
public:
    void chargeWithUSB() override
    {
        cout << "USB Adapter" << endl;
    }
};

int main()
{
    return 0;
}
// 适配器
// A. TypeC的电脑
// B. USB的充电器
// C. 适配器(TypeC到USB)
// 1. TypeC和USB的抽象接口chargeWithUSB和charge
// 2. TypeC的电脑TypeC口
// 3. USB的充电器USB口
// 4. 适配器(TypeC到USB)
// 5. 测试(电脑和充电器)
// 6. 测试(适配器)
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

// 1. TypeC和USB的抽象接口chargeWithUSB和charge
class TypeC
{
public:
    virtual void chargeWithTypeC() = 0;
    virtual ~TypeC() {}
};

// 1. TypeC和USB的抽象接口chargeWithUSB和charge
class USB
{
public:
    virtual void chargeWithUSB() = 0;
    virtual ~USB() {}
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

// 4. 适配器(TypeC到USB)
class TypeCToUSBAdapter : public USB
{
private:
    TypeC *_typeC;

public:
    TypeCToUSBAdapter(TypeC *typeC) : _typeC(typeC) {}

    void chargeWithUSB() override
    {
        _typeC->chargeWithTypeC();
    }
};

int main()
{
    int n;
    int operation;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> operation;
        if (operation == 1)
        {
            TypeC *computer = new Computer();
            computer->chargeWithTypeC();
            delete computer;
        }
        else if (operation == 2)
        {
            // USB的充电器USB口
            USB *usbCharge = new USBCharge();
            usbCharge->chargeWithUSB();
            delete usbCharge;
        }
        else if (operation == 3)
        {
            // 电脑TypeC接口
            TypeC *computer = new Computer();
            // 选择适配器的一端, 接入电脑
            USB *typeCToUSBAdapter = new TypeCToUSBAdapter(computer);
            // 选择的是TypeC一端(输出TypeC)
            typeCToUSBAdapter->chargeWithUSB();
            delete computer;
            delete typeCToUSBAdapter;
        }
    }

    return 0;
}
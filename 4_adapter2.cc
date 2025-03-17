// 6拓展坞
// A Target(目标接口, USB)
// B Adaptee(被适配者, TypeC, TypeCComputer)
// C Adapter(适配器, TypeCToUSBAdapter)
// 1 Target(目标接口, USB)
// 2 Adaptee(被适配者, TypeC, TypeCComputer)
// 3 Adapter(适配器, TypeCToUSBAdapter)
// 4 其他(使用USB充电器和数据线直接供电, USB Adapter)
// 5 测试(1直接使用TypeC充电, 2直接使用USB充电器和数据线充电)
// 6 测试(3使用适配器充电, 通过USB调用接口使用TypeC接口的功能)
// 7 改进(使用智能指针)
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

// 1 Target(目标接口, USB)
class USB
{
public:
    virtual void chargeWithUSB() = 0;
    virtual ~USB() {}
};

// 2 Adaptee(被适配者, TypeC, TypeCComputer)
class TypeC
{
public:
    virtual void chargeWithTypeC() = 0;
    virtual ~TypeC() {}
};

// 2 Adaptee(被适配者, TypeC, TypeCComputer)
class TypeCComputer : public TypeC
{
public:
    void chargeWithTypeC() override
    {
        cout << "TypeC" << endl;
    }
};

// 3 Adapter(适配器, TypeCToUSBAdapter)
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

// 4 其他(USB Adapter)
class USBAdapter : public USB
{
public:
    void chargeWithUSB() override
    {
        cout << "USB Adapter" << endl;
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
            TypeC *computer = new TypeCComputer();
            computer->chargeWithTypeC();
            delete computer;
        }
        else if (operation == 2)
        {
            // 使用USB充电器和数据线直接供电
            USB *usbAdapter = new USBAdapter();
            usbAdapter->chargeWithUSB();
            delete usbAdapter;
        }
        else if (operation == 3)
        {
            // 电脑TypeC接口
            TypeC *computer = new TypeCComputer();
            // 选择适配器的TypeC一端, 接入电脑
            USB *typeCToUSBAdapter = new TypeCToUSBAdapter(computer);
            // 输出TypeC
            // 通过USB调用接口使用TypeC接口的功能
            // 而不需直接直接依赖TypeC接口
            typeCToUSBAdapter->chargeWithUSB();
            delete computer;
            delete typeCToUSBAdapter;
        }
    }
    return 0;
}
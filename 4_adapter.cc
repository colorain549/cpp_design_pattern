// 6 扩展坞
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

// 接口1
class USB
{
public:
    virtual void chargeWithUSB() = 0;
};

// 接口2
class TypeC
{
public:
    virtual void chargeWithTypeC() = 0;
};

// 适配器(TypeC转USB)
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

// TypeC电脑
class TypeCComputer : public TypeC
{
public:
    void chargeWithTypeC() override
    {
        cout << "TypeC" << endl;
    }
};

// USB充电头
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
    int N;
    int choice;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> choice;
        if (choice == 1)
        {
            TypeC *computer = new TypeCComputer();
            computer->chargeWithTypeC();
            delete computer;
        }
        else if (choice == 2)
        {
            USB *adapter = new USBAdapter();
            adapter->chargeWithUSB();
            delete adapter;
        }
    }

    return 0;
}
// 单例(饿汉式)
// 输入
// Apple 3 Banana 2 Orange 5
// 输出
// Apple 3 Banana 2 Orange 5

#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class ShopCar
{
    // step 1: 构造函数私有化
    // public:
private:
    // step 5: default
    ShopCar() {}
    ShopCar(string item, int quantity) : _item(item), _quantity(quantity) {}

public:
    // step 2: 提供接口(指向本对象的静态函数???)(饿汉模式直接返回)
    static ShopCar *getInstance()
    {
        // goto step 3
        // goto step 5
        return _pInstance;
    }

    // step 6: init
    void init(string item, int quantity)
    {
        _item = item;
        _quantity = quantity;
    }

    // step 7: destroy
    void destroy()
    {
        if (_pInstance)
        {
            delete _pInstance;
            _pInstance = nullptr;
        }
    }

    void display()
    {
        cout << _item << " " << _quantity << endl;
    }

private:
    string _item;
    int _quantity;
    // step 3: declare
    static ShopCar *_pInstance;
};
// step 4: define(饿汉模式)
ShopCar *ShopCar::_pInstance = new ShopCar();

int main()
{
    string item;
    int quantity;
    for (int i = 0; i < 3; i++)
    {
        cin >> item >> quantity;
        // ShopCar shopCar(item, quantity);
        // shopCar.display();
        ShopCar::getInstance()->init(item, quantity);
        ShopCar::getInstance()->display();
        // ShopCar::getInstance()->destroy();
    }
    return 0;
}
// 懒汉模式
// * 输出包含小明购物车中的所有商品及其购买数量
// * 使用STL的map
// * 懒汉模式: 第一次使用时才创建
// 1. 私有的构造函数：防止外部代码直接创建类的实例(防止外部实例化)
// 2. 私有的静态实例变量：保存该类的唯一实例
// 3. 公有的静态方法：通过公有的静态方法来获取类的实例
#include <iostream>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::pair;
using std::string;

class ShoppingCartManager
{
private:
    // 1. 私有的构造函数
    ShoppingCartManager() {}

public:
    // 构造函数
    // ShoppingCartManager() {}
    // 3. 公有的静态方法
    static ShoppingCartManager *getInstance()
    {
        if (_pInstance == nullptr)
        {
            _pInstance = new ShoppingCartManager();
        }
        return _pInstance;
    }

    // 初始化变量(const string &避免不必要的拷贝)
    void addItem(const string &item, int quantity)
    {
        _cart[item] += quantity;
    }

    // 输出包含小明购物车中的所有商品及其购买数量(const不会修改类的成员变量)
    void display() const
    {
        // 范围for
        for (const auto &it : _cart)
        {
            cout << it.first << " " << it.second << endl;
        }
        // 迭代器
        // for (auto it = _cart.begin(); it != _cart.end(); ++it)
        // {
        //     cout << it->first << " " << it->second << endl;
        // }
    }

    // 释放单例实例
    static void destroyInstance()
    {
        if (_pInstance)
        {
            delete _pInstance;
            _pInstance = nullptr;
        }
    }

    // 析构函数
    ~ShoppingCartManager() {}

private:
    map<string, int> _cart;
    // 2. 私有的静态实例变量
    static ShoppingCartManager *_pInstance;
};
// 初始化, 私有的静态实例变量
ShoppingCartManager *ShoppingCartManager::_pInstance = nullptr;

int main()
{
    string item;
    int quantity;
    // 栈内存
    // ShoppingCartManager cart;
    // while (cin >> item >> quantity)
    // {
    //     cart.addItem(item, quantity);
    // }
    // cart.display();
    // 堆内存
    // ShoppingCartManager *cart = new ShoppingCartManager();
    // 通过公有的静态方法来获取类的实例
    ShoppingCartManager *cart = ShoppingCartManager::getInstance();
    while (cin >> item >> quantity)
    {
        cart->addItem(item, quantity);
    }
    cart->display();
    // delete cart;
    ShoppingCartManager::destroyInstance();

    return 0;
}
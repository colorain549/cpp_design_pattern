// 饿汉模式
// * 输出包含小明购物车中的所有商品及其购买数量
// * 使用STL的map
// * 饿汉模式：实例在类加载时就被创建, 这种方式的实现相对简单，但是实例有可能没有使用而造成资源浪费
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
    // 1. 私有的构造函数
private:
    ShoppingCartManager() {}

public:
    // 构造函数
    // ShoppingCartManager() {}

    // 3. 公有的静态方法
    static ShoppingCartManager *getInstance()
    {
        // 直接返回已经创建的实例
        return _pInstance;
    }

    // 初始化变量
    void addItem(const string &item, int quantity)
    {
        _cart[item] += quantity;
    }

    // 输出包含小明购物车中的所有商品及其购买数量
    void display() const
    {
        for (const auto &it : _cart)
        {
            cout << it.first << " " << it.second << endl;
        }
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

private:
    map<string, int> _cart;
    // 2. 私有的静态实例变量
    static ShoppingCartManager *_pInstance;
};
// 初始化, 私有的静态实例变量(饿汉模式：在类加载时直接初始化静态实例变量)
ShoppingCartManager *ShoppingCartManager::_pInstance = new ShoppingCartManager();

int main()
{
    string item;
    int quantity;
    ShoppingCartManager *cart = ShoppingCartManager::getInstance();
    while (cin >> item >> quantity)
    {
        cart->addItem(item, quantity);
    }
    cart->display();
    ShoppingCartManager::destroyInstance();

    return 0;
}
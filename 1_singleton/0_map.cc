// 0. 输出包含小明购物车中的所有商品及其购买数量
// 1. 使用STL的map
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
public:
    // 构造函数
    ShoppingCartManager() {}

    // 初始化变量(const string &避免不必要的拷贝)
    void addItem(const string &item, int quantity)
    {
        _cart[item] += quantity;
    }

    // 输出包含小明购物车中的所有商品及其购买数量(const不会修改类的成员变量)
    void display() const
    {
        // 范围for语句
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

    // 析构函数
    ~ShoppingCartManager() {}

private:
    map<string, int> _cart;
};

int main()
{
    string item;
    int quantity;
    // 栈分配
    // ShoppingCartManager cart;
    // while (cin >> item >> quantity)
    // {
    //     cart.addItem(item, quantity);
    // }
    // cart.display();
    // 堆分配(记得分配内存, 即使用new)
    ShoppingCartManager *cart = new ShoppingCartManager();
    while (cin >> item >> quantity)
    {
        cart->addItem(item, quantity);
    }
    cart->display();
    delete cart;

    return 0;
}
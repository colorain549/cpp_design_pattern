# 设计模式

## 目录
1. 单例模式(懒汉模式)(小明的购物车)
2. 工厂方法模式(积木工厂)
3. 抽象工厂模式(家具工厂)
4. 单例模式(饿汉模式)(小明的购物)
5. 简单工厂模式(积木工厂)

补充:
1. 懒汉模式:第一次使用才创建(多线程可使用互斥锁)
2. 饿汉模式:实例在类加载时就被创建(多线程不影响)(提供接口时直接返回;定义时new一个对象;无需再destory)

## 面向对象
1. 栈分配 自动管理内存 性能快(不涉及动态内存管理)
```
ShopCar shopcar(item, quantity);
```
2. 堆分配 手动管理内存 灵活性(指针可在不同作用域之间传递和共享)
```
ShopCar *shopcar = new ShopCar(item, quantity);
```

## 参考资料
* [卡码网](https://kamacoder.com/designpattern.php)
* [工厂设计模式](https://mp.weixin.qq.com/s/NDIFu6V76_cIo1kWvTM1YQ)

## 单例模式(懒汉模式)(小明的购物车)
1. 构造函数私有化
2. 提供接口(自定义)
```
static ShopCar *getInstance(){
    if(_pInstance==nullptr){
        _pInstance = new ShopCar();
    }
    return _pInstance;
}
```
3. 声明用来保存实例私有静态变量
```
static ShopCar *_pInstance;
```
4. 初始化私有静态变量
```
ShopCar *ShopCar::_pInstance = nullptr;
```
5. 显化默认构造函数
```
ShopCar(){}
```
6. 初始化数据
```
void init(){}
```
7. 删除私有静态变量
```
void destroy(){}
```

## 工厂方法模式(积木工厂)
1. 抽象工厂
```
class Shape {
    public:
    virtual void produceShape() = 0;
};
```
2. 具体工厂
```
class Circle: public Shape {
    public:
    void produceShape() override {}
}
```
3. 抽象工厂
```
class Factory {
    public:
    virtual Shape* factory() = 0;
}
```
4. 具体工厂
```
class CircleFactory: public Factory {
    public:
    Shape* factory() override {
        Shape *pCircleFactory = new Circle();
        return pCircleFactory;
    }
}
```

## 抽象工厂模式(家具工厂)
1. 抽象沙发
```
class Sofa {
    public:
    virtual void produceSofa() = 0;
}
```
2. 具体沙发
```
class ModernSofa: public Sofa {
    public:
    void produceSofa() override {}
}
```
3. 抽象椅子
```
class Chair {
    public:
    virtual void produceChair() = 0;
};
```
4. 具体椅子
```
class ModernChair: public Chair {
    public:
    void produceChair() override {}
}
```
5. 抽象工厂
```
class Factory {
    public:
    virtual Sofa *sofaFactory() = 0; 
    virtual Chair *chairFactory() = 0;
}
```
6. 具体工厂
```
class ModernFactory: public Factory {
    public:
    Sofa *sofaFactory() override {
        Sofa *pModernSofa = new ModernSofa();
        return pModernSofa;
    }
    Chair *chairFactory() override {
        Chair *pModernChair = new ModernChair();
        return pModernChair;
    }
}
```

## 单例模式(饿汉模式)(小明的购物)
1. 构造函数私有化
2. 提供接口(直接返回实例)
```
static ShopCar *getInstance(){
    return _pInstance;
}
```
3. 声明用来保存实例私有静态变量
4. 初始化用来保存实例私有静态变量
```
ShopCar *ShopCar::_pInstance = new ShopCar();
```
5. 显化构造函数
6. 初始化数据
7. 删除私有静态变量

## 简单工厂模式(积木工厂)
1. 抽象积木
2. 具体积木
3. 一个工厂创建所有具体产品(if...else)
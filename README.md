# It includes test files for c++

## compare_between_size_t_and_int
小于0的int值不能和size_t类型进行比较  

## function parameter
### 成员函数形参默认值不能设置为成员变量
> error: call to 'void ParaTest::ParaTestFunc(int)' uses the default argument for parameter 1, which is not yet defined  

解决：函数重载

### 函数形参默认值不能设置为另一个形参的默认值
解决：函数重载  

## move test
###  在有拷贝赋值操作符和移动赋值操作符的情况下，编译器优先考虑move assignment operator

## cin test
### 实现以空格分隔符分隔的字符串的数组读取 
注意`getchar()` 和 `cin` 都是对缓冲区的操作，混用时要分清顺序  

## typeinfo test
### 探究typeinfo存储的位置

## type minus test
### what happens of "(A)-1" 
folly::AtomicHashArray.config lockedKey erasedKey  

## member function test
### 成员函数的调用方式
声明一个A类型的空指针，调用成员函数可以，调用虚函数就会段错误  

## shared ptr test
### shared_ptr 引用计数的变化

## virtual table test
### 虚函数表的内部结构
用指针指向成员函数，第一个字节存放偏移位，第二个字节存放  

## member construct test
### 对象构造与拷贝
不使用初始化列表，编译器会对构造函数中的代码做一些扩张，应该是临时对象的创建和拷贝   
探究NRV优化  




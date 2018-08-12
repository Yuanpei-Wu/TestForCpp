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

## shared ptr test
### shared_ptr 引用计数的变化



#pragma once
#include <iostream>
//extern const int const_int = 123;
//extern const int const_int_ex;

void TestConst() {
	//std::cout <<"TEST: "<< const_int_ex << std::endl;
}

//总结
//有cpp和h的情况下,头文件不能包含定义的变量和函数体,cpp中一包含就会导致重定义错误
//一个互不相包含的两个h,cpp组合,在一个h中可用extern声明一个函数,在另一个组合的cpp中定义函数体
//同理变量也是,但是一定要注意不能在有cpp的情况下在.h中定义

//extern const int const_int = 999;
//extren不能少,否则链接错误:找不到名字
//体现了两点:1.const只在本文件中有效[如果前后有直接的include就不叫本文件,没有include才是独立的文件]
//2.能通过extren关键字连接两个独立文件中的同名const变量,但只能定义一次,可以重复声明,不论定义声明都要加extern关键字

//不过以上都是在最终两个组合都会被main include的情况下得出的

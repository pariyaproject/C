#include "Test_class.h"
//类外部定义成员函数
//请注意定义必须和声明匹配,也包括形参后的const关键字
//同名加上类的域 New_bangumi_data::
New_bangumi_data & New_bangumi_data::Combine(const New_bangumi_data &other)
{
	eps.Combine(other.eps);
	return *this;

}

EPS& EPS::Combine(const EPS& other)
{
	//如果自身Insert 自身 error
	if (this != &other) {
		this->eps_name.insert(this->eps_name.end(), other.eps_name.begin(), other.eps_name.end());
		this->eps_score.insert(this->eps_score.end(), other.eps_score.begin(), other.eps_score.end());
		BroadcastChanged();
	}
	else {
		std::cout << "Can't Combine self!" << std::endl;
	}
	return *this;
}

double New_bangumi_data::AvgScore() const
{
	return eps.Score();
}

EPS EPS::operator+(const EPS & eps1)
{
	EPS new_eps;
	//也可用已经写过的combine来实现
	//vector的insert函数
	new_eps.eps_name.insert(new_eps.eps_name.end(), this->eps_name.begin(), this->eps_name.end());
	new_eps.eps_name.insert(new_eps.eps_name.end(), eps1.eps_name.begin(), eps1.eps_name.end());
	new_eps.eps_score.insert(new_eps.eps_score.end(), this->eps_score.begin(), this->eps_score.end());
	new_eps.eps_score.insert(new_eps.eps_score.end(), eps1.eps_score.begin(), eps1.eps_score.end());
	new_eps.BroadcastChanged();

	return new_eps;
}
//类相关的非成员函数(辅助函数)
//如果函数在概念上属于类但是不定义在类中,则它一般应与类声明(非定义)在同一个头文件中
//即应该在类的同一个头文件中
New_bangumi_data add(const New_bangumi_data&data1, const New_bangumi_data& data2)
{
	New_bangumi_data new_data;
	if (data1.Id() == data2.Id()) {
		new_data.name = data1.Name() + data2.Name();
		new_data.ip_id = data1.Id();
		//这里data1.eps是常量引用 因为 重载的函数中operator+ 没有用const修饰 因此不能隐式转换为非常量
		new_data.eps = const_cast<EPS&>(data1.eps) + data2.eps;
	}
	else {
		new_data = data1;
	}
	return new_data;
}
//以下两个安全性不足 如果Bangumi_data是一个类的话 应当像输入输出流那样使用friend
std::ostream & print(std::ostream & os, const New_bangumi_data &data)
{
	os << data.Name() << "[ " << data.Id() << " ]" << std::endl;
	return os;
}

std::istream & read(std::istream& is, New_bangumi_data& data)
{
	is >>data.name>> data.ip_id;
	return is;
}

std::string TestStatic::Msg(){
	return msg;
}

std::string TestStatic::name = "123";
bool TestStatic::bReady = false;
std::string TestStatic::msg = "222";
int TestStatic::id = 999;
static const int period  = 40;
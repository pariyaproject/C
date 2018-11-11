#include "Test_class.h"
//���ⲿ�����Ա����
//��ע�ⶨ����������ƥ��,Ҳ�����βκ��const�ؼ���
//ͬ����������� New_bangumi_data::
New_bangumi_data & New_bangumi_data::Combine(const New_bangumi_data &other)
{
	eps.Combine(other.eps);
	return *this;
}

EPS& EPS::Combine(const EPS& other)
{
	//�������Insert ���� error
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
	//Ҳ�����Ѿ�д����combine��ʵ��
	//vector��insert����
	new_eps.eps_name.insert(new_eps.eps_name.end(), this->eps_name.begin(), this->eps_name.end());
	new_eps.eps_name.insert(new_eps.eps_name.end(), eps1.eps_name.begin(), eps1.eps_name.end());
	new_eps.eps_score.insert(new_eps.eps_score.end(), this->eps_score.begin(), this->eps_score.end());
	new_eps.eps_score.insert(new_eps.eps_score.end(), eps1.eps_score.begin(), eps1.eps_score.end());
	new_eps.BroadcastChanged();

	return new_eps;
}
//����صķǳ�Ա����(��������)
//��������ڸ����������൫�ǲ�����������,����һ��Ӧ��������(�Ƕ���)��ͬһ��ͷ�ļ���
//��Ӧ�������ͬһ��ͷ�ļ���
New_bangumi_data add(const New_bangumi_data&data1, const New_bangumi_data& data2)
{
	New_bangumi_data new_data;
	if (data1.Id() == data2.Id()) {
		new_data.name = data1.Name() + data2.Name();
		new_data.ip_id = data1.Id();
		//����data1.eps�ǳ������� ��Ϊ ���صĺ�����operator+ û����const���� ��˲�����ʽת��Ϊ�ǳ���
		new_data.eps = const_cast<EPS&>(data1.eps) + data2.eps;
	}
	else {
		new_data = data1;
	}
	return new_data;
}
//����������ȫ�Բ��� ���Bangumi_data��һ����Ļ� Ӧ�����������������ʹ��friend
std::ostream & print(std::ostream & os, const New_bangumi_data &data)
{
	std::cout << data.Name() << "[ " << data.Id() << " ]" << std::endl;
	return os;
}

std::istream & read(std::istream& is, New_bangumi_data& data)
{
	std::cin >>data.name>> data.ip_id;
	return is;
}

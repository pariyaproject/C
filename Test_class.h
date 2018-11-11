#pragma once
#ifndef TEST_CLASS_H
#define TEST_CLASS_H
#include<iostream>
#include<vector>
#include<cassert>
#include<string>
//��Ļ���˼�������ݳ���ͷ�װ
//���ݳ����������ڽӿں�ʵ�ַ���ı�̼���
//���ȶ���һ��������������(ͨ���ӿ���ʹ��)
//��һ���򵥵�struct����һ��������������,�������û�ֱ�ӷ����������ݳ�Ա
//Ҫ�������ɳ�����������,��Ҫ����һЩ�����Թ�����û�ʹ��,һ�����������Լ��Ĳ���,����
//�Ϳ��Է�װ(�����������ݳ�Ա��)

//��Ա��������������������ڲ�,���Ķ�����������ڲ������ⲿ
//����Ϊ�ӿ���ɲ��ֵķǳ�Ա���� �� read print,���ǵĶ�������������ⲿ
class Test_class
{
public:
protected:
private:
};
//���ڴ洢���Ľṹ��
struct EPS {
	//���캯��
	//��ʼ�����������ݳ�Ա,���ۺ�ʱֻҪ��Ķ��󱻴���,�ͻ�ִ�й��캯��
	//���ֺ�������ͬ,û�з�������,�����ж��(�൱������)
	//���캯�����ܱ�����Ϊconst
	//���������һ��const����ʱ,ֱ�����캯����ɳ�ʼ������,�����������ȡ���䳣��������
	//���,���캯����const����Ĺ�������п�������дֵ [ʵ��ֱ�Ӹ�ֵ����,���岻��]
	//Ĭ�Ϲ��캯�� �����κ�ʵ��,������ʽ���ṩ Ҳ����ʾ��д
	//�����������Ĺ��캯���ֱ���Ϊ�ϳɵ�Ĭ�Ϲ��캯��
	//���������¹����ʼ��������ݳ�Ա
	//1.����������ڵĳ�ʼֵ ��������ʼ����Ա
	//2.����Ĭ�ϳ�ʼ���ó�Ա
	//[ע�� ֻ�е���û�������κι��캯��ʱ,����������ϳ�Ĭ�Ϲ��캯��]
	//�����������ͻ�򸴺����ͳ�Ա����Ӧ��������ڲ���ʼ��
	//ֻ�е����ڵ����þ�Ӣȫ�����������ڳ�ʼֵ,�������ʺ�ʹ��Ĭ�ϵĹ��캯��
	//��Щʱ��������޷�����Ĭ�ϵĹ��캯��,����һ��û���ṩĬ�Ϲ��캯������ʱ
	//EPS() = default; ����������캯����Ϊ�˼���Ĭ��Ҳ���Զ���Ĺ��캯��,������ɵ�ͬ�ںϳ�Ĭ�Ϲ��캯��
	//c++11�� �����ҪĬ�ϵ���Ϊ,��ô����ͨ���ڲ����б����д�� =default ��Ҫ����������ɹ��캯��
	//����������һ��,������ڲ�����,��Ĭ�Ϲ��캯����������,���ⲿĬ�ϲ���������
	EPS() { avg_score = 0.0; eps_score = {}; eps_name = {};}
	//���캯����ʼֵ�б�
	//����Ϊ�´����Ķ����һ���򼸸����ݳ�Ա����ֵ
	//��ĳ�����ݳ�Ա����ʼ��ʼֵ�б����ʱ �����Ժϳ�Ĭ�Ϲ��캯����ͬ�ķ�ʽ��ʽ��ʼ��
	//������ⲿ���幹�캯��
	EPS(std::vector<std::string> na, std::vector<double> sc) 
		:eps_name(na),eps_score(sc)
	{
		BroadcastChanged();
	}
	double avg_score;
	std::vector<double> eps_score;
	std::vector<std::string> eps_name;
	//����һ��������const��Ա  �ͻ�����һ������  ���뿽�����캯���й�
	//error C2280 : ��EPS &EPS::operator =(const EPS &)�� : ����������ɾ���ĺ���
	//test_class.h(97): note: ���������ڴ˴����ɡ�EPS::operator =��
	//const std::string From = "China";
	//const int password = 999;

	double Score() const { return avg_score; }
	//�����ı�
	void BroadcastChanged() {
		CalScore();
	}
	void CalScore() {
		double all_score = 0.0;
		for (auto i : eps_score) {
			all_score += i;
		}
		avg_score = all_score / eps_score.size();
#ifndef NDEBUG
		std::cout << "######\navg_score: "
			<< avg_score
			<< "\n######\n"
			<< std::endl;
#endif
	}
	EPS& Combine(const EPS& other);
	void Add(std::string name, double score) {
		eps_name.push_back(name);
		eps_score.push_back(score);
		BroadcastChanged();
	};
	//�Ƴ����һ��Ԫ��
	void Remove() {
		//
		eps_name.erase(eps_name.cend() - 1);
		eps_score.erase(eps_score.cend() - 1);
		BroadcastChanged();
	};
	//�Ƴ�ָ����Ԫ��
	void Remove(std::string name) {
		//�����ҵ�λ��
		auto site = std::find(cbegin(eps_name), cend(eps_name), name);
		//����λ���ҵ��±�
		int index = static_cast<int>(std::distance(site, cbegin(eps_name)));
		//�Ƴ���Ӧ�±�
		eps_name.erase(eps_name.cbegin() + index);
		eps_score.erase(eps_score.cbegin() + index);
		BroadcastChanged();
	};
	//�������������
	//�ڶ����п��ܳ���: ����<string>ͷ�ļ�
	friend std::ostream& operator << (std::ostream&, const EPS&);
	friend std::istream& operator >> (std::istream&, EPS&);
	//����+
	EPS operator + (const EPS &eps1);
};
//ע�� ����һ�������ʱ ������Ҫ����ټ���std::endl
inline std::ostream & operator<<(std::ostream &os, const EPS &eps)
{
	assert(eps.eps_name.size() == eps.eps_score.size());
	auto num = eps.eps_name.size();
	if (num == 0) {
		std::cout << "No eps" ;
	}
	else {
		if(num >1)
		for (decltype(num) i = 0; i < num-1; ++i) {
			std::cout << "EPS: "
				<< eps.eps_name[i]
				<< "  SCORE: "
				<< eps.eps_score[i]
				<< std::endl;
		}
		//���һ�����������
		if (true) {
			std::cout << "EPS: "
				<< eps.eps_name[num-1]
				<< "  SCORE: "
				<< eps.eps_score[num-1];
				//<< std::endl;
		}
	}


	return os;
}

inline std::istream & operator >> (std::istream &is, EPS &eps)
{
	std::string nname;
	double nscore;
	bool has_enter = false;
	while (!has_enter) {
		if (std::cin >> nname >> nscore) {

			has_enter = true;
			eps.Add(nname, nscore);
			std::cout << "EPS: "
				<< nname
				<< "  SCORE: "
				<< nscore
				<< "  Get!"
				<< std::endl;
		}
		else {
			std::cout << "Bad Input" << std::endl;
		}
	}

	return is;
}
//�Ľ���Bangumi_data
//���������ڲ��ĺ�������ʽ��inline����
//������������������: ���ȱ����Ա������,Ȼ����ֵ���Ա������,��˳�Ա�������������ʹ�����е�
//������Ա�����������Ա���ֵĴ���
struct New_bangumi_data {
	//const��Ա���� ������Ա����
	//������β��ʹ����const�ؼ���:�޸���ʽthisָ�������
	//Ĭ���� this��������ָ�������ͷǳ��汾�ĳ���ָ��(New_bangumi_data * const)
	//��ᵼ��һ��������New_bangumi_data���ܵ���һ����ͨ��Ա����(const���ܸ����ǳ���)
	//ʹ��const�� ������������,ͬʱ�ں�����Ҳ�����޸�������� ����������
	std::string Name() const { return name; } //����������
	unsigned Id() const { return ip_id; }
	New_bangumi_data &Combine(const New_bangumi_data&);
	double AvgScore()const;

	std::string name;
	unsigned ip_id;
	double score;
	EPS eps;
};
//�ǳ�Ա�ӿں���
New_bangumi_data add(const New_bangumi_data&, const New_bangumi_data&);
//ע��IO�������ڲ��ܱ���������,���ֻ��ͨ�����ô���
std::ostream &print(std::ostream& os, const New_bangumi_data&);
std::istream &read(std::istream&, New_bangumi_data&);

//��Ա����ͨ��һ����Ϊthis�Ķ������ʽ���������������Ǹ�����.
//�����ǵ���һ����Ա����ʱ,������ú����Ķ����ַ��ʼ��this,
//����: test.Id();
//�����������total�ĵ�ַ���ݸ�Id����ʽ�β�this,���Եȼ۵���Ϊ���������õ�����д����
//New_bangumi_data::Id(&test);//����α����
//�ڳ�Ա�������ڲ�,����ֱ��ʹ�õ��øú����Ķ���ĳ�Ա,������ͨ����Ա���������,��Ϊthis��ָ��
//�����������,�κζ����Ա��ֱ�ӷ��ʶ�������this����ʽ����
//����κ��Զ�����Ϊthis�Ĳ������������Ϊ���ǷǷ���
//this��һ������ָ�� ����ָ���������


#endif

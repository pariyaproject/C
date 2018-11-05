#ifndef BANGUMI_SUBJECT_H
#define BANGUMI_SUBJECT_H
//pragma once�ȼ���ifndef ... endif,��ifndef��c++��׼��֧�ָ���ı�����
//������������ͻ��Σ�ղ��ұ�����Խ���
//#pragma once
//����iostream�Ѿ����������������������ֹ�ظ�����
#include <iostream>
//bangumi��Ŀ��
class Bangumi_subject
{
public:
	//const �����޶�����
	//1.�����޸����ݳ�Ա 2.���ܵ��÷�const��Ա���� 3.mutable���εĳ�Ա�ǿ����޸ĵ�
	//�������������
	//mutable�������κ���
	int Id()const;
	int DoNum()const;
	int Score()const;
	Bangumi_subject();
	Bangumi_subject(int,int,int);
	//ע����Ҫ����Ϊ��Ԫ����
	//<<>>��������������ǩ����һ��
	//��Ԫ�������Է������е��������ݳ�Ա
	//ע�⣺inlineһ��Ҫ�ڱ��ļ���ʹ�ò���h cpp��ʹ��
	//���õ�>>ģ������ʱ������ʵ�ֶ�ʹ��һ����ͬ��ģ��
	friend std::ostream& operator <<(std::ostream& ,const Bangumi_subject &);
	friend std::istream& operator >>(std::istream&,Bangumi_subject &);
	//ǰ��++û�в������֣��˴��ܷ���ǰ��++������һ�����ã�Ч�ʸ���
	Bangumi_subject& operator ++();
	//����++��Ҫ��һ����������
	Bangumi_subject operator++(int);
	//tip:
	//�β��е� Bangumi_subject* �� Bangumi_subject& ������
	//*�е���Ϊ func(&subject)ʵ�ʴ���һ�����е�ַ�ı����������˵�ַ�Ŀռ�(���룬����)
	//&�е���Ϊ func(subject)ֱ��ʹ�ñ������Ǳ���
	Bangumi_subject operator+(const Bangumi_subject&);
	Bangumi_subject &operator+=(const Bangumi_subject&);
private:
	int id;
	int score;
	mutable int do_num;
	
};

inline std::ostream & operator<<(std::ostream &out, const Bangumi_subject &subject)
{
	out << "Bangumi ID : " << subject.id
		<< "\nBangumi Score : " << subject.score
		<< "\nBangumi Do : " << subject.do_num;

	return out;
}

inline std::istream & operator >> (std::istream &in, Bangumi_subject &subject)
{
	if (in >> subject.id >> subject.score >> subject.do_num) {
		
	}
	else {
		subject.id = 0;
		subject.score = 0;
		subject.do_num = 1;
	}

	return in;
}







#endif
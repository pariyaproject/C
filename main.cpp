#include <iostream>
//�������Ա�׼���ͷ�ļ�ʱʹ��<>����""
//class
#include "bangumi_subject.h"

//�������
void cin_cout_cerr_clog() {
	//cerr clog �� cout ���������ͬһ������
	std::cerr << "err" << std::endl;
	std::clog << "log" << std::endl;
	std::cout << "cout" << std::endl;
	//std::endl����һ�ǽ�����ǰ�У����ö�������������ˢ���豸��
	//�����������ڴ��еȴ���������������ؼ�����������ڴ��дӶ������ƶϴ���ط�
}
//ע������
void note_err() {
	std::cout << "/*";
	std::cout << "*/";
	//����
	//std::cout << /*"*/"*/;
	std::cout << /*"*/" /* "/*"*/;
}
//������forѭ��
void undefine_num_for() {
	int num = 0;
	//��ʹ��һ��istream������Ϊ����ʱ��ʵ���Ǽ�����Ƿ�����Ч��
	//��Ϊistream���󷵻������������
	//����Ч������δ�������󣬵������ļ�������(EOF)or��Ч���루���Ͳ���������Ϊ����������Ϊ��Ч����
	while (std::cin >> num) {
		std::cout << "you have cin : " << num << std::endl;
	}
	//EOF win:ctrl+z unix:ctrl+d
}
//��Ĵ���ʹ��
void use_bangumi_class() {
	//.��������ֻ���������͵Ķ�������ָ��
	//ָ��ʹ��->
	Bangumi_subject my_subject;
	Bangumi_subject my_subject1(123, 9, 5);
	Bangumi_subject my_subject2(123, 8, 3);
	Bangumi_subject my_subject3(0,0,1000);

	std::cin >> my_subject;
	std::cout <<"current subject:\n"<< my_subject << std::endl;
	std::cout <<"++subject\n"<< ++my_subject << std::endl;
	std::cout <<"subject++\n"<< my_subject++ << std::endl;
	std::cout <<"subject+subject:\n"<< my_subject1 + my_subject2 << std::endl;
	my_subject += my_subject3;
	std::cout << "subject+=:\n" << my_subject << std::endl;
		
}
int main() {
	//�������
	//cin_cout_cerr_clog();
	///*/*xx*/xxxx*/�ᱨ��
	//����ԭ����/**/����Ƕ��
	//ע������
	//note_err();
	//������forѭ��
	//undefine_num_for();
	//��Ĵ���ʹ��
	//use_bangumi_class();

	system("pause");
	return 0;
}

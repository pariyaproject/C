#include <iostream>

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

int main() {
	//�������
	//cin_cout_cerr_clog();
	///*/*xx*/xxxx*/�ᱨ��
	//����ԭ����/**/����Ƕ��
	//ע������
	note_err();


	system("pause");
}

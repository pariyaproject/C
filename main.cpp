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
//c++��һ�־�̬������������ ������php������ʱ������ݱ���������
//32λϵͳ��һ����(word)��32bit��4���ֽ�(bytes)
//->32λ��2^32(�ֽ�)bytesѰַ�ռ�4*2^10*2^10*2^10=4G
//char != signed char (0~255)�ɱ��������� [unsigned char(-128~127)]
//->��Ϊ����ԭ��Ҫʹ��char������ ������Ϊ��(un)signed���ε�
//long һ��� int ��һ���ĳߴ� longlong����
//�������Ǹ� ����unsigned����(���ڵ���0) ֻ��unsigned��Ĭ��unsigned int
//��һ���޷��ŵ�����ֵ����Χ�������ȡģ���������� �� unsigned char x=-1 (ʵ��255)
//��һ���з��ŵ�����ֵ����Χ���������δ����
//�ַ���("")���ַ�('')��һ�����ַ�('\0')���������崮������ո����������еĻ�
//��ʵ��������һ�����塰x�� ��y��=="xy"
//ָ������ֵ����
//->L'a' ���ַ�����ֵ ������wchar_t [�ַ�����ǰ׺]
//->u8"hi!" utf-8�ַ�������ֵ  [���ֵ��Ǻ�׺]
//->nullptr��ָ������ֵ
//C++11������: int units_sold{0} ʹ�û����ų�ʼ������(�б��ʼ��)
//->[�������͵ı������ܵ���Ϣ��ʧʱ���뱨��]
//Ĭ�ϳ�ʼ��������������ֵ�ɶ����λ�þ������������κκ�������ĵı�����ʼ��Ϊ0
//->�����ں������ڵı���������ʼ��(δ����)
//�����Ͷ���
//->����ʱ����Ҳ����(����ռ䣬����ʼ)��������������������extern�ؼ��ֲ���ʾ�س�ʼ������
//->���磺extern int i;  �������Ƕ���
//->int j;  ����������
//->extern double pi = 3.1416;  ����
//->�ں������ڲ�(��ȻҲ��main)����ʼ��һ��extern��ǵı��������
void test_extern() {
	//extern double pi = 3.1416;
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
	//extern double p;
	p = 3.1416;
	system("pause");
	return 0;
}

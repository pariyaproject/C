#include <iostream>
#include <string>
#include <cctype>
#include <vector>
//�������Ա�׼���ͷ�ļ�ʱʹ��<>����""
//class
#include "bangumi_subject.h"
//extern const int x ;
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
	Bangumi_subject my_subject3(0, 0, 1000);

	std::cin >> my_subject;
	std::cout << "current subject:\n" << my_subject << std::endl;
	std::cout << "++subject\n" << ++my_subject << std::endl;
	std::cout << "subject++\n" << my_subject++ << std::endl;
	std::cout << "subject+subject:\n" << my_subject1 + my_subject2 << std::endl;
	my_subject += my_subject3;
	std::cout << "subject+=:\n" << my_subject << std::endl;

}
//c++��һ�־�̬������������ ������php������ʱ������ݱ���������
//->��̬�������ԣ��ڱ���׶μ������(���ͼ��)
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
//->�ں������ڲ�(��ȻҲ��main)����ʼ��һ��extern��ǵı������
//����=ʹ������Ϊ������֪��һ���ļ������ʹ�ñ𴦶�������������������Ǹ����ֵ������������帺�𴴽������ֹ�����ʵ�塣 
//���������涨�˱��������ͺ����֣�����һ���϶�����֮��ͬ�����ǳ���֮�⣬���廹����洢�ռ䣬Ҳ���ܻ�Ϊ������һ����ʼֵ��
//���п��ܸ��˳�ʼֵ(��ʾ����ʽ)��ָ�Զ������͵��ù��캯�������û������Ϳ��������ڵ���
void test_extern() {
	//extern double pi = 3.1416;
}
//����ֻ�ܱ�����һ�Σ����Զ������
//->���Ҫ�ڶ���ļ���ʹ��ͬһ�����ͱ��뽫�����Ͷ�����룬�����Ķ�������������ֻ�ܳ�����һ���ļ���
//->�������õ��ñ������ļ������������������������ظ�����
//���������÷��(�������ͨ��)
//->�û��Զ���ı�ʶ���в����������������»��ߣ�Ҳ�����»��߽�����д��ĸ��ͷ
//->�����ں�������ı�ʶ���������»��߿�
//int _abc;
//void test_identifier() {
//	int __c;
//	int _X;
//  int _;
//}
//scope(������)c++�д���������Ի����ŷָ�����ͬ�������������ͬ�����ֵ���ͬ��ʵ��
//->���ֵ���Ч����ʼ�����ֵ�������䣬������������ڵ�������ĩ��Ϊ����
void test_scope() {
	int sum = 0;
	for (int val = 0; val < 11; ++val) {
		sum += val;
	}
}
//test_scope���������л�����֮��(ȫ��������)
//->sum������test_scope�����޶���������֮�ڣ����˺�������޷�����(��������)
//->val������for����ڣ�ֻ����for�з���
//�ֲ�ͬ�������Ḳ��ȫ�ֱ���
//->��ʾ����ȫ��������ʱʹ��::sum
//��������
//c++11����"��ֵ����"һ�㡰���á���ָ"��ֵ����"
//������� = �������� ������;
//����Ϊ������������һ������
//->������ &d ��������������
void test_refers() {
	int val = 12;
	int &refval = val;
	std::cout << refval << val++ << std::endl;
	std::cout << refval;

	//int &refval1; //����: ���ñ��뱻��ʼ��
	//һ���ڳ�ʼ������ʱ����ʼֵ�ᱻ�������½��Ķ�����
	//����������ʱ�����������ú����ĳ�ʼֵ����(bind)һ��
	//ע�⣺���Ժ��޷����°�����һ��������˱����ʼ�������ܰ�һ������ֵ��ͬ���͵ı���
	//���ò���һ������(û��һ��ʵ�ʵ������ַ)��ֻ��һ�������������޷��������õ�����
}
//ָ�뱾����һ����������ֵ����������ʱ���踳��ֵ����Ŷ���ĵ�ַ
//->���������ñ���һ�����ڿ��������ڶ����ָ�����û�г�ʼ������ӵ��һ����ȷ����ֵ
//������ *d
void test_pointer() {
	//int *ip1, *ip2; //��ȷ����ֵ
	//��ȡ����ĵ�ַ
	int val = 42;
	int *p = &val;
	//��Ȼ���ܽ���ͬ���͵Ķ���ֵ
	//ͨ��ָ�����һ������ʹ�ý����÷�*
	*p = 123;
	std::cout << *p;
	//ʹ��һ��ָ��ǰ����ü��ָ�����Ч��(��)
	//���ɿ�ָ��ķ���
	int *p1 = nullptr; //�ȼ�*p1 = 0; �Ƽ�ʹ��
	int *p2 = 0;//ֱ�ӳ�ʼ��Ϊ���泣��0
	int *p3 = NULL;//�ȼ�*p3 = 0;
	//���ܸ�ָ�븳ֵһ������
	//int x = 0;
	//int *p4 = x;
	//�κη�0ָ�������ֵ����true
	//void* ָ����Դ���������ĵ�ַ
	double obj = .14, *pd = &obj;
	void *pv = pd;
	pv = &obj;
	//���ڲ�֪void*ָ������ͣ���֪���͵Ļ�������������
	std::cout << *(double*)pv;
	//std::cout << *pv; //����
	//�༶ָ��
	//ָ��ָ�������
	int *x = 0;
	//int &*r = x; //������ʹ��ָ�����õ�ָ��
	//���������
	//����������������(��)��Ӱ�� &*r=&(*r) r��һ��ָ�� ���ò��Ǳ��� *r�ɿ���һ�����壬rָ��������壬�����������һ������
	int *&r = x; //*&r=*(&r) r��һ������ r��������һ��ָ��
}
//const�޶��� �����ʼ��
void test_const() {
	//const int i = sizeof(int); 
	//���г�ʼ��(��������ֵ) ע������sizeof��һ���ؼ���
	const int j = 45; //����ʱ��ʼ��
	//const int k; //���� �����ʼ��
	int c = 123;
	const int a = c;
	int d = a;
	//���Ա���ʱ��ʼ���ķ�ʽ����һ��const ����ʱ�����������ڱ��������ֱ�ӽ������滻������ֵ
	//Ĭ��״̬�� const��������ļ�����Ч�����ļ���������const����
	//�б�Ҫ���ļ��乲��ʱ(��ǳ���һ������)Ӧ����const���������������Ƕ��嶼���extern�ؼ���
	//��const������
	const int ci = 1024;
	const int &rl = ci; //ע������ const int

	//�������ͱ���Ͷ��������һ�µ�����
	//��ʼ����������������������ʽ��Ϊ��ʼֵ��ֻҪ���ʽ�Ľ����ת�������õ�����
	//ԭ���ǳ��������ǲ������ֵ�ģ����ͨ����ʱ�����г�ʼ��
	//���ǳ������ܻ����ԭ�ڴ�ֵ��ͨ��һ������ת������ʱ�����޷��ı�ģ���˷Ƿ�
	int i = 42;
	const int &r1 = i;  //int ��ת����const int
	const int &r2 = 45;  //����ֵ ��ת����const int
	const int &r3 = r1 * 2;  //��ת����const int
	//int &r4 = r1 * 2; //���� r4��һ����ͨ�ķǳ�������
	//r1 = 5;//���� r1��һ����������(��const������)
	//ָ���const����������
	const double xpi = 3.14;
	//double *ptr = &xpi; //����
	const double *ptrc = &xpi;
	//*ptrc = 42.0; //����
	//����
	double val = 3.14;
	ptrc = &val; //ͨ�� ������ͨ��ptrc�ı�val��ֵ

	//constָ�� �����ʼ�� �������ָ�뱾���ֵ����ָ����Ǹ�ֵ
	int errNumb = 0;
	int *const curErr = &errNumb;
	const double pi = 3.1415;
	const double *const piptr = &pi;
	//����const ������const
	//�ײ�const ��ָ�Ķ�����const

}
//������
void const_test_others() {
	//�������ʽ constexpr����
	//����Ϊconstexpr�ı���һ����һ�������������ó������ʽ(������̾��ܵõ����)��ʼ��
	constexpr int size = sizeof(int);
	//�������ʽ
	std::cout << size;
	//constexpr�������Ƶ�(����ֵ����) �Զ����� IO�� string���Ͳ���������ֵ����
	//���������к�����֮��Ķ������ַ�̶����䣬��������ʼ��constexprָ��
	const int *cpp = nullptr; //ָ������ָ��
	constexpr int *cpp2 = nullptr; //ָ��int�ĳ���ָ��
	constexpr const int *cpp3 = nullptr; //ָ�����ĳ���ָ��
}
//���ͱ���
void test_type() {
	//�������ͱ��� ��ͳ����
	typedef double wages;
	typedef wages base, *f; //f�� double*��ͬ���
	const f double_f = 0;//double_f��ָ��double�ĳ���ָ��
	//��ʱ�Ĺ�����ϵ����ǰ�Ĳ�ͬ f�����Ѿ���ָ���� const f �Ѿ��ǻ������������� double_f ����������
	//c++ 11�µķ��� �������� ע�����������ʹ��
	using B_S = Bangumi_subject; //B_S�����ͬ���
	using ptr_int = int *;

	//auto����˵���� c++ 11
	//auto�ñ�����ͨ����ʼֵ��������������ͣ�auto����ı��������г�ʼֵ
	double val1 = 1.5;
	int val2 = 5;
	auto item = val1 + val2; //double���� 
	B_S subject_1(0, 0, 2);
	auto subject_item = subject_1 + subject_1;//autoҲ������һ����B_S
	std::cout << sizeof(item) << "  " << item << std::endl;
	std::cout << sizeof(subject_item) << "  " << subject_item << std::endl;
	//��Ȼ��auto��֧�� ���Բ��ܸı�c++��ǿ�������Ե���ʵ
	//auto����һ�ζ����������������ֱ�����ͬһ������
	//auto sz = 0, pi = 3.14; //error
	//auto����Զ���const ������ʾ���� const auto
	//decltype����ָʾ�� c++ 11
	//������ϣ����֪���� ��������Ҫ����ֵ��ʼ��
	//���ز���������������
	//decltype(f()) sum = x; //sum�������Ǻ���f�ķ�������
	//���ʹ�õ��Ǳ�������decltype���ظñ���������(��������const����������) ֱ���൱���滻
	//����Ǳ��ʽ ���з��������� Ӧ������Ϊ��ֵ
	//int iii = 45, *ppp = &iii, &rrr = iii;
	//decltype(rrr + 0) bbdsfsa; //r+0 =>int
	//decltype(*ppp) dfadadf; //���� c ��Int& ���� �����ʼ�� 
	//int i;
	//decltype ((i)) d; //d��int & ���� û��ʼ�� ()�����Ǳ��ʽ���� ����ֱ�Ӵ������������
	//˫��������Զ������ ����ֻ�е��������������ò�������
	//decltype (i) d; //d��int 
}
//�ṹ��
struct Bangumi_data {
	//Bangumi_data() {}
	//Bangumi_data(unsigned i,std::string n):id(i),name(n){}
	//unsigned id = 0;
	unsigned id;
	std::string name;
	friend std::ostream& operator<< (std::ostream &os, const Bangumi_data& bd) {
		std::cout << "name: " << bd.name << "\nid: " << bd.id << std::endl;
		return os;
	}
}test_struct_0;//���������; ��Ϊ�������Խ���������
void test_struct() {
	using B_D = Bangumi_data; //����ֱ�Ӽ�������ǰ ���Ͳ��ܽ���������
	B_D test_struct_1;
	Bangumi_data test_struct_2;
	//c++ 11
	//����Ϊ�������ݳ�Ա�ṩһ�����ڳ�ʼֵ
	//ע�����ڳ�ʼֵ ���ڻ��������Ⱥ��� ����ʹ��Բ����
	Bangumi_data test_struct_3{ 1,"" }; //ע���ʱ���ﱨ��ֻ�е�����ʱû��Ĭ��ʱ����ȷ ��unsigned id;��
	Bangumi_data test_struct_4 = { 1,"" };//ע���ʱ���ﱨ��ֻ�е�����ʱû��Ĭ��ʱ����ȷ ��unsigned id;��
}
//ȷ����ΰ���ͷ�ļ�Ҳ�ܰ�ȫ�����ļ�����Ԥ������
//Ԥ������ #include ��ָ����ͷ�ļ�����
//Ԥ�������������״̬ �Ѷ����δ���� #define 
//string��vector��������Ҫ�ı�׼������
//ǰ��֧�ֿɱ䳤���ַ���������֧�ֿɱ䳤�ļ���
//����������һ�ָ����������ͣ�string��vector���Ƕ�����ĳ�ֳ���
//�����ռ�using����
void test_using() {
	//cout << "ddd";//����: Ӧ��λ��using֮��
	using std::cout;
	cout << "yes";
	using std::cin; using std::endl;
	//usingҲ����������������������Ч,�������������֮��
}
//ͷ�ļ���Ӧ����using����,������������ͷ�ļ����ļ��������������
//��׼��string

void test_string() {
	using std::string;
	using std::cout;
	using std::cin;
	using std::endl;
	//string�ĳ�ʼ������
	string s1; //���ַ�
	string s2 = s1; //(������ʼ��)s1�ĸ��� �ȼ��� (ֱ�ӳ�ʼ��)string s2(s1);
	string s3 = "hiya"; //����ֵ ������ֵ�������Ŀ��ַ�'\0'�������е��ַ�������
	//Ҳ����˵string�������û���ַ�������ֵ������'\0'
	//->�ȼ� s3("hiya")
	string s4(10, 'c'); //s4�������� cccccccccc
	//s4��Ӧ�Ŀ�����ʼ�� string s4=string(10, 'c');
	//��ʼ���ķ�ʽ
	//���ʹ�õȺ� = ��ʼ�����ǿ�����ʼ��
	//�����ʹ�õȺ� = ���� ֱ�ӳ�ʼ��
	//>>�������Կհ��ַ��ָ� 
	//ע��ʹ��getlineһ��Ҫ����<string> ����ʹ��string�ɲ���
	//getline��cinһ���᷵�������� ���� while(getline(std::cin,s1));
	getline(std::cin, s1);//����������ȡһ�и�ֵ��s1 ���cin>>s1ֻ���Կհ��ַ�,���������ɲ��洢(���ж����־����)
	//���һ��ʼ���ǻ��з���ô������һ�����ַ�
	//s1 = { '\0' };
	if (!s1.empty())//ע�� �ո� \0����һ�����ַ�()
		cout << "getline=" + s1 + "=end" << endl;
	//����cin>>s1�Ͳ����Ի��з�����,Ҳ����˵cin>>�����ܳ���һ�����ַ�,����¼��һ���ǿհ��ַ��Ż�������������
	cin >> s1;
	cout << s1 << endl;
	cout << s1.empty() << endl;
	//"xxx"����һ��C�����ַ��� ����\0Ϊĩβʶ���
	//string ��һ������ Ҳ�г��ȼ�¼ ��ȫ���Բ���\0��ȷ������(ʲôʱ�����)
	string test1("123\0");//"123\0"���Ѿ�ȷ������ '1''2''3'�����ַ��ĸ�ֵ
	string test2("123");
	string test3(4, '\0');//string���󲻻Ὣ\0������Ϊ\0������ǿ��ַ��ĺ���
	string test4{ '1','2','3','\0' };
	//size()���ص���string::size_type����(�޷������͵�ֵ)��˲�Ӧ����int(������unsigned)
	//auto len = s1.size();
	//string::size_type x;
	cout << s1.size() << endl;
	cout << test1 << " " << test1.size() << endl;//size����string���ַ��ĸ���
	cout << test2 << " " << test2.size() << endl;
	cout << test3 << " " << test3.size() << endl;
	cout << test4 << " " << test4.size() << endl;
	//����ʹ�� c_str() data()��string����ת��Ϊconst char *ʱ���һ���ַ���'\0'
	string blan;
	cout << "�հ�=" << blan[blan.size()] << "=ddd" << endl;
	cout << "�հ�=" << test1[test1.size()] << "=ddd" << endl;//0-size()-1�Ǵ洢��Ч�ַ�
	//����ͼ����size()λʱ��̶�����'\0'
	//reference:https://segmentfault.com/q/1010000005141633
	//==���s1 s2�������ַ���ȫһ�������(��Сд����)
	//>= <= �������ֵ��е�˳��Ա� 
	string a("a");
	string b("b");
	cout << (a >= b) << endl;// a<b �������� 
	//string("a")<string("aa")
	//�������string���Ȳ�ͬ,���ҽ϶̵�string��ÿ���ַ�����ϳ��Ķ�Ӧλ����ͬ,��϶̵�<�ϳ���
	//����Ƚϵ��ַ���ĳЩλ�ò�ͬ,����ǵ�һ�Բ�ͬ���ַ����ֵ�˳��
	//string �������ʹ��+ ������һ���µ�string����(�����ַ�ƴ��)
	//���Ǳ���������һ��������string(���ұ����Ƚ���string������ֵ������)�������ַ�������ֵ: "123"+"dd"
	string("123") + "123" + "222";
	//"123" + "   " + string("ddd");//�Ƿ���������ֱֵ����ӵĹ���
	//λ�� <cctype>
	isalnum('s');//����ĸ������ʱΪ��
	//isalpha > ��ĸ
	//iscntrl > �����ַ�
	//isdigit > ����
	//islower > Сд��ĸ
	//isprint > �ɴ�ӡ
	//ispunct > ������
	//tolower > ���Сд ע�ⷵ�ص���int����
	//toupper > �����д ע�ⷵ�ص���int����

	//���ڷ�Χ��for  range for
	//for (declaration : expression) �����������е�ÿ��Ԫ��
	//ÿ�ε���declaration�ᱻ��ʼ��Ϊexpression���ֵ���һ��Ԫ��ֵ
	//��Ϊstring��ʾһ���ַ�������
	string test_range_for("aabbcc dd");
	for (auto &each : test_range_for) {//�����Ҫ�ı�ֵ ��ʹ������
		//cout << static_cast<char>(toupper(each)) << endl;
		each = static_cast<char>(toupper(each));
	}
	cout << test_range_for << endl;
	//�±������[] ���ܵĲ�����string::size_type ����ֵ�Ǵ�λ���ַ�������
	//&& �߼�������� c++��ֻ����������Ϊ��Ż����Ҳ���������
}
//vector ����
void test_vector() {
	using std::string;
	using std::endl;
	using std::cout;
	//vector��ʾ����ļ���,�������ж�������Ͷ���ͬ 
	//ʹ��vector������� <vector>
	//vectorҲλ��std�����ռ� vector��һ����ģ�� ��Ҫ�ṩ�������Ϣ(����)
	//����������ģ�崴��������Ĺ��̳�Ϊʵ����
	using std::vector;
	vector<int> ivec; //<int>���ṩ�Ķ�����Ϣ //��vector ִ��Ĭ�ϳ�ʼ��
	vector<Bangumi_data> bdvec;
	vector<vector<string>> strvv;//vector����Ƕ�� ���ƶ�ά������
	//vector<int&>d; ����
	//��ע�� ���ò���һ������ ���ܷ���vector��
	//c++�ɰ汾Ƕ��vector���vector������Ҽ����ź�Ԫ������֮��Ҫ��һ���ո� vector<vector<int> >
	//c++ 11 ����ո�
	//��ʼ��vector
	vector<int> ivec2(ivec); //ֱ�ӳ�ʼ�� ivec�ĸ���
	vector<int> ivec3 = ivec; //��ֵ��ʼ�� �ȼ���һ��(ivec)
	vector<int> ivec4(10, 1); //������10��ֵΪ1��int
	//vector<int> ivec44 = (10, 1); //���� 
	vector<int> ivec5(11); //������11��ִ����Ĭ�ϳ�ʼ����int
	vector<int> ivec6{ 1,2 }; //����Ԫ�� �ֱ���1 2
	//c++11 �ṩ���б��ʼ�� vector
	vector<int> ivec7 = { 1,2 };//���Կ��� vector<int> ivec6={int(1),int(2)}
	vector<string> strvec = { "dd","ddd" };
	//vector<Bangumi_data> bdvec2 = { {1,""},{2,"ddd"} }; //���Գ�ʼ���б���ʹ�ó�ʼ���б�
	vector<Bangumi_data> bdvec2 = { { 1,"" },{2,"ddd"} };//��ͬ���� ��ʹû����صĹ��캯�����ɿ���ֱ��ʹ��{}��ʼ��
	Bangumi_subject test_bs1 = { 1,2,3 }; //��Ҳ��ʹ�ó�ʼ���б����ʽ,��ʵ�����ǵ�������صĹ��췽��
	//->����֮ǰ���ᵽ��ʹ��{}�б��ʼ�������������,���Ա�ᱨ�� 
	cout << "BangumiSubject" << test_bs1 << endl;
	vector<Bangumi_subject> bsvec = { {1,2,3},{2,3,4} };//����ʹ��{(1,2,3)} ֻ�����б��ʼ��
	//���� vector�еĳ�ʼ���б�[�ϸ�Ҫ������һ��]
	//->�����˶�Ӧ�Ķ��������� �� Bangumi_subject{1,2,3} => {1,2,3} int{1}=>1
	for (auto bd : bdvec2) {
		cout << bd << endl;
	}
	for (auto bs : bsvec) {
		cout << bs << endl;
	}
	//Բ������������ �����������б��ʼ��
	ivec.push_back(2); //��vectorβ���Ԫ��
	//vector�ǿ��Ը�Ч��������,ֻ��һ�������ʼ����ͬ��Ԫ��
	//����ʹ������ʱpush��Ԫ�ص�һ����vector����Ч
	//Ϊ�˸�Ч�ܶ��鱣��ʡ��,Ӧȷ������
	//���ѭ�����������vector���Ԫ����� ʱ ����ʹ��range for
	//����push_back()
	//empty() //�Ƿ����һ��Ԫ��
	//size() //Ԫ�ظ���
	//[n] //��������
	//== //���ҽ���Ԫ�ظ�����ͬ���Ҷ�Ӧλ��ֵ��ͬ
	//< > //���ֵ�˳��Ƚ�
	//size_typeҪ��Ӧ
	vector<int>::size_type testx = 0;
	//������vector�Ƚ���stringһ�� ������������
	//���ݵıȽϿ���������͵ıȽ�
	//->ǰ����ֻ��vector�ڵ�Ԫ��ֵ�ɱ�ʱ ��Ӧ��vector�ſɱ�
	//����������������������,����������
	//iterator������
	//����vector������������
	//���б�׼����������ʹ�õ����� stringҲ���� 
	//�������� ��Ч����Ч֮��
	//��������endָ�����������һ���������ڵ�β��,������ʶ���
	//�������Ϊ�� �� begin �� end ���ص���ͬһ�������� ����β�������
	//�����������
	//*iter ����Ԫ������
	//iter->name
	//++iter
	//--iter
	//iter1 == iter2
	string strtest("aabbccdd");
	for (auto it = strtest.begin(); it != strtest.end(); ++it) {
		*it = toupper(*it);
	}
	cout << strtest << endl;
	//
	string::iterator it2; //�ܶ�д�ַ�
	//���vector �� string�ǳ��� ֻ�� ��const_iterator
	string::const_iterator it3; //ֻ�ܶ�ȡ�ַ� ����д�ַ�
	//begin��end���صľ���������ɶ����Ƿ��ǳ�������
	//Ϊ�˱��ڵõ�const_iterator����
	//c++������ cbegin�� cend
	string::const_iterator testc = strtest.cbegin();
	//ĳЩ��vector����Ĳ�����ʹ������ʧЧ
	//������ʹ���˵�������for����ʹ��push_back
	//���push_backӦ����һ��ѭ����ʹ��
	//����������
	//iter + n //��ǰ�ƶ�n��Ԫ��
	//iter - n //����ƶ�
	//iter += n
	//iter1 - iter2 //����������֮��ľ��� �м��Ԫ�ز���� 
	//< > //
	//begin()��ָ0�±�
	auto mid = strtest.cbegin() + strtest.size() / 2;
	string::difference_type difference = mid - strtest.cbegin(); //�����ŵ�����
	//����

}
//�����Сȷ������
//char cha1[] = "c++";
//char cha2[] = { 'c','+','+','\0' }; //��βӦ����һ�����ַ� ���Խ�char[]����c����string ���ַ�������ֵ
//char cha3[] = { 'c','+','+' }; //����û�н�β�Ŀ��ַ� c++������ܶ� ����
void test_array() {
	using std::cout;
	using std::endl;
	//����a[b]��ά��(b)�����ǳ������ʽ
	unsigned cnt = 45; //���ǳ������ʽ
	//int arr[cnt]; //����
	constexpr unsigned cnt1 = 45;
	int arr[cnt1] = {}; //����
	int arr2[sizeof(int)] = {}; //����
	//����������һ�� �ں������ڶ�����ĳ�����͵�����,Ĭ�ϳ�ʼ���Ậ��δ�����ֵ
	//�����������ָ����������� ������auto
	//auto xxx[] = { 1,1,1 };//����
	//�����Ԫ��Ϊ���� ���������� 
	//��ʾ��ʼ������Ԫ��(�б��ʼ��)
	int a3[5] = { 0,1,2 }; //�ȼ� a3[]={0,1,2,0,0} �����������δ����
	//cout << a3[4] << "  " << a3[5] << endl; //δ����ֵ
	//�ַ�������һ�ֶ���ĳ�ʼ����ʽ,ʹ���ַ�������ֵ
	char cha1[] = "c++";
	char cha2[] = { 'c','+','+','\0' }; //��βӦ����һ�����ַ� ���Խ�char[]����c����string ���ַ�������ֵ
	char cha3[] = { 'c','+','+' }; //����û�н�β�Ŀ��ַ� c++������ܶ� ����(��������������,�ⲿ���Ժ��������c++)
	cout << cha1 << endl;
	cout << cha2 << endl;
	//cout << cha3 << endl;
	//const char a4[6] = "123456"; //����  û�пռ���\0
	//���鲻�������͸�ֵ(������Щ������֧�ָ�ֵ,�����Ǳ�׼)
	int *ptrs[10]; //10��int��ָ�������
	//int &refs[10]; //����  :���������õ�����
	int arr3[10] = {};
	int(*parray)[10] = &arr3; //ָ��һ������10�����ε�����
	int(&arrref)[10] = arr3; //����һ������10��int��array
	//��������� parray��һ��ָ�� ָ�� int [10]
	int *(&arrya)[10] = ptrs; // arrya����������� ���麬��10��ָ��
	//���˹̶���С ������vector����һ��
	unsigned scores[11] = {}; //arrayû�����еĵ���������(���鲢����һ����) ȫ��Ĭ�ϳ�ʼ��Ϊ 0
	//->ע�� ʹ����{}��ʼ���б������ʾ��Ĭ�ϳ�ʼ��(��ͬ���ں������ⶨ�岢��ʼ��)
	//->������{}ֻ�Ƕ��� unsigned scores[11]; ��Ϊδ����ֵ
	for (auto i : scores) {
		cout << i << endl;
	}
	//����vector�е�����
	std::vector<unsigned> scores2(11, 0);
	//ʹ������ʱ,������һ������ת����ָ��
	using std::string;
	string nums[] = { "one","two","three" };
	string *p = &nums[0];
	string *p1 = nums; //���ߵȼ�
	//**** �������Զ��滻numsΪָ�������һ��Ԫ�ص�ָ�� ****
	decltype(nums) x = {};//������ string[3];
	auto x2(nums);//������ string*  ==x2(&nums[0])
	//����ĵ���
	cout << *(++p1) << endl; //��nums[0] �� Nums[1]
	//++����ָ�����������ƶ� sizeof(ָ������)���ֽ�
	//ָ������������++ �� + �ȵ������
	//�жϽ�β��β��Ԫ�ص�ַ ������ nums[3]->ָ���ڵ�һ��Ԫ��[βԪ�������һ����Чֵ]
	//Ϊ�˸��Ӱ�ȫ c++ 11��׼���� begin end ����
	string *beg = std::begin(nums);
	string *end = std::end(nums); //β��ָ�벻��ֱ��ʹ�� *
	for (auto i = beg; i != end; ++i) {
		cout << *i << endl;
	}
	//��ȻҲ������const_iterator��cbegin
	const string *beg1 = std::cbegin(nums);
	int ary[] = { 1,1,2,3,6,4 };
	auto n = std::cend(ary) - std::cbegin(ary); //ary��Ԫ�صĸ��� ������ ptrdiff_t��׼������
	//���������е������� vector::difference_type
	cout << n << endl;
	int nn = sizeof(ary) / sizeof(*ary);
	cout << nn << endl; //Ҳ�ɵ�֪Ԫ�ظ���
	//ptrdif_t(������)��size_tһ��������cstddef
	//����ʹ�õ������õ��±�����(���Դ���ֵ)
	//vector���±�����ֻ֧���޷���
}
//c����ַ�������һ�����Ͷ���һ��д��
void test_c_cpp_string() {
	//c-style string���һ���ַ������һ�����ַ�'\0'(Ҳռһ���ַ�λ)
	//ʵ����c�����ַ�������һ��char������
	using std::string;
	using std::cout;
	using std::endl;
	string str = "abc";
	const char co_str[] = "def";
	char c_str[7] = "abc";
	cout << sizeof(str) << endl; //40�ֽ�
	cout << sizeof("abc") << endl; //4�ֽ�
	//c style�Ĳ�������
	//���س��� ���ַ�����
	cout << strlen(co_str) << "  " << strlen("abc") << endl;
	//strcmp(p1,p2)  ���Ϊ0 p1����p2Ϊ����
	cout << c_str << "  " << sizeof(c_str) << " " << strlen(c_str) << endl;
	//��� abc 7 3
	cout << c_str[5]; // \0���ַ�
	strcat(c_str, co_str);
	cout << c_str << endl;//����һ������const ��2���ӵ�1������1
	//->��������������ж�,ԭ����c_strû���㹻�Ŀռ� �������c_str[7]
	strcpy(c_str, co_str); // ��2������1 ����1
	cout << c_str << endl; //ȷ��1���ڴ�ռ��㹻
	//����һ��string����Ƚ�ֱ��ʹ�� < > (�����˲�����) 
	//������c����ʹ�� < > �Ƚϵ���ָ��,�����ַ������� ��Ȼ + -Ҳ����ʹ��(ʵ������������ص�ָ�������) ����ʹ��strcmp

	//�κγ����ַ�������ֵ�ĵط������ÿ��ַ��������ַ����������
	//��׼��string�ṩһ��s_str()����ʼ�� const char* (������const char[]����ֻ�ܷ���ָ��) (c���)[]
	const char *xx = str.c_str();
	//char xxx[] =
	cout << xx << endl; //ע�� char���͵�ָ��ʹ��<<��ʱ��һֱ�����\0Ϊֹ
	//��Ϊ��һ��ָ��,�޷���֤c_str()���ص�ֵһֱ��Ч
	str = "ddd";
	cout << xx << endl; //���ddd
	//ʹ�������ʼ��vector����
	int int_arr[] = { 0,1,2,3,4,5,6 };
	//ע�� ���е�end����ָβ��Ԫ��(�����ڶ�������)
	std::vector<int> ivec(std::begin(int_arr) + 1, std::end(int_arr) - 1);
	for (auto i = ivec.begin(); i != ivec.end(); ++i) {
		cout << *i << endl;
	}
	//����ʹ�ñ�׼���������
	//��ά���� ���������
	int ia[3][4] = {}; //��СΪ3 ÿ��Ԫ���Ǻ���4������������
	//���մ��������� (�������������)
	//���ڶ�ά���� ���ѵ�һ��ά�ȳ����� �ڶ���ά�ȳ�����
	int ib[3][4] = {
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12}
	};
	//Ҳ����û���㻨����
	int ic[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	int id[3][4] = { {0}, {1}, {2} };//Ҳ�ɲ��ָ�����ʼ�� ����Ĭ�ϳ�ʼ��
	int(&row)[4] = ib[1]; //��row�󶨵�ʱib�ĵڶ���4Ԫ��������;
	//��ά�����for
	//��ͳ���� ����forǶ��
	//c++11 range for
	for (auto &i : ia) {
		for (auto &j : i) {
			j = 1;
		}
	}
	//ʹ�����õ�ԭ�� ���ϲ�������Ϊ��Ҫ�ı�ֵ
	for (const auto &row : ia) {//�˴�(���)��Ҫ�� & ���������������Զ�ת��ָ��
		for (int col : row) {
			cout << col << endl;
		}
	}
	//ʵ��ʹ��range for ��Ѱ��begin�������ҵ�ָ�� Ȼ����range for �Զ���ָ��
	//for (const auto row : ia) {
	//	for (auto col : row) { //row��������int *const row �޷��ҵ����ʵ�begin
	////**** �������Զ��滻һ���������Ϊָ�������һ��Ԫ�ص�ָ�� ****
	////��ά����ᱻת��Ϊ1��ָ��
	//		cout << col << endl;
	//	}
	//}
	//int ox = std::begin(ia); 
	//begin���صľ���һ��ָ�� �����ص��� int(*) [4]
	//���ֱ��ʹ���������б�������:ֱ��ʹ������ʹ�����˻�Ϊһ��ָ�� int*
	for (auto p = std::begin(ia); p != std::end(ia); ++p) {
		for (auto q = std::begin(*p); q != std::end(*p); ++q) {
			cout << *q << endl;

		}
	}
	//ʹ�����ͱ����򻯹��� c++ 11
	using int_array = int[4];
	typedef int int_array[4];//�ȼ�
}
//С��
//string(�ɱ䳤���ַ�����) �� vector(һ��ͬ���Ͷ��������)������ ��Ҫ�ı�׼������
//���߶��е�����
//�����ָ������Ԫ�ص�ָ����һ���ϵ͵Ĳ����ʵ�������׼������string��vector���ƵĹ���
//buffer overflow ��Ҫԭ����ͼͨ��һ��Խ��������������������� 
//��������չ ������ֲ
//������ʼ�� ʹ��= ��ʼ����ʽ �´����Ķ����ǳ�ʼֵ��һ������
//��ֵ����ֵ c++�ı��ʽ������ֵ ���� ��ֵ: c��������ֵ����λ�ڸ�ֵ�������,��ֵ����
//c++�� ��������: һ����ֵ���ʽ����ֵ�����һ�������һ������,Ȼ���Գ�������Ϊ�����ĳЩ��ֵ������Ϊ��ֵ��������������
//������ȻĳЩ���ʽ����ֵ����Ƕ��� ����������ֵ
//�ܽ� ��һ������������ֵʱ,�õ��Ƕ����ֵ(�ڴ�);������������ֵʱ.�õ��Ƕ�������(�����λ��)
//c++ pri p121����ϸ������

void test_basic() {
	//������Щû��ָ��˳����������˵,������ʽָ���޸�ͬһ������,�����������󲢲���δ������Ϊ
	//����<<û����ȷ�涨��ʱ�Լ���ζ����������ֵ
	//�������������ʽ��δ�����
	using std::cout;
	using std::endl;
	int i = 0;
	cout << i << "" << ++i << endl; //���� //һ������� 11
	//��4���������ȷ�涨������������ֵ˳��1>&& 2>|| 3>?: 4>,
	//��ֵ˳�������ȼ��ͽ�����޹�,��f()+g()*h()+j()��
	//���ȼ��涨,g()�ķ���ֵ��h()�ķ���ֵ���
	//����ɹ涨,f()�ķ���ֵ����g()��h()�ĳ˻����,�������j()�ķ���ֵ���
	//������Щ�����ĵ���˳��û����ȷ�涨
	//������Ƕ����޹غ���(ͬһ����ĸı�,IO����),�����˳��������,��֮��δ������Ϊ
	//���һ���������ò�Ҫ�ж�ͬһ����ĸ��Ĳ���*++iterû������ ++��������
	//ȡģ����������������
	//c++11�涨��һ����0ȡ��(ֱ���г�С������)
	//m nΪ������n!=0 m==(m/n)*n+m%n
	//m%(-n) == m%n  (-m)/n == m/(-n) == -(m/n)
	//<= >= < >���ȼ�����== !=
	//&&���ҽ��������������Ϊ��ʱ���Ϊ��||ֻҪһ��Ϊ�漴Ϊ��
	//���߶������������������ֵ���ҽ�������޷�ȷ�����ʽ��ֵʱ�Ż�����Ҳ������ֵ
	//->���ֲ��Խ� ��·��ֵ
	//��ֵ������������������һ�����޸ĵ���ֵ
	int ii = 0, j = 0;//��ʼ�����Ǹ�ֵ
	const int ci = ii;//��ʼ�����Ǹ�ֵ
	//i+ j =k; //���� �������ʽ����ֵ
	//k = {3.14}; //���� խ��ת�� {}����Ҫ��һ��
	//�����ʼ���б�{}Ϊ�� ��ֵ��ʼ������һ��ʱ�ǲ����丳�д�����������
	//��ֵ���������ҽ���� ��ͬ������Ԫ����� �����ȼ��ϵ�
	//�����������ֵ����ֻ��һ�� ����ͨ����Ҫ���� +=
	//���� �ݼ������
	//ǰ�ð汾����������Ϊ��ֵ����(�Ƽ�) ���ð汾�򽫶���ԭʼֵ�ĸ���(����)��Ϊ��ֵ����
	//���õ�ʹ������ *pbeg++
	//���õ�����������ȼ����ڽ����������
	//std::string s;
	//std::string::iterator beg = s.begin();
	//while (beg != s.end() && !std::isspace(*beg)) {
	//	*beg = std::toupper(*beg++); //δ����,�Ҳ�ı���beg �����ʹ����beg
	//	//�������� = �� �Ҳ��ֵ  Ҳ�������� ����ֵ
	//}
	//����������������ȼ����ڵ������ (*p).size()
	//��������� ?: �����ҽ���� ���ȼ��ǳ���
	//��������ʽ��ʹ��?:
	int grade = 70;
	cout << ((grade < 60) ? "fail" : "pass") << endl; //pass or fail
	cout << (grade < 60) ? "fail" : "pass";//���1 �� 0
	//cout << grade < 60 ? "fail" : "pass" ; //���� ��ͼ�Ƚ�cout �� 60
	//�����ߺ��ټ�<<endl ֱ��Ҳ����
	//λ�������������������,����������󿴳��Ƕ�����λ�ļ���,λ�����ṩ�������ö�����λ�Ĺ���
	//��Ϊ  bitset �ı�׼������Ҳ���Ա�ʾ�����С�Ķ�����λ�ļ���,���Ҳ����λ�����
	//����λû����ȷ�Ĺ涨 ǿ�ҽ��������޷�������
	//~ λ�� 0=>1 1=>0
	//<< >> ���� ���� IO�������������,������������������������ݰ����Ҳ�Ҫ���ƶ�ָ��λ��,�ƶ����(���ܽ�������)����������Ŀ�����Ϊ��ֵ�Ľ��,�Ҳ����һ������Ϊ��,���ұ��ϸ�С�ڽ����λ��,��������δ������Ϊ,�������Ƴ��߽�֮��ı�����
	//& λ��
	//^ λ���
	//| λ��
	//0���ص��������� �˽��� 0x ����ʮ������
	cout << "char size: " << sizeof(char) << endl; //1�ֽ�
	cout << "int size: " << sizeof(int) << endl; //4�ֽ�
	unsigned char bits = 0233; //10011011
	//bits << 8;//bits������int Ȼ������8λ
	//00000000 00000000 10011011 00000000
	//bits << 31;//�����߽� ����
	//10000000 00000000 00000000 00000000
	//bits >> 3; //�����ƶ�3 ע�����Ʋ��������λ��ص�ֵ
	//00000000 00000000 00000000 00010011
	unsigned char bits1 = 0227; //10010111
	//~bits1;//char��������Ҫ������int����
	//11111111 11111111 11111111 01101000
	1UL << 27; //����һ��ֻ��27λ��1 ��unsigned long ,intֻ��ȷ����16λ
	unsigned long students = 0;
	students |= 1UL << 27;
	students &= ~(1UL << 27);
	bool status = (students & (1UL << 27)) == 1;
	//��λ����<< >>�ֽ�IO����� ����������  ���ȼ����� �����͹�ϵ�����֮��
	//sizeof����� �����ҽ���ɷ���ֵ size_t���� ���ȼ�=*
	sizeof(int); //Ҳ�ɲ���()
	int x = 0, *px = nullptr;
	sizeof x; //���ر��ʽ�����͵Ĵ�С 
	sizeof *px; //����int�����ʹ�С ��ʹpx��һ����Чָ��Ҳû��(ֻ������)
	cout << "x " << sizeof x << " *px " << sizeof *px << endl;
	//c++ 11�±�׼����ʹ�����������������ȡ���Ա�Ĵ�С
	//sizeof���㲻�������ת����ָ�������� ��˷�������Ĵ�С
	int array_int[10] = {};
	constexpr size_t sz = sizeof array_int / sizeof *array_int;
	int arr2[sz] = {};
	//��������� �������ҵ�˳��������ֵ
	//�ȶ����ı��ʽ��ֵ Ȼ�󽫽��������,�������������������Ҳ���ʽ��ֵ
	using std::vector;
	vector<int> ivec;
	vector<int>::size_type cnt = ivec.size();
	//...
	//����ת��
	int ival = 3.541 + 3;//��ʾ������ʧ  (��ʽת��) 3=>double +3.541  6.541 => int =6
	//��ʱ��������ת�� p141
	//����ת�� ����������ת������һ�������������һ����������������long double ��ô������һ����������������ʲô����ת����long double
	//�������� ��С����ת���ɽϴ���������� ֻҪ���п��ܵ�ֵ�ܷ���int����������unsigned int
	short a1 = 1, a3 = 2;
	char a2 = 5;
	cout << "a1+a2: " << sizeof(a1 + /*+ a2 +*/a3) << endl; //�Ѿ�����������
	//��������ʽ����ת��
	//����ת����ָ�� [ע��:������& sizeof typeid ʱ����ת����ָ��]
	int ia[10];
	int *ip = ia;
	//ָ���ת�� 0 nullptrת�����������͵�ָ�� ָ������ǳ�����ָ����ת����void* �������� const void*
	//ת���ɲ���
	//ת���ɳ���
	//�����Ͷ����ת�� �ַ�������ֵת����string cin=>����ֵ
	//��ʾת��
	//ǿ������ת��(�ǳ�Σ��)
	//һ��������ǿ������ת����������ʽ
	//cast-name<type>(expression);
	//type��Ŀ������ expression����Ҫת����ֵ �������ֵ
	//cast-name�� static_cast dynamic_cast(����ʱ����ʶ��)  const_cast �� reinterpret_cast
	//static_cast�κξ�����ȷ���������ת��,ֻҪ�������ײ�const ������ʹ��
	int i1 = 1, j1 = 2;
	double slop = static_cast<double>(i1) / j1; //ʹ���ʽִ�и���������
	//���� static_cast �����һش�����void*��ָ��
	//const_castֻ�ܸı��������ĵײ�const
	const char *pcc = "123";
	char *p = const_cast<char*>(pcc); //��ȷ ����ͨ��pдֵ��δ������Ϊ 
	//��Ϊȥ��const���� �����������һ������������������Ķ����ǿ��Խ���д��,�����δ����
	//ֻ��const_cast�ܸı���ʽ�ĳ�������,��const_cast���ܸı���ʽ������
	//reinterpret_castͨ��Ϊ��������λģʽ�ṩ�ϵͲ���ϵ����½���(�ǳ�Σ��)
	int *iip = 0;
	char *pc = reinterpret_cast<char*>(iip);
	//����Ҫ�μ�pc��ָ����ʵ������һ��int����char
	//string str(pc); //����ʱ���ܴ���
	//��ʽǿ������ת��
	//type(expr)
	//(type)expr
	//��ʽ�ֱ������const_cast static_cast reinterpret_cast���Ƶ���Ϊ
	//������滻��const_cast static_cast,����Ϊ�Ͷ�Ӧ������ת��һ�� ������reinterpret_cast����
	//p147��������ȼ���

}
//���
void test_statement() {
	using std::cin;
	using std::cout;
	using std::endl;
	//c++��䶼�ԷֺŽ��� ĩβ����;
	//�����
	;
	//����
	//int my_input;
	//while (cin >> my_input)
	//	; //�����
	//������� => �� ��block�����������ֻ���ڿ��з���(���嵽��β)
	//���������ǿ�����㶨��һ����{} �ⲿ��Ҫ�ṩ���� �鲻�ԷֺŽ���
	//�տ�==�����
	{}
	//���������
	//if switch
	//����else c++�й涨else�������������δƥ���ifƥ��
	int x = 0;
	//while (cin >> x) {
	switch (x)
	{
	case 100:
		cout << "ok" << endl;
		//std::string name; //���� �������ƹ�һ����ʽ��ʼ��ֵ
		//int cc = 1; //���� �������ƹ�һ����ʾ��ʼ��ֵ
		{
			std::string name = "ddddd"; //������һ������
		}
		int c; //��ȷ ��Ϊcû�б���ʼ��
		break; //ע��һ��ƥ�� ������䶼ִ�� ���ʹ��break;�ж�

	default:
		c = 10; //��ȷ
		//cc = 1;//���� �������ƹ�һ����ʾ��ʼ��ֵ
		//name = "d"; //���� �������ƹ�һ����ʽ��ʼ��ֵ
		cout << "no" << endl;
		break;
	}

	//}
	//break�����жϵ�ǰ�������ϸ������н�����Ȩת�Ƶ���switch������� 
	//case�ؼ��ֺ�����Ӧ��ֵ���������ͳ������ʽ ����case����һ��
	//case������д��һ�� case 'a':case 'e':
	//�����case���ж��� : c++�涨 �������������ĳ�ʼ�����ֱ����ת���ñ������������һ��λ��
	//��������ҪΪĳ��case��֧���岢��ʼ��һ������ Ӧ�������ڿ��� �Ӷ�ȷ�����������case��ǩ���ڱ�����������֮��
	//�������
	//��ת���
	//break ��� ������ֹ���������while do_while for switch���
	//continue ��� ��ֹ�����ѭ���еĵ�ǰ������������ʼ��һ�εĵ��� ֻ�ܳ����� for while do_while
	//goto �������������ת��ͬһ�����ڵ���һ�����
	//��Ҫʹ��goto
	//�﷨: goto label; label�����ڱ�ʶһ�����ı�ʾ��
	//end : return; //����ǩ���,������Ϊgoto��Ŀ��
	//��ǩ��ʾ�������ڱ�����������ʾ������, ��switch���� goto��䲻�ܽ�����Ŀ���Ȩ�ӱ�����������֮��ת�Ƶ�������֮��
	goto end;
	int ix = 10; //���� goto�ƹ���һ������ʼ���ı����Ķ��� //ʵ��û�б���
end:
	ix = 42;
	cout << ix << endl;
	//�����ǰ��ת(��������֮ǰ)��ζ��ϵͳ�����ٸñ��� Ȼ�����´�����
}
int test_exception(){
	//try������쳣����
	//c++���쳣�������
	//throw ���ʽ �����쳣
	//try ���� �����쳣,��һ��try�ؼ��ֿ�ʼ,����һ������catch�Ӿ����
	//һ���쳣�� ������throw���ʽ����ص�catch�Ӿ�֮�䴫���쳣��Ϣ
	//�׳�һ���쳣����ֹ��ǰ�ĺ���,���ѿ���Ȩת�Ƹ��ܴ�����쳣�Ĵ���
	//runtime_error������stdexceptͷ�ļ���
	using std::cin;
	using std::cout;
	using std::endl;
	const unsigned password = 123456;
	unsigned int input;
	while (cin >> input) {
		if (password != input) {
			throw std::runtime_error("An error password!");
			
		}
		cout << "Welcome~";
		return 0;
	}
	return -1;
	//try������ ��ѡ����һ��catch�Ӿ䴦���쳣֮��,ִ����֮��Ӧ�Ŀ�,
	//catchһ�����,������ת��try������һ��catch�Ӿ�֮�������������ִ��
	//try�������ı����ڿ��ⲿ�޷�����,�ر�����catch�Ӿ���Ҳ�޷�����

	//try��Ҳ���ܵ�����try
	//Ѱ�Ҵ������Ĺ����뺯���������෴,
	//���쳣���׳�ʱ,���������׳����쳣�ĺ���.���û���ҵ�ƥ���catch�Ӿ�,��ֹ�ú���,����
	//���øú����ĺ����м���Ѱ��.�����û��,��������ֱ���ҵ�Ϊֹ.
	//����û���ҵ��κ�ƥ���catch�Ӿ�,����ת����Ϊterminate�ı�׼�⺯��,�ú�������Ϊ��ϵͳ�й�
	//һ������µ��³���������˳�,û��try����Ҳ�����ַ�ʽ����
	//�쳣��
	//exception ͷ�ļ� ��ͨ�õ�,ֻ�����쳣�ķ���
	//stdexcept ͷ�ļ� �����˼��ֳ��õ��쳣��
	//new ͷ�ļ� ������bad_alloc�쳣��
	//type_info ͷ�ļ� ������bad_cast�쳣��

	//����ֻ����Ĭ�ϳ�ʼ�ķ�ʽ��ʼ��exception,bad_alloc,bad_cast����,�������ṩ��ʼֵ
	//�����쳣���͵���Ϊ��ǡ���෴,Ӧ��ʹ��string�������c����ַ�����ʼ����Щ���͵Ķ���
	//���ǲ�����ʹ��Ĭ�ϳ�ʼ���ķ�ʽ(������ʾ��ʼ��)û��Ĭ�ϵĹ��캯��
	//what���ص�ֵȡ���������Ƿ�洢һ���ַ��� ���������ɱ���������

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
	//p = 3.1416;
	//ָ��
	//test_pointer();
	//extern const�ؼ���
	//std::cout << x;
	//test_using();
	//cout << "end"; //using�ڿ�λ��������ֻ��������Ч
	//test_string();
	//test_vector();
	//test_array();
	//test_c_cpp_string();
	//test_basic();
	//test_statement();
	try {
		test_exception();//ִ�в��Դ���
		//��ʧ�����׳��쳣
	}
	catch (std::runtime_error re) {
		std::cout << re.what(); //����쳣(runtime_error)����Ϣ
		//what()����c�����ַ���(const char*)
	}
	system("pause");
	return 0;
}

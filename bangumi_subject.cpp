#include "bangumi_subject.h"
#include <iostream>
using std::istream;
using std::ostream;
int Bangumi_subject::Id()const
{
	return id;
}

int Bangumi_subject::DoNum()const
{
	return do_num;
}

int Bangumi_subject::Score()const
{
	return score;
}

Bangumi_subject::Bangumi_subject()
{
	id = 0;
	do_num = 0;
	score = 0;
}

Bangumi_subject::Bangumi_subject(int i_id, int i_score, int i_do_num)
	:id(i_id),score(i_score),do_num(i_do_num)
{
	
}

Bangumi_subject& Bangumi_subject::operator++()
{
	this->do_num += 1;

	return *this;
}

Bangumi_subject Bangumi_subject::operator++(int)
{
	this->do_num += 1;

	return *this;
}

Bangumi_subject Bangumi_subject::operator+(const Bangumi_subject &subject)
{
	if (this->id == subject.id) {
		int new_do_num = this->do_num + subject.do_num;
		Bangumi_subject new_subject(this->id,this->score, new_do_num);
		return new_subject;
	}
	else {
		return *this;
	}

	
}

Bangumi_subject & Bangumi_subject::operator+=(const Bangumi_subject &subject)
{
	this->do_num += subject.do_num;
	// TODO: 在此处插入 return 语句
	return *this;
}

//std::ostream & operator<<(std::ostream &out, const Bangumi_subject &subject)
//{
//	out << "Bangumi ID : " << subject.id
//		<< "Bangumi Score : " << subject.score
//		<< "Bangumi Do : " << subject.do_num;
//
//	return out;
//}
//
//std::istream & operator >> (std::istream &in, Bangumi_subject &subject)
//{
//	in >> subject.id >> subject.do_num >> subject.score;
//
//	return in;
//}

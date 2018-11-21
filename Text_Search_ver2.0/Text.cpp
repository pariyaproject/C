#include "Text.h"
//inline����ֻ�ܶ�������֮��ص�ͷ�ļ���,���ܿ��ļ� ****
ReaderResult TextReader::Search(string word)
{
	try {
		auto result_set_ptr = word_map->at(word);
		return ReaderResult(word,result_set_ptr,line_vec,result_set_ptr->size());
	}
	catch(std::out_of_range e){
		return ReaderResult(word, e.what());
	}
	
}

void TextReader::Process()
{
	string line;
	string word;
	istringstream line_stream;
	int line_num = 0;
	int times = 0;
	line_vec->push_back("#"); //��Ϊ��0������
	while (getline(input, line)) {
		++line_num;
		//word part
		line_stream.str(line);
		while (line_stream >> word) {
			//*****����ע��,������auto&����,��Ȼ�޷�����
			auto &set_ptr = (*word_map)[word];
			if (!set_ptr) {//��ʱָ��Ϊ��,nullptr,�����Ҫreset
				set_ptr.reset(new multiset<int>);
			}

			set_ptr->insert(line_num);
		}
		//line part
		line_vec->push_back(line);
		//
		line_stream.clear();
	}
}

#include "Text.h"
//inline函数只能定义在与之相关的头文件中,不能跨文件 ****
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
	line_vec->push_back("#"); //作为第0行内容
	while (getline(input, line)) {
		++line_num;
		//word part
		line_stream.str(line);
		while (line_stream >> word) {
			//*****这里注意,返回是auto&引用,不然无法更改
			auto &set_ptr = (*word_map)[word];
			if (!set_ptr) {//此时指针为空,nullptr,因此需要reset
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

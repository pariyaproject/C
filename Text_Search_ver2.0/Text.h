#ifndef TEXT_H
#define TEXT_H
#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <set>
#include <memory>
#include <vector>
using std::cin;
using std::cout;
using std::ifstream;
using std::ofstream;
using std::istringstream;
using std::endl;
using std::map;
using std::set;
using std::multiset;
using std::istream;
using std::ostream;
using std::getline;
using std::string;
using std::multimap;
using std::shared_ptr;
using std::vector;

class ReaderResult;
class TextReader
{
public:
	using WordMap = shared_ptr<map<string, shared_ptr<multiset<int>>>>;
	using UnWordMap = map<string, shared_ptr<multiset<int>>>;
	using LineVec = shared_ptr<vector<string>>;
	using UnLineVec = vector<string>;

	TextReader()
		:word_map(new UnWordMap()), line_vec(new UnLineVec()), input(cin)
	{
		
		Process();
	}

	TextReader(ifstream &is)
		:word_map(new UnWordMap()), line_vec(new UnLineVec()), input(is)
	{
		Process();
	}

	ReaderResult Search(string word);

private:
	void Process();

	WordMap word_map;
	LineVec line_vec;
	string wanted_word;
	istream &input;
};

class ReaderResult {
	friend inline ostream& operator<<(ostream &os, const ReaderResult&);
public:
	ReaderResult(string word, shared_ptr<multiset<int>> word_set, shared_ptr<vector<string>>lvec, size_t time)
		:wanted_word(word), word_map_set(word_set), line_vec(lvec), times(time)
	{}
	ReaderResult(string word, string msg) 
		:wanted_word(word),times(0)
	{
		word_map_set.reset(new multiset<int>);
		word_map_set->insert(0);

		line_vec.reset(new vector<string>);
		line_vec->push_back(msg);
	}
private:
	shared_ptr<multiset<int>> word_map_set;
	shared_ptr<vector<string>> line_vec;
	string wanted_word;
	size_t times;
};
//жиди<<
inline ostream& operator<<(ostream &os, const ReaderResult& result) {
	os << "->" << result.wanted_word << " occurs " << result.times << " times" << endl;
	int last_line = 0;
	for (auto i : *(result.word_map_set)) {
		if (last_line != i) {
			os << "\t(line "
				<< i
				<< ") "
				<< (*result.line_vec)[i]
				<< endl;
			last_line = i;
		}

	}
	return os;
}


#endif
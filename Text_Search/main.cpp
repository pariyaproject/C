#include <iostream>
#include <sstream>
#include <fstream>
#include <map>

using std::cin;
using std::cout;
using std::ifstream;
using std::ofstream;
using std::istringstream;
using std::endl;
using std::map;
using std::istream;
using std::ostream;
using std::getline;
using std::string;
using std::multimap;

inline void HandleLine(const string &line, multimap<string, int>& word_map, const int &curr_line_num) {
	istringstream line_input(line);
	string word;
	while (line_input >> word) {
		word_map.emplace(word, curr_line_num);
	}
}

void LoadText(istream& in, multimap<string, int>& word_map, map<int, string>& text_map) {
	string curr_s;
	int line_num = 0;
	while (getline(in, curr_s)) {
		//记录行内容
		text_map.emplace(++line_num, curr_s);
		//处理每个单词的map
		HandleLine(curr_s, word_map, line_num);
	}
	cout << "Handle OK!\n..." << endl;
}
inline void PrintResult(ostream &os, const string &str, const int &times);
inline void PrintWordLine(ostream &os, int line_num, const string &curr_line);
void Search(const string &wanted, multimap<string, int>& word_map, map<int, string>& text_map, ostream& os = cout) {
	auto beg = word_map.equal_range(wanted).first;
	auto end = word_map.equal_range(wanted).second;
	PrintResult(os, wanted, word_map.count(wanted));
	int last_line = 0;
	for (auto i = beg; i != end; ++i) {
		if (last_line != (*i).second) {
			last_line = (*i).second;
			PrintWordLine(os, (*i).second, text_map.at(last_line));
		}
	}
}
void PrintResult(ostream &os, const string &str, const int &times) {
	os <<"->"<< str << " occurs " << times << " times" << endl;
}
void PrintWordLine(ostream &os, int line_num, const string &curr_line) {
	os << "\t(line "
		<< line_num
		<< ") "
		<< curr_line
		<< endl;
	//return os;
}

int main() {
	multimap<string, int> word_map;
	map<int, string> text_map;
	//const string example_string = "";
	//istringstream string_input(example_string);

	ifstream file_input("input.txt");
	if (!file_input){
		cout << "File Opened Filed!\n";
		//return -1;
	}

	LoadText(file_input, word_map, text_map);

	string search_word;
	cout << "Now Input the word you want to search:\n" << endl;
	while (cin >> search_word) {
		Search(search_word, word_map, text_map);
	}


	system("pause");
}
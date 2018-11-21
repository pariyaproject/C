#include <iostream>
#include "Text.h"	


int main() {

	string search_word;
	ifstream file_input("input.txt");
	if (!file_input) {
		cout << "File Opened Filed!\n";
		//return -1;
	}
	else {
		TextReader example_reader(file_input);
		cout << "OK" << endl;
		while (cout << "Input the word you want to search:\n", cin >> search_word) {
			cout << example_reader.Search(search_word) << endl;
		}
	}




	system("pause");
}
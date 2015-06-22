#include "HashTable.h"
#include "Node.h"
#include "Node_impl.h"
#include "List.h"
#include "List_impl.h"
#include "Queue.h"
#include "Queue_impl.h"
#include <fstream>
#include <string>

using namespace std;

HashTable varNames = HashTable();
HashTable keywords = HashTable();

void buildKeywords();
void getWords(string);
void findOccurences(string, char*);

int main()
{
	bool run = true;
	buildKeywords();
	string filename;
	string prompt;
	while (run)
	{
		cout << "Enter the full path of the file you want to read:" << endl;
		getline(cin, filename);
		getWords(filename);
		cout << endl << "Would you like to read another file? (type Y for yes)";
		getline(cin, prompt);
		if (prompt == "y" || prompt == "Y")
			run = true;
		else
			run = false;
	}
	system("pause");
	return 0;
}

void getWords(string fname)
{
	ifstream in(fname);
	if (!in)
	{
		cout << "There was a problem opening the file." << endl;
		return;
	}
	char letter;
	char prevletter = '\0';
	bool varstart = false;
	bool quote = false;
	bool comment = false;
	bool commentblock = false;
	Queue<char> storeword = Queue<char>();
	while (!in.eof())
	{
		in.get(letter);
		if (letter == 47 && prevletter == 47 && !commentblock)
			comment = true;
		else if (letter == 42 && prevletter == 47 && !comment)
			commentblock = true;
		else if (comment)
		{
			if (letter == '\n')
				comment = false;
		}
		else if (commentblock)
		{
			if (letter == 47 && prevletter == 42)
				commentblock = false;
		}
		else if (quote)
		{
			if (letter == 34 || letter == 39)
				quote = false;
		}
		else if (!varstart)
		{
			if (letter == 34 || letter == 39)
				quote = true;
			else if ((letter >= 65 && letter <= 90) || (letter >= 97 && letter <= 122) || letter == 95)
			{
				storeword.enqueue(letter);
				varstart = true;
			}
		}
		else
		{

			if ((letter >= 65 && letter <= 90) || (letter >= 97 && letter <= 122) || (letter >= 48 && letter <= 57) || letter == 95)
			{
				storeword.enqueue(letter);
			}
			else
			{
				char* word = new char[storeword.QSize() + 1];
				for (int i = 0; !storeword.isEmpty(); i++)
				{
					word[i] = storeword.dequeue();
					word[i + 1] = '\0';
				}
				if (!keywords.find(word) && !varNames.find(word))
				{
					cout << word << "\n";
					findOccurences(fname, word);
					cout << endl << endl;
					varNames.insert(word);
				}
				else
					delete[] word;
				varstart = false;
			}
		}
		prevletter = letter;
	}
	in.close();
}

void findOccurences(string fname, char* aWord)
{
	ifstream in(fname);
	string line;
	if (!in)
	{
		cout << "There was a problem opening the file." << endl;
		return;
	}
	char letter;
	char prevletter = '\0';
	bool varstart = false;
	bool quote = false;
	bool comment = false;
	bool commentblock = false;
	int linenum = 1;
	Queue<char> storeword = Queue<char>();
	while (!in.eof())
	{
		in.get(letter);
		if (letter == 47 && prevletter == 47 && !commentblock)
			comment = true;
		else if (letter == 42 && prevletter == 47 && !comment)
			commentblock = true;
		else if (comment)
		{
			if (letter == '\n')
			{
				linenum++;
				comment = false;
			}
		}
		else if (commentblock)
		{
			if (letter == 47 && prevletter == 42)
				commentblock = false;
			if (letter == '\n')
				linenum++;
		}
		else if (quote)
		{
			if (letter == 34 || letter == 44)
				quote = false;
			if (letter == '\n')
				linenum++;
		}
		else if (!varstart)
		{
			if (letter == 34 || letter == 44)
				quote = true;
			else if ((letter >= 65 && letter <= 90) || (letter >= 97 && letter <= 122) || letter == 95)
			{
				storeword.enqueue(letter);
				varstart = true;
			}
			if (letter == '\n')
				linenum++;
		}
		else
		{
			if ((letter >= 65 && letter <= 90) || (letter >= 97 && letter <= 122) || (letter >= 48 && letter <= 57) || letter == 95)
			{
				storeword.enqueue(letter);
			}
			else
			{
				char* word = new char[storeword.QSize() + 1];
				for (int i = 0; !storeword.isEmpty(); i++)
				{
					word[i] = storeword.dequeue();
					word[i + 1] = '\0';
				}
				if (strcmp(word, aWord) == 0)
				{
					cout << linenum << ", ";
					delete[] word;
					while (letter != '\n')
						in.get(letter);
				}
				else
					delete[] word;
				varstart = false;
			}
			if (letter == '\n')
				linenum++;
		}
		prevletter = letter;
	}
	in.close();
}

void buildKeywords()
{
	keywords.insert("alignas");
	keywords.insert("alignof");
	keywords.insert("and");
	keywords.insert("and_eq");
	keywords.insert("asm");
	keywords.insert("auto");
	keywords.insert("bitand");
	keywords.insert("bitor");
	keywords.insert("bool");
	keywords.insert("break");
	keywords.insert("case");
	keywords.insert("catch");
	keywords.insert("char");
	keywords.insert("char16_t");
	keywords.insert("char32_t");
	keywords.insert("class");
	keywords.insert("compl");
	keywords.insert("concept");
	keywords.insert("const");
	keywords.insert("constexpr");
	keywords.insert("const_cast");
	keywords.insert("continue");
	keywords.insert("decltype");
	keywords.insert("default");
	keywords.insert("delete");
	keywords.insert("do");
	keywords.insert("double");
	keywords.insert("dynamic_cast");
	keywords.insert("else");
	keywords.insert("enum");
	keywords.insert("explicit");
	keywords.insert("export");
	keywords.insert("extern");
	keywords.insert("false");
	keywords.insert("float");
	keywords.insert("for");
	keywords.insert("friend");
	keywords.insert("goto");
	keywords.insert("if");
	keywords.insert("inline");
	keywords.insert("int");
	keywords.insert("long");
	keywords.insert("mutable");
	keywords.insert("namespace");
	keywords.insert("new");
	keywords.insert("noexcept");
	keywords.insert("not");
	keywords.insert("not_eq");
	keywords.insert("nullptr");
	keywords.insert("operator");
	keywords.insert("or");
	keywords.insert("or_eq");
	keywords.insert("private");
	keywords.insert("protected");
	keywords.insert("public");
	keywords.insert("register");
	keywords.insert("reinterpret_cast");
	keywords.insert("requires");
	keywords.insert("return");
	keywords.insert("short");
	keywords.insert("signed");
	keywords.insert("sizeof");
	keywords.insert("static");
	keywords.insert("static_assert");
	keywords.insert("static_cast");
	keywords.insert("struct");
	keywords.insert("switch");
	keywords.insert("template");
	keywords.insert("this");
	keywords.insert("thread_local");
	keywords.insert("throw");
	keywords.insert("true");
	keywords.insert("try");
	keywords.insert("typedef");
	keywords.insert("typeid");
	keywords.insert("typename");
	keywords.insert("union");
	keywords.insert("unsigned");
	keywords.insert("using");
	keywords.insert("virtual");
	keywords.insert("void");
	keywords.insert("volatile");
	keywords.insert("wchar_t");
	keywords.insert("while");
	keywords.insert("xor");
	keywords.insert("xor_eq");
	keywords.insert("elif");
	keywords.insert("endif");
	keywords.insert("defined");
	keywords.insert("ifdef");
	keywords.insert("ifndef");
	keywords.insert("define");
	keywords.insert("undef");
	keywords.insert("include");
	keywords.insert("pragma");
	keywords.insert("std");
	keywords.insert("iostream");
	keywords.insert("NULL");
	keywords.insert("cout");
	keywords.insert("cin");
	keywords.insert("cerr");
	keywords.insert("endl");
	keywords.insert("fstream");
	keywords.insert("ifstream");
	keywords.insert("ofstream");
	keywords.insert("string");
	keywords.insert("cstdlib");
	keywords.insert("ctime");
	keywords.insert("rand");
	keywords.insert("srand");
	keywords.insert("time");
	keywords.insert("system");
}

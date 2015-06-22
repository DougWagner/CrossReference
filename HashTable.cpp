#include "HashTable.h"

HashTable::HashTable()
{
	size = 13;
	table = new char*[13];
	for (int i = 0; i < size; i++)
		table[i] = "\0";
	numtaken = 0;
}

int HashTable::hash(char* in)
{
	unsigned int hashval = 0;
	while (*in != '\0')
		hashval += *in++;
	return hashval;
}

void HashTable::rehash(int arraysize)
{
	size = nextPrime(arraysize * 2);
	char **newtable = new char*[size];
	int val;
	int hval;
	for (int i = 0; i < size; i++)
		newtable[i] = "\0";
	for (int i = 0; i < arraysize; i++)
	{
		if (strcmp(table[i], "\0") != 0)
		{
			val = hash(table[i]);
			hval = val % size;
			if (strcmp(newtable[hval], "\0") == 0)
				newtable[hval] = table[i];
			else
			{
				while (strcmp(newtable[hval], "\0") != 0)
					hval = (hval + 1) % size;
				newtable[hval] = table[i];
			}
		}
	}
	delete[] table;
	table = newtable;
}

int HashTable::nextPrime(int num)
{
	bool found = false;
	int newnum = num;
	while (!found)
	{
		found = true;
		for (int i = 2; i <= (newnum / 2); i++)
		{
			if (newnum % i == 0)
				found = false;
		}
		if (found)
			return newnum;
		else
			newnum++;
	}
}

void HashTable::insert(char* in)
{
	if ((float)numtaken / (float)size > 0.67)
		rehash(size);
	int val = hash(in);
	int hval = val % size;
	if (strcmp(table[hval], "\0") == 0)
	{
		table[hval] = in;
	}
	else
	{
		while (strcmp(table[hval], "\0") != 0)
			hval = (hval + 1) % size;
		table[hval] = in;
	}
	numtaken++;
}

bool HashTable::find(char* in)
{
	int val = hash(in);
	int hval = val % size;
	if (strcmp(in, table[hval]) == 0)
		return true;
	else
	{
		while (strcmp(table[hval], "\0") != 0)
		{
			hval = (hval + 1) % size;
			if (strcmp(in, table[hval]) == 0)
				return true;
		}
		return false;
	}
}

void HashTable::printTable()
{
	for (int i = 0; i < size; i++)
		std::cout << i << ": " << table[i] << std::endl;
}

HashTable::~HashTable()
{
	delete[] table;
}

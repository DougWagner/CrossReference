#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <iostream>
class HashTable
{
private:
	char **table;
	int size;
	int numtaken;
	int hash(char*);
	void rehash(int);
	int nextPrime(int);	//used only for rehash function - also quite inefficient but whatever.
public:
	HashTable();
	void insert(char*);
	bool find(char*);
	void printTable();
	~HashTable();
};
#endif

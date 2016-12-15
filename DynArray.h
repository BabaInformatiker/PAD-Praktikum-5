#pragma once
#include "Lied.h"

class DynArray
{
private:
	void resize(int newCapacity);
	DynArray(const DynArray& other); 
	Lied* m_data;
	int m_size;
	int m_capacity;

public:
	DynArray();
	DynArray(int newCapacity); 
	~DynArray(); 
	Lied& at(int index);
	void push_back(Lied elem);
	void pop_back();
	void erase(int index);
	int size();
	int capacity();
	void print();
        void print(int index);
        void edit(int index, Lied elem);
};

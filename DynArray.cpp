#include <iostream>
#include "DynArray.h"
#include <iostream>

using namespace std;

DynArray::DynArray() { 
	m_capacity = 2;
	m_size = 0;
	m_data = new Lied[m_size];

}

DynArray::DynArray(int newcapacity) {
	m_capacity = newcapacity;
	m_size = m_capacity / 2;

}

DynArray::~DynArray() {
	delete[] m_data;
}

int DynArray::size(){
	return m_size;
}

int DynArray::capacity() {
	return m_capacity;
}

/* void DynArray::print() {
	for (int i = 0; i < m_size; i++) {
		cout << m_data[i];
	}
}
*/

void DynArray::resize(int newcapacity) {
	Lied* copy = new Lied[newcapacity];

	for (int i = 0; i < m_size; i++)
		copy[i] = m_data[i];

	delete[] m_data;
	m_data = copy;
	delete[] copy;
}

void DynArray::push_back(Lied elem) {
	if (m_size = m_capacity)
		resize(m_size * 2);

	m_data[m_size + 1] = elem;
}

void DynArray::pop_back() {
	Lied* copy = new Lied[m_size - 1];

	for (int i = 0; i < m_size - 1; i++)
		copy[i] = m_data[i];

	delete[] m_data;
	m_data = copy;
	delete[] copy;
}

void DynArray::erase(int index) {
	Lied* copy = new Lied[m_size - 1];
	cin >> index;

	for (int i = 0; i < m_size; i++) {
		if (i == index)
			continue;
		else
			copy[i] = m_data[i];
	}

	delete[] m_data;
	m_data = copy;
	delete[] copy;
}

int main() {

	DynArray a(1);

	Lied li;
	Lied s;
	Lied l;

	li.zahl = 10;
	s.zahl = 15;
	l.zahl = 20;


	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	system("pause");
	return 0;
}

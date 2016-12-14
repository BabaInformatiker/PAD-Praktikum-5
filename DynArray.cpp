#include <iostream>
#include "DynArray.h"
#include <iostream>

using namespace std;


  
DynArray::DynArray() { 
	m_capacity = 2;
	m_size = 0;
	m_data = new Lied[m_capacity];
}

DynArray::DynArray(int newCapacity) {
	m_capacity = newCapacity;
	m_size = 0;
        m_data = new Lied[m_capacity];
}

DynArray::~DynArray() {
    delete[] m_data;
    m_data = NULL;
}

DynArray::DynArray(const DynArray& other){
    m_capacity = other.m_capacity;
    m_data = new Lied[m_capacity];
    for (int i = 0; i < m_capacity; i++)
        m_data[i] = other.m_data[i];
} 

int DynArray::size(){
	return m_size;
}

int DynArray::capacity() {
	return m_capacity;
}

void DynArray::print() {
	for (int i = 0; i < m_size; i++) {
		cout << m_data[i].zahl << endl;
	}
}


void DynArray::resize(int newCapacity) {
        Lied* copy = new Lied[newCapacity];
        
	for (int i = 0; i < m_size; i++)
		copy[i] = m_data[i];

	delete[] m_data;
	m_data = copy;
        m_capacity = newCapacity; 
}

void DynArray::push_back(Lied elem) {
    if (m_capacity == 0)
        m_capacity = 1;
    if (m_size == m_capacity)
		resize(m_capacity + m_size);

	m_data[m_size] = elem;
        m_size += 1;
}

void DynArray::pop_back() {
	Lied* copy = new Lied[m_size - 1];

	for (int i = 0; i < m_size - 1; i++)
		copy[i] = m_data[i];

	delete[] m_data;
	m_data = copy;
        m_size -= 1;
}

void DynArray::erase(int index) {
	Lied* copy = new Lied[m_size - 1];

	for (int i = 0; i < m_size; i++) {
            if (i < index)
                copy[i] = m_data[i];
            
            if (i == index)
			continue;
            if (i > index)
            copy[i-1] = m_data[i];
	}

	delete[] m_data;
	m_data = copy;
        m_size -= 1;
	
}

/* Lied& DynArray::at(int index){
    return double& m_data[index]; 
} */

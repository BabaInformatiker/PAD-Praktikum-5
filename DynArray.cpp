#include <iostream>
#include "DynArray.h"
#include "Lied.h"
#include <string>


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
		cout << i+1 << ". Eintrag" <<endl;
                cout << "Titel: " << m_data[i].titel << endl;
                cout << "Interpret: " <<m_data[i].interpret << endl;
                cout << "Erscheinungsjahr: " << m_data[i].erscheinungsjahr << endl;
                cout << "Laenge: " << m_data[i].laenge << endl;
                //cout << "Genre: " << m_data[i].g << endl;
                if (m_data[i].g == 0)
                    cout << "Genre: Pop" << endl;
                if (m_data[i].g == 1)
                    cout << "Genre: Rock" << endl;
                if (m_data[i].g == 2)
                    cout << "Genre: Klassik" << endl;
                if (m_data[i].g == 3)
                    cout << "Genre: Hard Rock" << endl;
                cout << endl;
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
    
   
    cout << "Bitte den Titel eingeben: ";
    cin >> elem.titel;
    cout << "Bitte den Interpreten eingeben: ";
    cin >> elem.interpret;
    cout << "Bitte das Erscheinungsjahr eingeben: ";
    cin >> elem.erscheinungsjahr;
    cout << "Bitte die Laenge eingeben: ";
    cin >> elem.laenge;
    cout << "Bitte das Genre angeben: ";
    string k;
        cin >> k;
        if (k == "pop") { elem.g = pop; }
        if (k == "rock") { elem.g = rock; }
        if (k == "klassik") { elem.g = klassik; }
        if (k == "hard rock") { elem.g = hard_rock; }
 
    
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
        index -= 1;
        
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


void DynArray::print(int index){
		cout << index << ". Eintrag" <<endl;
                index -= 1;
                cout << "Titel: " << m_data[index].titel << endl;
                cout << "Interpret: " <<m_data[index].interpret << endl;
                cout << "Erscheinungsjahr: " << m_data[index].erscheinungsjahr << endl;
                cout << "Laenge: " << m_data[index].laenge << endl;
                if (m_data[index].g == 0)
                    cout << "Genre: Pop" << endl;
                if (m_data[index].g == 1)
                    cout << "Genre: Rock" << endl;
                if (m_data[index].g == 2)
                    cout << "Genre: Klassik" << endl;
                if (m_data[index].g == 3)
                    cout << "Genre: Hard Rock" << endl;
                cout << endl;
        
    
}

void DynArray::edit(int index, Lied elem){
        string k;
        string y;
        int x;

        cout << "Was moechten sie bearbeiten?: ";
        cin >> y;
       
       
        if (y == "titel" | y == "Titel") {
            cout << "Bitte den Titel eingeben: ";
            cin >> k;   
            m_data[index-1].titel = k;
        }
 
        if (y == "interpret" | y == "Interpret") {
            cout << "Bitte den Interpreten eingeben: ";
            cin >> k;
            m_data[index-1].interpret = k;
        }
 
        if (y == "erscheinungsjahr") {
            cout << "Bitte das Erscheingungsjahr eingeben: ";
            cin >> x;  
            m_data[index-1].erscheinungsjahr = x;
        }
 
        if (y == "laenge") {
            cout << "Bitte die Laenge des Liedes angeben: ";
            cin >> x;
            m_data[index-1].laenge = x;
        }
 
        if (y == "genre") {
            cout << "Bitte geben sie das Genre an: ";
            cin >> k;
            if (k == "pop") { m_data[index-1].g = pop; }
            if (k == "rock") { m_data[index-1].g = rock; }
            if (k == "klassik") { m_data[index-1].g = klassik; }
            if (k == "hard rock") { m_data[index-1].g = hard_rock; }
            
        }
    
    
}

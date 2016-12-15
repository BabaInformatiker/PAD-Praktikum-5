#include <iostream>
#include <string>
#include <vector>
#include "DynArray.h"

using namespace std;


int menue() {
    Lied li;
    string eingabe;
    DynArray songs(1);
    int k;
 
    
   
    while (true) {
        cout << "*********** Musikbibliothek Version 0.1**********" << endl;
        cout << "Hauptmenue:" << endl;
        cout << "1. (N)euen Eintrag anlegen" << endl;
        cout << "2. (D)etails eines Eintrags anzeigen" << endl;
        cout << "3. Einen Eintrag (l)oeschen" << endl;
        cout << "4. Einen Eintrag (b)earbeiten" << endl;
        cout << "5. Einen Eintrag (s)uchen" << endl;
        cout << "6. (A)lle Eintraege anzeigen" << endl;
        cout << " " << endl;
        cout << "0. Programm beenden" << endl;
        cin >> eingabe;
 
        if (eingabe == "1" | eingabe == "n" | eingabe == "N") {
            cout << "Sie befinden sich im Menuepunkt Neuen Eintrag anlegen" << endl;
            songs.push_back(li);
        }
        if (eingabe == "2" | eingabe == "d" | eingabe == "D") {
            cout << "Sie befinden sich im Menuepunkt Details eines Eintrags anzeigen" << endl;
            cout << "Welchen Eintrag moechten sie sich ansehen?: ";
            cin >> k;
            songs.print(k);
        }
        if (eingabe == "3" | eingabe == "l" | eingabe == "L") {
            cout << "Sie befinden sich im Menuepunkt Einen Eintrag loeschen" << endl;
            cout << "Welchen Eintrag moechten sie loeschen?: " << endl;
            cin >> k;
            songs.erase(k);
        }
        if (eingabe == "4" | eingabe == "b" | eingabe == "B") {
            cout << "Sie befinden sich im Menuepunkt Einen Eintrag bearbeiten" << endl;
            cout << "Welchen Eintrag moechten sie bearbeiten?: " << endl;
            cin >> k;
            songs.edit(k, li);
        }
        if (eingabe == "5" | eingabe == "s" | eingabe == "S") {
            cout << "Sie befinden sich im Menuepunkt Einen Eintrag suchen" << endl;
        }
        if (eingabe == "6" | eingabe == "a" | eingabe == "A") {
            cout << "Sie befinden sich im Menuepunkt Alle Eintraege anzeigen" << endl;
            songs.print();
        }
        if (eingabe == "0") {
            return 0;
        }
        //menue();
    }
}
 
int main() {
    
    
    menue();
 
 
    
    return 0;
}

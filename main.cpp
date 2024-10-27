#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

int select_goat(list<Goat> trip);
void delete_goat(list<Goat> &trip);
void add_goat(list<Goat> &trip, string [], string []);
void display_trip(list<Goat> trip);
int main_menu();

int main() {
    srand(time(0));
    list<Goat> trip; //list to store goat objects
    int choice; 

    bool again;

    // read & populate arrays for names and colors
    ifstream fin("names.txt");
    string names[SZ_NAMES];
    int i = 0;
    while (fin >> names[i++]);
    fin.close();
    
    ifstream fin1("colors.txt");
    string colors[SZ_COLORS];
    i = 0;
    while (fin1 >> colors[i++]);
    fin1.close();

    //menu loop
    do {
        choice = main_menu();
        if (choice == 4) {
            cout << "Exiting program";
        } else {
            cout << "Selected option: " << endl;
        }
        return 0;
    }

int main() {
    cout << " Goat Manager 3001";
    cout << "Add a goat";
    cout << "List goat";
    cout << "Quit";
    cin >> choice;

    return choice;

}





    return 0;
}


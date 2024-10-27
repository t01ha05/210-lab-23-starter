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
        switch (choice) {
            case 1:
                add_goat(trip,names,colors);
                break;        
            case 2:
                delete_goat(trip);
                break;
            case 3:
                display_trip(trip);
                break;
            case 4:
                cout << "Exit program"
                break;
        }  
    } while (choice !=4);

        return 0;
    }

//menu function
int main_menu() {
    cout << " Goat Manager 3001";
    cout << "Add a goat";
    cout << "Delete a goat";
    cout << "List goat";
    cout << "Quit";
    cin >> choice;

    if (choice > 1 && choice < 4) {
        cout << "Invalid. Enter a number from 1-4";
    }
    
    if (input_invalid) {
        cout << "Error: Invalid input";
    }

    return choice;

}


    return 0;
}


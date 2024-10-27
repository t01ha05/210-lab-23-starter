#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

//reorganize for readability
void add_goat(list<Goat> &trip, string names[], string colors[]);
void delete_goat(list<Goat> &trip);
void display_trip(list<Goat> trip);
int main_menu();

int main() {
    srand(time(0));
    list<Goat> trip; //list to store goat objects
    string names[SZ_NAMES] = ["Ella", "Inga"];
    string colors[SZ_COLORS] = {"Red", "Blue"};
    
    // read & populate arrays for names and colors
    ifstream fin("names.txt");
    string names[SZ_NAMES];
    int i = 0;
    while (fin >> names[i++] && i < SZ_NAMES) {
        i++;
    }
    fin.close();
    
    ifstream fin1("colors.txt");
    i = 0;
    while (fin1 >> colors[i] && i < SZ_COLORS) { //added boundary check
        i++;
    } 
    fin1.close();

    //menu loop
    int choice;
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
                cout << "Exit program";
                break;
        }  
    } while (choice !=4);

     return 0;
}

//menu function
int main_menu() {
    int choice;
    bool valid = false;
    
while(!valid) {
    cout << " Goat Manager 3001";
    cout << "Add a goat";
    cout << "Delete a goat";
    cout << "List goat";
    cout << "Quit";
    cout << "Choice -->"
    cin >> choice;

    if (cin.fail() || choice < 1 || choice > 4) {
        cin.clear();
        cin.ignore(1000); //ignore invalid input
        cout << "Invalid input. Enter from 1-4";
    } else {
        valid = true;
    }
}
   return choice;
}




void add_goat(list<Goat> &trip, string names[], string colors[]) {
    int rand_name = rand() % SZ_NAMES;
    int rand_color = rand() % SZ_COLORS;
    int age = rand() % MAX_AGE + 1;

    //create new goat objecty
    Goat new_goat(names[rand_name], age, colors[rand_color]);
    trip.push_back(new_goat);

     cout << "Goat added: " << names[rand_name] << "Color: " << colors[rand_color] << ", Age: " << age;
     cout << "Total goats: " << trip.size();
}

//function to delete goat from list
void delete_goat(list<Goat> &trip) {
    if(trip.empty()) {
        cout << "No goat to delete";
        return;
    }

    int index;
    cout << "enter how many goats to delete";
    cin >> index;

    auto it = trip.begin();
    advance(it, index);

    trip.erase(it);
    cout << "Goat deleted";
}

void display_trip(list<Goat> &trip) {
    if(trip.empty()) {
        cout << "No goats in the trip";
        return;
    }
    int count = 0;
    for(auto goat : trip) {
        cout << "Goat " << count << ": "
            << goat.get_name() << " (Age: << goat.get_age() << ")\n";
        count++;
    }
}
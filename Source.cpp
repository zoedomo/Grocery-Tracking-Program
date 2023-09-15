// Zoe Domagalski
// 4/10/2023
//Project 3

#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

//declaring grocery class
class Grocery {
private:
    map<string, int> items; //map to store items and frequencies

public:
    Grocery() { //constructor to read input file and initialize the items map
        ifstream file("CS210_Project_Three_Input_File.txt"); //opening input file
        if (!file.is_open()) {
            cout << "Error: File not found!" << endl; //error for user when item they entered isnt found
            return;
        }
        string item;
        while (file >> item) {
            items[item]++; //incrementing frequency count for each item
        }
        file.close(); //closing file
        ofstream backup("frequency.dat"); //opening output file for backup
        if (backup.is_open()) {
            for (auto it = items.begin(); it != items.end(); ++it) {
                backup << it->first << " " << it->second << endl; //writing item name and frequncy to output file (output file is created in the beginning of the program without user intervention)
            }
            backup.close(); //closing output
        }
    }

    //function to search for item
    void searchItem() {
        string item;
        cout << "Enter item name: ";
        cin >> item;
        if (items.count(item) > 0) { //checking if item is in items map
            cout << item << " " << items[item] << endl << endl;
        }
        else {
            cout << "Invalid Input!\n" << endl;
        }
    }

    //function to print all items and their frequencies
    void printList() {
        for (auto it = items.begin(); it != items.end(); ++it) {
            cout << it->first << " " << it->second << endl; //printing each item and frequencies
        }
        cout << endl;
    }

    //function to print histogram of the items using asterisks
    void printHistogram() {
        for (auto it = items.begin(); it != items.end(); ++it) {
            cout << it->first << " ";
            for (int i = 0; i < it->second; ++i) {
                cout << "*"; //printing each itam name and * for frequencies
            }
            cout << endl;
        }
        cout << endl;
    }
};

int main() {
    int choice;
    Grocery grocery;
    do { //Menu for user to choose a number
        cout << "Menu:" << endl;
        cout << "1. Search Item" << endl;
        cout << "2. Print List" << endl;
        cout << "3. Print Histogram" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter Menu Number: ";
        cin >> choice; // user input for number selection 
        cout << endl;
        switch (choice) {
        case 1:
            grocery.searchItem(); //calling searchItem()
            break;
        case 2:
            grocery.printList(); //calling printList()
            break;
        case 3:
            grocery.printHistogram(); //calling printHistogram()
            break;
        case 4:
            cout << "Exit Program." << endl; //output message for when the user exits program
            break;
        default:
            cout << "Invalid Option!" << endl; //output when user picks wrong number selection
            break;
        }
    } while (choice != 4); //loops menu until user exits (number 4)
    return 0;
}


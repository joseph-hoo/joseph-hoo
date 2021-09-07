/*
    Joseph Hoover
    Lab 06
    18 June 2021
    This Lab is to replace Lab 04
*/

#include <iostream>
#include "Currencies.h"
#include "HashTable.h"

using namespace std;

int main()
{
    // create dollar values
    USD USD1;
    USD1.setNoteVal(57);
    USD1.setCoinVal(12);

    USD USD2;
    USD2.setNoteVal(23);
    USD2.setCoinVal(44);

    USD USD3;
    USD3.setNoteVal(87);
    USD3.setCoinVal(43);

    USD USD4;
    USD4.setNoteVal(68);
    USD4.setCoinVal(99);

    USD USD5;
    USD5.setNoteVal(111);
    USD5.setCoinVal(22);

    USD USD6;
    USD6.setNoteVal(44);
    USD6.setCoinVal(55);

    USD USD7;
    USD7.setNoteVal(77);
    USD7.setCoinVal(77);

    USD USD8;
    USD8.setNoteVal(18);
    USD8.setCoinVal(36);

    USD USD9;
    USD9.setNoteVal(543);
    USD9.setCoinVal(21);

    USD USD10;
    USD10.setNoteVal(20);
    USD10.setCoinVal(21);

    USD USD11;
    USD11.setNoteVal(345);
    USD11.setCoinVal(67);

    USD USD12;
    USD12.setNoteVal(36);
    USD12.setCoinVal(18);

    USD USD13;
    USD13.setNoteVal(48);
    USD13.setCoinVal(48);

    USD USD14;
    USD14.setNoteVal(101);
    USD14.setCoinVal(0);

    USD USD15;
    USD15.setNoteVal(11);
    USD15.setCoinVal(0);

    USD USD16;
    USD16.setNoteVal(21);
    USD16.setCoinVal(0);

    USD USD17;
    USD17.setNoteVal(51);
    USD17.setCoinVal(0);

    USD USD18;
    USD18.setNoteVal(1);
    USD18.setCoinVal(0);

    USD USD19;
    USD19.setNoteVal(251);
    USD19.setCoinVal(0);

    USD USD20;
    USD20.setNoteVal(151);
    USD20.setCoinVal(0);

    HashTable h1;
    
  
    h1.hashInsert(h1.getArr(), USD1);
    h1.hashInsert(h1.getArr(), USD2);
    h1.hashInsert(h1.getArr(), USD3);
    h1.hashInsert(h1.getArr(), USD4);
    h1.hashInsert(h1.getArr(), USD5);

    h1.hashInsert(h1.getArr(), USD6);
    h1.hashInsert(h1.getArr(), USD7);
    h1.hashInsert(h1.getArr(), USD8);
    h1.hashInsert(h1.getArr(), USD9);
    h1.hashInsert(h1.getArr(), USD10);

    h1.hashInsert(h1.getArr(), USD11);
    h1.hashInsert(h1.getArr(), USD12);
    h1.hashInsert(h1.getArr(), USD13);
    h1.hashInsert(h1.getArr(), USD14);
    h1.hashInsert(h1.getArr(), USD15);

    h1.hashInsert(h1.getArr(), USD16);
    h1.hashInsert(h1.getArr(), USD17);
    h1.hashInsert(h1.getArr(), USD18);
    h1.hashInsert(h1.getArr(), USD19);
    h1.hashInsert(h1.getArr(), USD20);

    //print array to check
    h1.printHash();

    // user input to search for dollar in array
    bool timeToQuit = false;
    char userChoice = '-';


    USD tempToFind;
    while (timeToQuit != true) {
        cout << "Enter the note value of the object to search: ";
        int noteToFind;
        cin >> noteToFind;
        cout << endl;

        cout << "Enter the coin value of the object to search: ";
        int coinToFind;
        cin >> coinToFind;
        cout << endl;

        tempToFind.setNoteVal(noteToFind);
        tempToFind.setCoinVal(coinToFind);

        if (h1.hashSearch(tempToFind) == true) {
            // object exists in array
        }
        else {
            cout << tempToFind << "Invalid Data" << endl;
        }

        cout << "Do you want to quit? y/n" << endl;
        cin >> userChoice;
        userChoice = tolower(userChoice);
        if (userChoice == 'n') {
            timeToQuit = false;
        }
        if (userChoice == 'y') {
            timeToQuit = true;
        }

        while (userChoice != 'y' && userChoice != 'n') {
            cout << "you must enter 'y'/'Y' or 'n'/'N'" << endl;
            cout << "Do you want to quit? y/n" << endl;
            cin >> userChoice;
            userChoice = tolower(userChoice);
            if (userChoice != 'y' && userChoice != 'n') {
                cout << "Invalid entry" << endl;
            }
            if (userChoice == 'n') {
                timeToQuit = false;
            }
            if (userChoice == 'y') {
                timeToQuit = true;
            }
        }

    }

    // print secordary hash info
    h1.printHashInfo();
}


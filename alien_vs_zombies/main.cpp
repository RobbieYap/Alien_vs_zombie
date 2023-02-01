// ********************************************************* 
// Course: TCP1101 PROGRAMMING FUNDAMENTALS 
// Year: Trimester 1, 2022/23 (T2215) 
// Lab: T12L
// Names: Yap Tze Lam, Robbie | Sri Raam | Danish Haziq
// IDs: 1211101662 | 1211102757 | 1221302704
// Emails: 1211101662@student.mmu.edu.my | 1211102757@student.mmu.edu.my | 1221302704@student.mmu.edu.my
// Phones: 0122916488 | 0123861410 | 017-247 8911
// ********************************************************* 

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> // for system()
#include <ctime> // for time() in srand( time(NULL) );
#include <iomanip> // for setw()
using namespace std;
class Mars
{
private:
    vector< vector<char> > map_; // convention to put trailing underscore
    int dimX_, dimY_; // to indicate private data

public:
    Mars(int dimX = 15, int dimY = 5);
    void init(int dimX, int dimY);
    void display() const;
};

Mars::Mars(int dimX, int dimY)
{
    init(dimX, dimY);
}
void Mars::init(int dimX, int dimY)
{
    dimX_ = dimX;
    dimY_ = dimY;

    char objects[] = {' ', ' ', ' ', ' ', ' ', ' ', 'X', '#', '@', '$'};
    int noOfObjects = 10; // number of objects in the objects array

    // create dynamic 2D array using vector
    map_.resize(dimY_); // create empty rows
    for (int i = 0; i < dimY_; ++i)
    {
        map_[i].resize(dimX_); // resize each row
    }
    // put random characters into the vector array
    for (int i = 0; i < dimY_; ++i)
    {
        for (int j = 0; j < dimX_; ++j)
        {
            int objNo = rand() % noOfObjects;
            map_[i][j] = objects[objNo];
        }
    }
}

void Mars::display() const
{
    // comment this out during testing
    // system("cls"); // OR system("clear"); for Linux / MacOS

    cout << " --__--__--__--__--__--__--__--_" << endl;
    cout << " =       Alien vs Zombies      =" << endl;
    cout << " __--__--__--__--__--__--__--__-" << endl;
    
    // for each row
    for (int i = 0; i < dimY_; ++i)
    {

        // display upper border of the row
        cout << "  ";
        for (int j = 0; j < dimX_; ++j)
        {
            cout << "+-";
        }
        cout << "+" << endl;

        // display row number
        cout << setw(2) << (dimY_ - i);

        // display cell content and border of each column
        for (int j = 0; j < dimX_; ++j)
        {
            cout << "|" << map_[i][j];
        }
        cout << "|" << endl;
    }

    // display lower border of the last row
    cout << "  ";
    for (int j = 0; j < dimX_; ++j)
    {
        cout << "--";
    }
    cout << "+" << endl;

    // display column number
    cout << "  ";
    for (int j = 0; j < dimX_; ++j)
    {
        int digit = (j + 1) / 10;
        cout << " ";
        if (digit == 0)
            cout << " ";
        else
            cout << digit;
    }
    cout << endl;
    cout << "  ";
    for (int j = 0; j < dimX_; ++j)
    {
        cout << " " << (j + 1) % 10;
    }
    cout << endl << endl;

    
}

void test1_1()
{
    Mars mars;
    int choice;

    cout << "Welcome to Alien VS Zombies!" << endl;
    cout << "1. New Game" << endl;
    cout << "2. Load Game" << endl;
    cout << "3. Customize Settings" << endl;
    cout << "4. Quit" << endl;
    cout << "Enter your choice: ",    cin >> choice;

    switch (choice) {
        case 1:
            cout << "Starting a new game..." << endl;
            mars.display();
            // code to start a new game
            break;
        case 2:
            cout << "Loading game..." << endl;
            // code to load a saved game
            break;
        case 3:
            cout << "Opening settings..." << endl;
            // code to open settings menu
            break;
        case 4:
            cout << "Quitting game..." << endl;
            // code to quit the game
            break;
        default:
            cout << "Invalid choice. Quitting game..." << endl;
            // code to quit the game
            break;
    }
    return ;
}

int main()
{
    srand(1);              // use this for fixed map during testing
    // srand(time(NULL)); // try this for random map

    test1_1();
}
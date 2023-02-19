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
#include <fstream>
#include <cstdlib>
#include <bits/stdc++.h>
using namespace std;

void displayMenu()
{
    cout << "********************" << endl;  
    cout << "*      WELCOME     *" << endl;
    cout << "*  Alien vs Zombie *" << endl;
    cout << "*                  *" << endl;
    cout << "* Please Begin:    *" << endl;
    cout << "*  1 = Start game  *" << endl;
    cout << "*                  *" << endl;
    cout << "*  Q = Quit        *" << endl;
    cout << "********************" << endl;
    cout << endl;
    cout << "Option = ";
}


void gameboard(int row, int col, int zombie, char *random, int alienLife, int alienAttack, int *zombieData, int turn)
{
    int r;
    int c;
    int z = 0;
    int n;
    char ran;
    int w = (col * 2 - 19) / 2;
    for (c = 0; c < w; c++)
    {
        cout << " ";
    }
    cout << ".: Alien vs Zombie :." << endl;
    for (r = 0; r < row; r++)
    {
        cout << " ";
        if (row > 9)
        {
            cout << " ";
        }
        for (c = 0; c < col; c++)
        {
            cout << "+-";
        }
        cout << "+" << endl;
        if (row > 9 && r < 9)
        {
            cout << " ";
        }
        cout << r + 1;
        for (c = 0; c < col; c++)
        {
            cout << "|";
            cout << *(random + r * col + c);
        }
        cout << "|" << endl;
    }
    cout << " ";
    if (row > 9)
    {
        cout << " ";
    }
    for (c = 0; c < col; c++)
    {
        cout << "+-";
    }
    cout << "+" << endl;
    int tens = (col - 10) / 10;
    int dec = col % 10;
    int t = 1;
    int d;
    if (col > 10)
    {
        if (row > 10)
        {
            cout << " ";
        }
        cout << "  ";
        for (c = 0; c < 9; c++)
        {
            cout << "  ";
        }
        for (t = 0; t < tens; t++)
        {
            for (c = 0; c < 10; c++)
            {
                cout << t + 1 << " ";
            }
        }
        for (d = 0; d <= dec; d++)
        {
            cout << t + 1 << " ";
        }
        cout << endl;
        if (row > 10)
        {
            cout << " ";
        }
        cout << " ";
        int m = 1;
        for (m = 0; m <= tens; m++)
        {
            for (c = 1; c < 10; c++)
            {
                cout << " " << c;
            }
            cout << " 0";
        }
        for (d = 1; d <= dec; d++)
        {
            cout << " " << d;
        }
    }
    else
    {
        if (row > 10)
        {
            cout << " ";
        }
        cout << "  ";
        for (d = 1; d <= dec; d++)
        {
            cout << d << " ";
        }
    }
    cout << endl << endl;
    string arrowtowhoseturn = "";
    if (turn == -1)
    {
        arrowtowhoseturn = "-> ";
    }
    cout << setw(3) << arrowtowhoseturn;
    cout << "Alien   : Life " << setw(3) << alienLife << ", Attack " << setw(3) << alienAttack << endl;
    arrowtowhoseturn = "";
    for (z = 0; z < zombie; z++)
    {
        if (turn == z)
        {
            arrowtowhoseturn = "-> ";
        }
        cout << setw(3) << arrowtowhoseturn;
        cout << "Zombie " << z + 1 << ": Life " << setw(3) << *(zombieData + z * 6) << ", Attack " << setw(3) << *(zombieData + z * 6 + 1) << setw(2) << ", Range " << *(zombieData + z * 6 + 2) << endl;
        arrowtowhoseturn = "";
    }
    cout << endl;
}

void help()
{
    cout << "Command                      " << endl;
    cout << "up        - move up." << endl;
    cout << "down      - move down." << endl;
    cout << "left      - move left." << endl;
    cout << "right     - move right." << endl;
    cout << "arrow     - Change the direction of an arrow" << endl;
    cout << "help      - Display commands" << endl;
    cout << "quit      - Quit the game" << endl;
    // system("pause");
    cout << endl;
    cout << "Press any key to continue . . .";
    string cintocontinue;
    cin >> cintocontinue;
}

void alienmove(char com, bool &win, int row, int col, char *random)
{
    bool movedone = false;
    int variable1, variable2;
    char going;
    for (int r = 0; r < row; r++)
    {
        for (int c = 0; c < col; c++)
        {
            char A = *(random + r * col + c);
            if (A == 'A')
            {
                variable1 = r;
                variable2 = c;
            }
        }
    }
    while (!movedone)
    {
        switch (com)
        {
        // go to the next place in the board
        case '^':
            going = *(random + (variable1 - 1) * col + variable2);
            cout << going;
            break;
        case 'v':
            going = *(random + (variable1 + 1) * col + variable2);
            cout << going;
            break;
        case '<':
            break;
        case '>':
            break;
        }
        // check the spot in the spot
        switch (going)
        {
        case '^':
            com = '^';
            break;
        case 'v':
            going = *(random + (variable1 + 1) * col + variable2);
            cout << going;
            break;
        case '<':
            break;
        case '>':
            break;
        }
        // starts moving
    }
}

void alien(int &alienLife, int &alienAttack)
{
    alienLife = 100;
    alienAttack = 0;
}

void load()
{
    cout << "Still in Progress :(" << endl;
}

void save()
{
    cout << "Still in Progress :(" << endl;
}

void game(int row, int col, int zombie)
{
    bool win = false;
    bool zombiedead = false;
    bool playerquit = false;
    char com, ran;
    int turn;
    int r, c, z;
    int alienLife = 0;
    int alienAttack = 0;
    int zombiedeadnum = 0;
    int zlife, zattack, range;
    vector<char> object = {'^', 'v', '<', '>', 'h', 'p', 'r', ' '};
    vector<char> norock = {'^', 'v', '<', '>', 'h', 'p', ' '};
    char random[row][col];
    int zombdata[zombie][6]; //life attack range zombieinrange(for pod) row column
    srand(time(NULL));
    int o = object.size();
    int nrock = norock.size();
    cout << " ";
    if (row > 9)
    {
        cout << " ";
    }
    for (r = 0; r < row; r++)
    {
        for (c = 0; c < col; c++)
        {
            ran = object[rand() % o];
            random[r][c] = ran;
        }
    }

    random[row / 2][col / 2] = 'A';

    for (z = 0; z < zombie;)
    {
        r = rand() % row;
        c = rand() % col;
        if ((random[r][c] == 'A') || (random[r][c] == 'Z'))
        {
        }
        else
        {
            random[r][c] = 'Z';
            zombdata[z][4] = r;
            zombdata[z][5] = c;
            z += 1;
        }
    }

    for (int z = 0; z < zombie; z++)
    {
        char zombienumber = char(49 + z);
        int zr = zombdata[z][4];
        int zc = zombdata[z][5];
        random[zr][zc] = zombienumber;
    }
    alien(alienLife, alienAttack);

    // zombie data
    for (z = 0; z < zombie; z++)
    {
        zlife = ((rand() % 4) * 50 + 100);
        zombdata[z][0] = zlife;
        zattack = ((rand() % 3) * 5 + 5);
        zombdata[z][1] = zattack;
        range = ((rand() % 3) + 1);
        zombdata[z][2] = range;
    }

    do
    {
        bool turn = false;
        string command;
        char com;
        do
        {
            int arrowrow, arrowcolumn;
            char direction;
            bool arrowdone = false;
            while (!arrowdone)
            {
                turn = -1;
                gameboard(row, col, zombie, (char *)random, alienLife, alienAttack, (int *)zombdata, turn);
                cout << "command> ";
                cin >> command;
                if (command == "arrow")
                {
                    cout << "Enter row, column, and direction: ";
                    cin >> arrowrow >> arrowcolumn >> direction;
                    // cout << arrowrow << arrowcolumn << direction;
                    if (random[arrowrow - 1][arrowcolumn - 1] == '^' || random[arrowrow - 1][arrowcolumn - 1] == 'v' || random[arrowrow - 1][arrowcolumn - 1] == '<' || random[arrowrow - 1][arrowcolumn - 1] == '>')
                    {
                        switch (direction)
                        {
                        case 'u':
                            random[arrowrow - 1][arrowcolumn - 1] = '^';
                            break;
                        case 'd':
                            random[arrowrow - 1][arrowcolumn - 1] = 'v';
                            break;
                        case 'l':
                            random[arrowrow - 1][arrowcolumn - 1] = '<';
                            break;
                        case 'r':;
                            random[arrowrow - 1][arrowcolumn - 1] = '>';
                            break;
                        }
                        cin >> command;
                    }
                    else
                    {
                        cout << "That is not an arrow.";
                        cin >> command;
                    }
                }
                else if (command == "up")
                {
                    com = '^';
                    arrowdone = true;
                }
                else if (command == "down")
                {
                    com = 'v';
                    arrowdone = true;
                }
                else if (command == "left")
                {
                    com = '<';
                    arrowdone = true;
                }
                else if (command == "right")
                {
                    com = '>';
                    arrowdone = true;
                }
                else if (command == "save")
                {
                    save();
                }
                else if (command == "load")
                {
                    load();
                }
                else if (command == "quit")
                {
                    playerquit = true;
                    break;
                }
                else
                {
                    help();
                }
            }

            if (playerquit == false)
            {
                bool movedone = false;
                int ar, ac;
                char going;
                for (int r = 0; r < row; r++)
                {
                    for (int c = 0; c < col; c++)
                    {
                        char A = random[r][c];
                        if (A == 'A')
                        {
                            ar = r;
                            ac = c;
                        }
                    }
                }
                int gr, gc;
                while (!movedone)
                {
                    switch (com)
                    {
                    // get going palce
                    case '^':
                        gr = ar - 1;
                        gc = ac;
                        going = random[gr][gc];
                        break;
                    case 'v':
                        gr = ar + 1;
                        gc = ac;
                        going = random[gr][gc];
                        break;
                    case '<':
                        gr = ar;
                        gc = ac - 1;
                        going = random[gr][gc];
                        break;
                    case '>':
                        gr = ar;
                        gc = ac + 1;
                        going = random[gr][gc];
                        break;
                    }
                    // done

                    // check going place
                    char nextcommand;
                    string alienstatus, zombielifedamage, zombiestatus;

                    switch (going)
                    {
                    case '^':
                        alienstatus = "Alien finds an arrow.\nAlien's attack receives a buff by 20!\n";
                        alienAttack = alienAttack + 20;
                        nextcommand = '^';
                        break;
                    case 'v':
                        alienstatus = "Alien finds an arrow.\nAlien's attack receives a buff by 20!\n";
                        alienAttack = alienAttack + 20;
                        nextcommand = 'v';
                        break;
                    case '<':
                        alienstatus = "Alien finds an arrow.\nAlien's attack receives a buff by 20!\n";
                        alienAttack = alienAttack + 20;
                        nextcommand = '<';
                        break;
                    case '>':
                        alienstatus = " Alien finds an arrow.\nAlien's attack is receives a buff by 20!\n";
                        alienAttack = alienAttack + 20;
                        nextcommand = '>';
                        break;
                    case 'h':
                        nextcommand = com;
                        alienLife = alienLife + 20;
                        if (alienLife > 100)
                        {
                            alienLife = 100;
                            alienstatus = "Alien finds a health pack, alien gets a 20hp increase!\nAlien's health is capped at 100.\n";
                        }
                        else
                        {
                            alienstatus = "Alien finds a health pack, alien's gets a 20hp increase!\nAlien's health is capped at 100.\n";
                        }
                        break;
                    case 'p':
                    {
                        int check;
                        nextcommand = com;
                        bool podatt = false;
                        int ragr = -1;
                        int ragc = -1;
                        int ragrt, ragct;
                        int zombieinrange = 0;
                        cout << "Alien finds a pod.\n";
                        while (podatt == false)
                        {
                            for (ragrt = ragr; ragrt <= -ragr; ragrt++)
                            {
                                int arragrt = gr + ragrt;
                                if (arragrt < 0)
                                {
                                    arragrt = 0;
                                    ragrt = 0;
                                }
                                for (ragct = ragc; ragct <= -ragc; ragct++)
                                {
                                    for (z = 0; z < zombie; z++)
                                    {
                                        char go = (z + 49);
                                        int acragct = gc + ragct;
                                        char alienattacting = random[arragrt][acragct];
                                        if (acragct < 0)
                                        {
                                            acragct = 0;
                                            ragct = 0;
                                            alienattacting = random[arragrt][acragct];
                                        }
                                        else if (acragct > col)
                                        {
                                            alienattacting = ' ';
                                        }

                                        if (alienattacting == go)
                                        {
                                            zombieinrange = zombieinrange + 1;
                                            zombdata[z][3] = 1;
                                        }
                                    }
                                }
                            }
                            if (zombieinrange > 0)
                            {
                                while (podatt == false)
                                {
                                    int rannum = rand() % 5;
                                    char zombpod = (rannum + 49);
                                    if (zombdata[rannum][3] == 1)
                                    {
                                        zombdata[rannum][0] = zombdata[rannum][0] - 10;
                                        cout << "Zombie " << zombpod << " is hit for 10 damage!" << endl;
                                        if (zombdata[rannum][0] <= 0)
                                        {
                                            cout << "Zombie " << zombpod << " is dead!\n";
                                            random[gr][gc] = ' ';
                                            zombiedeadnum = zombiedeadnum + 1;
                                        }
                                        else
                                        {
                                            cout << "Zombie " << zombpod << " is still alive!\n";
                                        }
                                        podatt = true;
                                    }
                                }
                            }
                            else
                            {
                                ragc = ragc - 1;
                                ragr = ragr - 1;
                            }
                        }
                        break;
                    }
                    case 'r':
                        com = 's';
                        nextcommand = 's';
                        ran = norock[rand() % nrock];
                        random[gr][gc] = ran;
                        alienstatus = "Alien hits a rock, the object beneath the rock is revealed.\n";
                        break;
                    case ' ':
                        nextcommand = com;
                        alienstatus = "Alien finds an empty space.\n";
                        break;
                    case '.':
                        nextcommand = com;
                        alienstatus = "Alien finds an empty space.\n";
                        break;
                    default:
                        com = 's';
                        alienstatus = "Alien reached the side of the game.\n";
                        break;
                    }

                    if (ar == 0 && com == '^')
                    {
                        break;
                    }
                    else if (ar == row - 1 && com == 'V')
                    {
                        break;
                    }
                    else if (ac == 0 && com == '<')
                    {
                        break;
                    }
                    else if (ac == col - 1 && com == '>')
                    {
                        break;
                    }
                    //
                    for (z = 0; z < zombie; z++)
                    {
                        char go = (z + 49);
                        if (going == go)
                        {
                            zombdata[z][0] = zombdata[z][0] - alienAttack;
                            cout << "Alien attacks Zombie " << go << "\nZombie " << go << " gets damaged for " << alienAttack << endl;
                            alienstatus = "Alien hits zombie and stop.\n";
                            if (zombdata[z][0] <= 0)
                            {
                                cout << "Zombie " << go << " is dead\n";
                                random[gr][gc] = ' ';
                                zombiedeadnum = zombiedeadnum + 1;
                            }
                            else
                            {
                                cout << "Zombie " << go << " is still alive\n";
                            }
                        }
                    }

                    cout << alienstatus;
                    string cintocontinue;
                    cout << "Type any key to continue ...";
                    cin >> cintocontinue;
                    switch (com)
                    {
                    case '^':
                        random[ar][ac] = '.';
                        random[ar - 1][ac] = 'A';
                        ar = ar - 1;
                        break;
                    case 'v':
                        random[ar][ac] = '.';
                        random[ar + 1][ac] = 'A';
                        ar = ar + 1;
                        break;
                    case '<':
                        random[ar][ac] = '.';
                        random[ar][ac - 1] = 'A';
                        ac = ac - 1;
                        break;
                    case '>':
                        random[ar][ac] = '.';
                        random[ar][ac + 1] = 'A';
                        ac = ac + 1;
                        break;
                    case 's':
                        alienstatus = "";
                        turn = true;
                        movedone = true;
                        break;
                    }
                    gameboard(row, col, zombie, (char *)random, alienLife, alienAttack, (int *)zombdata, turn);
                    com = nextcommand;
                }
            }

            if (zombiedeadnum == zombie)
            {
                zombiedead = true;
            }
            if (zombiedead == false && playerquit == false)
            {
                cout << "Alien's turn ended.\n";
                alienAttack = 0;
                
                cout << "Type any key to continue ...";
                char cintocontinue;
                cin >> cintocontinue;
                string alienturn;
                int alientrial = 0;
                for (r = 0; r < row; r++)
                {
                    for (c = 0; c < col; c++)
                    {
                        if (random[r][c] == '.')
                        {
                            ran = object[rand() % o];
                            random[r][c] = ran;
                            alienturn = "Alien's trial '.' is replaced by random objects.\n";
                            alientrial = alientrial + 1;
                        }
                    }
                }
                if (alientrial > 0)
                {
                    gameboard(row, col, zombie, (char *)random, alienLife, alienAttack, (int *)zombdata, turn);
                    cout << alienturn;
                    cout << "Type any key to continue ...";
                    cin >> cintocontinue;
                }
                turn += 1;
                bool zombieturndone = false;
                while (!zombieturndone)
                {
                    //add zombie move
                    int zr, zc;
                    char zombienextplace;
                    string zombiegoing;
                    bool alieninrange = true;
                    for (z = 0; z < zombie; z++)
                    {
                        gameboard(row, col, zombie, (char *)random, alienLife, alienAttack, (int *)zombdata, turn);
                        cout << "Zombie " << z+1 << "'s turn."<< endl;
                        cout << "Type any key to continue ...";
                        char cintocontinue;
                        cin >> cintocontinue;
                        // system("pause")
                        int range = zombdata[z][2];
                        char zombnum = (z + 49);
                        bool zombmovedone = false;
                        bool zombcanmove = true;
                        while(!zombmovedone)
                        {
                            zr = zombdata[z][4];
                            zc = zombdata[z][5];
                            int zombiemove = rand() % 4;
                            if (zombiemove == 0 && zombdata[z][4] > 0)
                            {
                                for (int zt = 0; zt < zombie; zt++)
                                {
                                    zombienextplace = random[zombdata[z][4] - 1][zombdata[z][5]];
                                    char go = (zt + 49);
                                    if (zombienextplace == go || zombienextplace == 'A')
                                    {
                                        zombcanmove = false;
                                    }
                                }
                                if (zombcanmove == true)
                                {
                                    zombdata[z][4] -= 1;
                                    zombiegoing = "up";
                                    random[zr][zc] = ' ';
                                    random[zr - 1][zc] = zombnum;
                                    zombmovedone = true;
                                }
                            }
                            else if (zombiemove == 1 && zombdata[z][4] < row)
                            {
                                for (int zt = 0; zt < zombie; zt++)
                                {
                                    zombienextplace = random[zombdata[z][4] + 1][zombdata[z][5]];
                                    char go = (zt + 49);
                                    if (zombienextplace == go || zombienextplace == 'A')
                                    {
                                        zombcanmove = false;
                                    }
                                }
                                if (zombcanmove == true)
                                {
                                    zombdata[z][4] += 1;
                                    zombiegoing = "down";
                                    random[zr][zc] = ' ';
                                    random[zr + 1][zc] = zombnum;
                                    zombmovedone = true;
                                }      
                            }
                            else if (zombiemove == 2 && zombdata[z][5] > 0)
                            {
                                for (int zt = 0; zt < zombie; zt++)
                                {
                                    zombienextplace = random[zombdata[z][4]][zombdata[z][5] - 1];
                                    char go = (zt + 49);
                                    if (zombienextplace == go || zombienextplace == 'A')
                                    {
                                        zombcanmove = false;
                                    }
                                }
                                if (zombcanmove == true)
                                {
                                    zombdata[z][5] -= 1;
                                    zombiegoing = "left";
                                    random[zr][zc] = ' ';
                                    random[zr][zc - 1] = zombnum;
                                    zombmovedone = true;
                                }
                            }
                            else if (zombiemove == 3 && zombdata[z][4] < col)
                            {
                                for (int zt = 0; zt < zombie; zt++)
                                {
                                    zombienextplace = random[zombdata[z][4]][zombdata[z][5] + 1];
                                    char go = (zt + 49);
                                    if (zombienextplace == go || zombienextplace == 'A')
                                    {
                                        zombcanmove = false;
                                    }
                                }
                                if (zombcanmove == true)
                                {
                                    zombdata[z][5] += 1;
                                    zombiegoing = "right";
                                    random[zr][zc] = ' ';
                                    random[zr][zc + 1] = zombnum;
                                    zombmovedone = true;
                                }  
                            }
                        }
                        gameboard(row, col, zombie, (char *)random, alienLife, alienAttack, (int *)zombdata, turn);
                        cout << "Zombie " << zombnum << " move " << zombiegoing << endl;
                        cout << "Type any key to continue ...";
                        cin >> cintocontinue;
                        // system("pause")
                        zr = zombdata[z][4];
                        zc = zombdata[z][5];
                        for (int ragr = -range; ragr <= range; ragr++)
                        {
                            for (int ragc = -range; ragc <= range; ragc++)
                            {
                                char zombieattacking = random[zr + ragr][zc + ragc];
                                if (zombieattacking == 'A')
                                {
                                    int zombatt = zombdata[z][1];
                                    alienLife = alienLife - zombatt;
                                    gameboard(row, col, zombie, (char *)random, alienLife, alienAttack, (int *)zombdata, turn);
                                    cout << "Alien is in the range of Zombie " << z + 1 << endl;
                                    cout << "Alien life reduce by " << zombdata[z][1] << endl;
                                    
                                    ragc = range + 1;
                                    ragr = range + 1;
                                    alieninrange = true;
                                    if (alienLife <= 0)
                                    {
                                        cout << "Alien dies.\nYou lose the game!" << endl;
                                        turn = true;
                                        win = true;
                                        zombieturndone = true;
                                        z = zombie;
                                    }
                                    else 
                                    {
                                        cout << "Alien is still alive.\n";
                                    }
                                    cout << "Type any key to continue ...";
                                    char cintocontinue;
                                    cin >> cintocontinue;
                                    // system("pause")
                                }
                                else
                                {
                                    alieninrange = false;
                                }
                            }
                        }
                        if (alieninrange == false)
                        {
                            gameboard(row, col, zombie, (char *)random, alienLife, alienAttack, (int *)zombdata, turn);
                            cout << "Alien is not in range of Zombie " << z + 1 << endl;
                            cout << "Type any key to continue ...";
                            char cintocontinue;
                            cin >> cintocontinue;
                            // system("pause")
                        }
                        turn += 1;
                    }
                    zombieturndone = true;
                }
            }
            else if (zombiedead == true)
            {
                turn = true;
                win = true;
                cout << "All zombies are dead.\nYou win!" << endl;
            }
            else if (playerquit == true)
            {
                turn = true;
                win = true;
            }

            
        } while (!turn);
    } while (!win);
}


void setting(int &row, int &col, int &zombie)
{
    bool rowdone, coldone, zombiedone;
    cout << "+-----------------------------+" << endl;
    cout << "|        Game Settings        |" << endl;
    cout << "+-----------------------------+" << endl;
    cout << "Enter rows => ";
    cin >> row;
    while (cin.fail() || row % 2 == 0 || row < 4)
    {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "The value must be an odd number and more than 3.Please type again: ";
        cin >> row;
    }

    cout << "Enter columns => ";
    cin >> col;
    while (cin.fail() || col % 2 == 0 || col < 4)
    {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "The value must be an odd number and more than 3.Please type again: ";
        cin >> col;
    }

    cout << "Please enter numbers of zombie: ";
    cin >> zombie;
    while (cin.fail() || zombie > 4)
    {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "The number of zombies has to be less than or equal to 4. Please Type again: ";
        cin >> zombie;
    }
}

void defaultSetting(int &row, int &col, int &zombie)
{
    char change;
    bool done = false;
    srand(time(NULL));
    bool valid = false;
    do
    {
        row = rand() % 20 + 5;
        col = rand() % 20 + 5;
        zombie = rand() % 3 + 3;
        if ((row % 2 == 1) && (col % 2 == 1))
        {
            valid = true;
        }
        else
        {
            valid = false;
        }
    } while (!valid);
    cout << "Default Game Settings     " << endl;
    cout << "------------------------- " << endl;
    cout << "Board Rows             :  " << row << endl;
    cout << "Board Columns          :  " << col << endl;
    cout << "Zombie Count           :  " << zombie << endl;
    cout << endl;

    cout << endl;
    do
    {
        cout << "Do you wish to change the game settings (y/n)? => ";
        cin >> change;
        change = toupper(change);
        switch (change)
        {
        case 'Y':
            setting(row, col, zombie);
            done = true;
            break;
        case 'N':
            done = true;
            break;
        default:
            cout << "Invalid input. Please Try Again" << endl;
            cout << endl;
            break;
        }
    } while (!done);
}


int main()
{
    int row, column, zombie;
    char choice;
    bool done = false;
    do
    {
        displayMenu();
        cin >> choice;
        choice = toupper(choice);
        cout << endl;
        switch (choice)
        {
        case '1':
            defaultSetting(row, column, zombie);
            game(row, column, zombie);
            break;
        case '2':
            load();
            break;
        case 'Q':
            done = true;
            break;
        default:
            cout << "Invalid selection, try again!" << endl;
            cout << endl;
            break;
        }
        // system("pause");
    } while (!done);
    cout << endl;
    cout << "Thank You For Playing. Good Bye!" << endl;
}
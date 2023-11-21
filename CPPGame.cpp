#include <iostream>
#include <conio.h>

using namespace std;

class Game {
public:
    void start() {
        showStartScreen();
        initializeMap();
        playGame();

    }
    int endGame = 0;
    bool gameOver = false;

private:
    char map[20][20];
    int playerX, playerY;
    int pigX, pigY;
    int toolX, toolY;
    int thatchX, thatchY;
    int woodX, woodY;
    int rockX, rockY;
    int dialogueProgress;
    string tool;
    string material;


    void showStartScreen() {
        cout << "-------- Help Piggy build a house --------" << endl;
        cout << "Welcome to play！" << endl;
        cout << "Operating instructions:\n";
        cout << "W - MoveUp\n";
        cout << "A - MoveLeft\n";
        cout << "S - MoveDonw\n";
        cout << "D - MoveRight\n";
        cout << "Q - Quit\n";
        cout << "Operate 'I' to move closer to other character on the map to generate interaction\n";
        cout << "--------Press 'C' to start--------\n";
        _getch();
        system("cls"); // Clean Screen
        dialogueProgress = 0;
    }

    void initializeMap() {
        
        for (int i = 0; i < 20; ++i) {
            for (int j = 0; j < 20; ++j) {
                if (i == 0 || i == 19 || j == 0 || j == 19) {
                    map[i][j] = '#'; 
                }
                else {
                    map[i][j] = ' ';
                }
            }
        }

        // Place player
        playerX = 1;
        playerY = 1;
        map[playerX][playerY] = 'I';

        // Place NPC Piggy
        pigX = 5;
        pigY = 5;
        map[pigX][pigY] = 'P';

        // Place tool
        toolX = 5;
        toolY = 8;
        map[toolX][toolY] = '!';

        // Place grasslands, forests, and quarry
        thatchX = 3;
        thatchY = 12;
        map[thatchX][thatchY] = 'G';//Grassland

        woodX = 3;
        woodY = 15;
        map[woodX][woodY] = 'F';//Forest

        rockX = 3;
        rockY = 18;
        map[rockX][rockY] = 'Q';//Quarry
    }

    void printMap() {
        system("cls");
        for (int i = 0; i < 20; ++i) {
            for (int j = 0; j < 20; ++j) {
                cout << map[i][j] << ' ';
            }
            cout << endl;
        }
    }

    void playGame() {
        char userInput;
        while (!gameOver) {
            printMap();
            userInput = _getch();
            switch (userInput) {
            case 'W':
            case 'w':
                movePlayer(-1, 0);
                break;
            case 'A':
            case 'a':
                movePlayer(0, -1);
                break;
            case 'S':
            case 's':
                movePlayer(1, 0);
                break;
            case 'D':
            case 'd':
                movePlayer(0, 1);
                break;
            case 'Q':
            case 'q':
                gameOver = true;
                break;
            }

            // Determine the player's position, detect distance to determine if interaction occurs
            if ((abs(playerX-pigX)+abs(playerY-pigY)<=1)) {
                talkToPig();
            }

            if ((abs(playerX - toolX) + abs(playerY - toolY) <= 1)) {
                getTool();
            }

            if ((abs(playerX - thatchX) + abs(playerY - thatchY) <= 1)) {
                getThatch();
            }

            if ((abs(playerX - woodX) + abs(playerY - woodY) <= 1)) {
                getWood();
            }

            if ((abs(playerX - rockX) + abs(playerY - rockY) <= 1)) {
                getRock();
            }
        }
    }

    void movePlayer(int deltaX, int deltaY) {
        // Move players and prevent them from overlapping elements on the map
        if (map[playerX + deltaX][playerY + deltaY] != '#') {
            if (map[playerX + deltaX][playerY + deltaY] != 'P') {
                if (map[playerX + deltaX][playerY + deltaY] != '!') {
                    if (map[playerX + deltaX][playerY + deltaY] != 'G') {
                        if (map[playerX + deltaX][playerY + deltaY] != 'F') {
                            if (map[playerX + deltaX][playerY + deltaY] != 'Q') {
                                if (map[playerX + deltaX][playerY + deltaY] != '|') {
                                    if (map[playerX + deltaX][playerY + deltaY] != '_') {
                                        if (map[playerX + deltaX][playerY + deltaY] != '\\') {
                                            if (map[playerX + deltaX][playerY + deltaY] != '//') {
                                                map[playerX][playerY] = ' ';
                                                playerX += deltaX;
                                                playerY += deltaY;
                                                map[playerX][playerY] = 'I';
                                            }}}}}}}}}}}

    void getTool() {
        cout << "Piggy: There are collection tools here, and different materials need to be collected using different tools" << endl;
        cout << "Piggy: Which one you want？" << endl;
        cout << "1: Pickaxe  2: Axe  3: Sickle" << endl;
        cout << "Please select" << endl;
        char userInput;
        userInput = _getch();
        switch (userInput)
        {
        case '1': {tool = "Pickaxe"; };
            break;
        case '2': {tool = "Axe"; };
                break;
        case '3': {tool = "Sickle"; };
                break;
        }
        cout << "You chose the ";
        cout << tool << endl;
        cout << "--------Press 'C' to continue--------" << endl;

        dialogueProgress = 1;
        _getch();
    }

    void getThatch() {
        cout << "You come to the grassland. Do you want to collect some Thatch?" << endl;
        cout << "Y:Yes  N:No" << endl;
        cout << "Please select" << endl;
        char userInput;
        userInput = _getch();
        switch (userInput)
        {
        case 'y':
        case 'Y': {
            if (tool == "Sickle") {
                cout << "You have successfully collected materials!" << endl;
                material = "Thatch";
                cout << "Now, the material you have is:" <<material<<endl;
                cout << "--------Press 'C' to continue--------" << endl;
            }
            else {
                cout << "You don't have the corresponding collection tool, go find it!" << endl;
                cout << "--------Press 'C' to continue--------" << endl;
            }
            ; 
        };
                break;
        case 'n':
        case 'N': ;
                break;
        }
        dialogueProgress = 2;
        _getch();
    }

    void getWood() {
        cout << "You come to the forest. Do you want to collect some wood?" << endl;
        cout << "Y:Yes  N:No" << endl;
        cout << "Please select" << endl;
        char userInput;
        userInput = _getch();
        switch (userInput)
        {
        case 'y':
        case 'Y': {
            if (tool == "Axe") {
                cout << "You have successfully collected materials!" << endl;
                material = "Wood";
                cout << "Now, the material you have is:" << material << endl;
                cout << "--------Press 'C' to continue--------" << endl;
            }
            else {
                cout << "You don't have the corresponding collection tool, go find it!" << endl;
                cout << "--------Press 'C' to continue--------" << endl;
            };
        };
                break;
        case 'n':
        case 'N':;
            break;
        }
        dialogueProgress = 3;
        _getch();
    }
    void getRock() {
        cout << "You come to the quarry. Do you want to collect some rock?" << endl;
        cout << "Y:Yes  N:No" << endl;
        cout << "Please select" << endl;
        char userInput;
        userInput = _getch();
        switch (userInput)
        {
        case 'y':
        case 'Y': {
            if (tool == "Pickaxe") {
                cout << "You have successfully collected materials!" << endl;
                material = "Rock";
                cout << "Now, the material you have is:" << material << endl;
                cout << "--------Press 'C' to continue--------" << endl;
            }
            else {
                cout << "You don't have the corresponding collection tool, go find it!" << endl;
                cout << "--------Press 'C' to continue--------" << endl;
            };
        };
                break;
        case 'n':
        case 'N':;
            break;
        }
        dialogueProgress = 4;
        _getch();
    }

    void talkToPig() {
        switch (dialogueProgress)
        {
        case 0: {
            cout << "Piggy: Hello friend, I want to build a house to resist the big gray wolf." << endl;
            cout << "Piggy: Can you help me? I don't have enough materials." << endl;
            cout << "Piggy: I'm not sure what kind of house to build" << endl;
            cout << "Piggy:  There are collection tools available at '!', which can collect materials nearby" << endl;
            cout << "Press any key to continue..." << endl;
        };
              break;
        case 1: {
            cout << "Piggy: It seems that you have found the tool. You can go to collect some materials!" << endl;
            cout << "Piggy: There are grasslands, forests, and quarries nearby." << endl;
            cout << "Piggy: We can build thatched, wooden, or brick houses." << endl;
            cout << "Press 'C' to continue..."  << endl;
        };
              break;
        case 2: {
            cout << "Piggy: Thank you for your materials!" << endl;
            cout << "Piggy: Now we can build thatched house." << endl;
            cout << "Press 'C' to continue..." << endl;
            char userInput;
            userInput = _getch();
            if (userInput == 'C' || userInput == 'c') {
                cout << "Under construction......" << endl;
                cout << "Press 'C' to continue" << endl;
                userInput = _getch();
                if (userInput == 'C' || userInput == 'c') {
                    system("cls");
                    cout << "The thatched cottage has been successfully built." << endl << endl;
                    cout << "But the thatched cottage is not sturdy enough. The big gray wolf blew down in one breath" << endl << endl;
                    cout << "Maybe try other materials" << endl << endl;
                    cout << "Press 'C' to continue..." << endl;
                }
            }
        };
              break;
        case 3: {
            cout << "Piggy: Thank you for your materials!" << endl;
            cout << "Piggy: Now we can build wooden house." << endl;
            cout << "Press 'C' to continue..." << endl;
            char userInput;
            userInput = _getch();
            if (userInput == 'C' || userInput == 'c') {
                cout << "Under construction......" << endl;
                cout << "Press 'C' to continue" << endl;
                userInput = _getch();
                if (userInput == 'C' || userInput == 'c') {
                    system("cls");
                    cout << "The wooden house has been successfully built." << endl << endl;
                    cout << "But the wooden house is not sturdy enough. The big gray wolf burned down the house with one blow of fire." << endl << endl;
                    cout << "Maybe try other materials" << endl << endl;
                    cout << "Press 'C' to continue..." << endl;
                }
            }
        };
              break;
        case 4: {
            cout << "Piggy: Thank you for your materials!" << endl;
            cout << "Piggy: Now we can build brick house." << endl;
            cout << "Press 'C' to continue..." << endl;
            char userInput;
            userInput = _getch();
            if (userInput == 'C' || userInput == 'c') {
                cout << "Under construction......" << endl;
                cout << "Press 'C' to continue" << endl;
                userInput = _getch();
                if (userInput == 'C' || userInput == 'c') {
                    system("cls");
                    cout << "                Congratulation!" << endl << endl;
                    cout << "The wooden house has been successfully built." << endl << endl;
                    cout << "But the brick house is very sturdy enough. The big gray wolf tried various methods but couldn't destroy it." << endl << endl;
                    cout << "Let's go see the new house!" << endl << endl;
                    cout << "Press 'C' to continue..." << endl;
                }
            }
            //Draw a house
            map[7][11] = '_';
            map[7][12] = '_';
            map[8][10] = '//';
            map[8][13] = '\\';
            map[9][9] = '//';
            map[9][14] = '\\';
            map[10][8] = '//';
            map[10][15] = '\\';
            map[11][7] = '//';
            map[11][16] = '\\';
            map[12][8] = '_';
            map[12][15] = '_';
            map[13][11] = '_';
            map[13][12] = '_';
            map[15][14] = '_';
            map[15][13] = '_';
            map[15][9] = '_';
            map[15][10] = '_';
            map[13][15] = '|';
            map[13][8] = '|';
            map[14][15] = '|';
            map[14][8] = '|';
            map[15][15] = '|';
            map[15][8] = '|';
            map[14][11] = '|';
            map[14][12] = '|';
            map[15][11] = '|';
            map[15][12] = '|';

            map[pigX][pigY] = ' ';
            pigX = 15;
            pigY = 5;
            map[pigX][pigY] = 'P';
            dialogueProgress = 5;
        };
              break;
        case 5: {
            cout << "Piggy: Thank you very much for your help." << endl;
            cout << "Piggy: This house is really sturdy, even the big gray wolf cannot destroy it." << endl;
            cout << "----------------------The End-----------------------------" << endl;
        };
              break;
        default:
            break;
        }
        _getch();
    }
};

int main() {
    Game game;
    game.start();
    return 0;
}

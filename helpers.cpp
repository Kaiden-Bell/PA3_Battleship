#include "helpers.h"

int startGame(Player& p, AiPlayer& a){
    string name;
    int random = 0;

    cout << "Enter your name: ";
    cin >> name;
    p.setName(name);

    //place ai ships
    a.placeShipsRandom();

    //to place user ships, have them select a beginning and end point for each ship
    placeShips(p);

    //randomly decide who goes first (pick between 1 & 2), implement later

    return random;
}

void placeShips(Player& p){
    Square start;
    Square end;
    bool result;

    //Carrier
    displayBoards(p);
    cout << "To place your Carrier (5 squares), select a starting and ending square for it." << endl;
    do{
        cout << "   Start: ";
        cin >> start;

        cout << "   End: ";
        cin >> end;
        
        result = checkShips(start, end, p);
    }while(result == false);
    initShips(start, end, p);
    system("clear");

    //Battleship
    displayBoards(p);
    cout << "To place your Battleship (4 squares), select a starting and ending square for it." << endl;
    do{
        cout << "   Start: ";
        cin >> start;

        cout << "   End: ";
        cin >> end;
        
        result = checkShips(start, end, p);
    }while(result == false);
    initShips(start, end, p);
    system("clear");

    //Destroyer
    displayBoards(p);
    cout << "To place your Destroyer (3 squares), select a starting and ending square for it." << endl;
    do{
        cout << "   Start: ";
        cin >> start;

        cout << "   End: ";
        cin >> end;
        
        result = checkShips(start, end, p);
    }while(result == false);
    initShips(start, end, p);
    system("clear");

    //Submarine
    displayBoards(p);
    cout << "To place your Submarine (3 squares), select a starting and ending square for it." << endl;
    do{
        cout << "   Start: ";
        cin >> start;

        cout << "   End: ";
        cin >> end;
        
        result = checkShips(start, end, p);
    }while(result == false);
    initShips(start, end, p);
    system("clear");

    //Patrol Boat
    displayBoards(p);
    cout << "To place your Patrol Boat (2 squares), select a starting and ending square for it." << endl;
    do{
        cout << "   Start: ";
        cin >> start;

        cout << "   End: ";
        cin >> end;
        
        result = checkShips(start, end, p);
    }while(result == false);
    initShips(start, end, p);
    system("clear");

}

bool isValidSquare(const Square& square, const Player& player){
    if(square.row < 'A' || square.row > 'J' || square.col < 1 || square.col > 10) {
        return false;
    }
    return !player.isSquareOccupied(square);
}

//checks the validity of the ship placement
bool checkShips(Square s, Square e, const Player& player) {
    if (s.row == e.row) {  // Horizontal
        if (e.col < s.col) std::swap(s.col, e.col);
        // Iterate through columns
        for (int col = s.col; col <= e.col; ++col) {
            if (!isValidSquare(Square{s.row, col}, player)) return false;
        }
    } else if (s.col == e.col) {  // Vertical
        if (e.row < s.row) std::swap(s.row, e.row);
        // Iterate through rows
        for (char row = s.row; row <= e.row; ++row) {
            if (!isValidSquare(Square{row, s.col}, player)) return false;
        }
    } else {  // Not in a straight line (invalid placement)
        cout << "Invalid ship placement" << endl;
        return false;
    }
    return true;
}

//places the ships after checked in the ships array
void initShips(Square s, Square e, Player& player){
    if (s.row == e.row) {
        if (e.col < s.col) swap(s.col, e.col);
        for (int col = s.col; col <= e.col; ++col) {
            player.occupuySquare(Square{s.row,col});
        }
    } else if (s.col == e.col) {
        if (e.row < s.row) swap(s.row, e.row);
        for (char row = s.row; row <= e.row; row++){
            player.occupuySquare(Square{row, s.col});
        }
    }

}

//gameloop function
bool playRound(Player& p, AiPlayer& a, int& turn){
    bool win;
    switch(turn){
        case 1: 
            p.takeTurn(p);
            win = checkWin();
            if(win){
                return true;
            }
            turn++;
            break;
        case 2:
            a.takeTurn(a);
            win = checkWin();
            if(win){
                return true;
            }
            turn--;
            break;
        default:
            return 0;
            break;
    }
    return false;
}

void displayBoards(Player& p){
    DynamicArray<int> playerBoard = p.getPlayerBoard();
    DynamicArray<int> opponent_board = p.getOpponentBoard();

    cout << "Opponent Board: " << endl;
    cout << "  1 2 3 4 5 6 7 8 9 10" << endl;
    for(int i = 0; i < 10; i++) {
        cout << (char)('A' + i) << " ";
        for(int j = 0; j < 10; j++) {
            cout << opponent_board.getArray()[i*10 +j];
        }
        cout << endl;
    }
    
    cout << endl;
    cout << "------------------------" << endl;

    cout << "Player's Board: " << endl;
    cout << "  1 2 3 4 5 6 7 8 9 10" << endl;
    for(int i = 0; i < 10; i++) {
        cout << (char)('A' + i) << " ";
        for(int j = 0; j < 10; j++) {
            cout << playerBoard.getArray()[i*10+j];
        }
        cout << endl;
    }
    cout << endl;
}

/* updates after each square selection for hit or miss
void updateBoard(Square s){
    //update board with hit/miss
}

//checks if player hit ship
bool checkHit(Square s){

}

//checks if guess is valid
bool checkGuess(Square s, DynamicArray<Square> g){ //g for guesses

}

//checks if win conditions are met
bool checkWin(){
    
}
*/
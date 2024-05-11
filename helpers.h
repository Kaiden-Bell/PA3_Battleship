#ifndef HELPERS_H
#define HELPERS_H

#include "aiPlayer.h"
#include "dynamicArray.h"

class Helpers {
    public:
        void startGame();
        void playRound();
        void displayBoards();
        void updateBoard(string, int, int, char);
        bool checkHit(string, int, int);
        bool checkGuess(string, int, int);
        bool checkWin();
}
#endif
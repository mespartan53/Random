#include <iostream>
#include <string>

using namespace std;
    
class TTTBoard{
    private:
    string currentBoard[9];
    
    public:
    
    //Depending on the player will determine the letter used
    void selection(int player, int choice)
    {
        string update = "";
        if (player % 2 == 0)
            update = "X";
        else
            update = "O";
            
        currentBoard[choice - 1] = update;
    }
    
    //Checks if the choice is not played
    bool isValid(int choice)
    {
        if (currentBoard[choice - 1] == "X" || currentBoard[choice - 1] == "O")
            return false;
        return true;
    }
    
    //checks all victory situations
    //then checks if there are still playable selections
    //if none, the draw
    int checkVictory()
    {
        //check 123 -- top row
        if(currentBoard[0] == currentBoard[1] && currentBoard[1] == currentBoard[2] && (currentBoard[0] == "X" || currentBoard[0] == "O")) {
            if (currentBoard[0] == "X")
                return 0;
            else
                return 1;
        }
                
        //check 159 -- down sloping diagonal
        if(currentBoard[0] == currentBoard[4] && currentBoard[4] == currentBoard[8] && (currentBoard[0] == "X" || currentBoard[0] == "O")) {
            if (currentBoard[0] == "X")
                return 0;
            else
                return 1;
        }
        
        //check 147 -- left column
        if(currentBoard[0] == currentBoard[3] && currentBoard[3] == currentBoard[6] && (currentBoard[0] == "X" || currentBoard[0] == "O")) {
            if (currentBoard[0] == "X")
                return 0;
            else
                return 1;
        }
                
        //check 258 -- middle column
        if(currentBoard[1] == currentBoard[4] && currentBoard[4] == currentBoard[7] && (currentBoard[4] == "X" || currentBoard[4] == "O")) {
            if (currentBoard[4] == "X")
                return 0;
            else
                return 1;
        }
                
        //check 456 -- middle row
        if(currentBoard[3] == currentBoard[4] && currentBoard[4] == currentBoard[5] && (currentBoard[4] == "X" || currentBoard[4] == "O")) {
            if (currentBoard[4] == "X")
                return 0;
            else
                return 1;
        }
                
        //check 357 -- up sloping diagonal
        if(currentBoard[2] == currentBoard[4] && currentBoard[4] == currentBoard[6] && (currentBoard[4] == "X" || currentBoard[4] == "O")) {
            if (currentBoard[4] == "X")
                return 0;
            else
                return 1;
        }
                
        //check 369 -- right column
        if(currentBoard[2] == currentBoard[5] && currentBoard[5] == currentBoard[8] && (currentBoard[8] == "X" || currentBoard[8] == "O")) {
            if (currentBoard[8] == "X")
                return 0;
            else
                return 1;
        }

        //check 789 -- bottom row
        if(currentBoard[6] == currentBoard[7] && currentBoard[7] == currentBoard[8] && (currentBoard[8] == "X" || currentBoard[8] == "O")) {
            if (currentBoard[8] == "X")
                return 0;
            else
                return 1;
        }
        
        //check for unused spaces
        //3 will be to continue playing 
        for (int i = 0; i < 9; i++)
            if (currentBoard[i] != "X" && currentBoard[i] != "O")
                return 3;
        
        //no victory, no winner
        //2 is tie
        return 2;
    }
    
    
    //reset the board to numbered selections
    void resetBoard()
    {
        for (int i = 0; i < 9; i++)
            currentBoard[i] = to_string(i + 1);
    }
    
    //Initialize the board
    TTTBoard()
    {
           for (int i = 0; i < 9; i++)
                currentBoard[i] = to_string(i + 1);
    }
    
    //output board tabbed from the left
    friend ostream & operator<<(ostream & out, TTTBoard & game)
    {
        for (int i = 0; i < 5; i++)
            if (i % 2 != 0)
                out << "\t----------" << endl;
            else
                if (i == 0)
                    out<< "\t" << game.currentBoard[0] << " | " << game.currentBoard[1] << " | " << game.currentBoard[2] << endl;
                else if ( i == 2 )
                    out<< "\t" << game.currentBoard[3] << " | " << game.currentBoard[4] << " | " << game.currentBoard[5] << endl;
                else
                    out<< "\t" << game.currentBoard[6] << " | " << game.currentBoard[7] << " | " << game.currentBoard[8] << endl;
        
        return out;
    }
};

//Handle everything before starting a new game
int pregame()
{
    int start = 0;
    
    cout << "Make a selection followed by enter(3 or 4 only)\n"
        << "3: Start Tic-Tac-Toe\n"
        << "4: Exit\n";
    cin >> start;
    while (start > 4 || start < 3) //input validation
    {
        cout << "Please choose a valid option\n"
            << "Make a selection followed by enter(3 or 4 only)\n"
            << "3: Start Tic-Tac-Toe\n"
            << "4: Exit\n";
        cin >> start;
    }
    system("Clear");
    return start;
}

//reset the baord and prepare for next game
int endGame(TTTBoard * g)
{
    g->resetBoard();
    return 5;
}

//the player makes a choice based and validate
//the selection is made and the player is incremented and victory is checked
int playGame(TTTBoard * g, int *player)
{
    int choice = 10;
    bool valid = false;
    
    cout << *g;
    cout <<"Player " << (*player % 2) + 1 << " please make a move.\n"
        <<"Only 1-9 are valid choices (Cannot choose a space that has been selected).\n";
    cin >> choice;
    
    if (choice <= 9 && choice >= 1)
        valid = g->isValid(choice);
    else 
        valid = false;
    
    while(choice > 9 || choice < 1 || !valid)
    {
        cout << *g;
        cout << "Choice NOT valid\n"
            <<"Player " << (*player % 2) + 1 << " please make a move.\n"
            <<"Only 1-9 are valid choices (Cannot choose a space that has been selected).\n";
        cin >> choice;
        if (choice <= 9 && choice >= 1)
            valid = g->isValid(choice);
        else
            valid = false;
    }
    
    g->selection(*player, choice);
    (*player)++;
    return g->checkVictory();
}

int main() {
    TTTBoard *game = new TTTBoard;
    int state = 5; // 0: Player 1 win, 1: Player 2 win, 2: draw, 3: play on, 4 exit, 5: begin game;
    int *player = new int(0);
    int p1Wins = 0, p2Wins = 0, draws = 0;
    
    while (state != 4)
    {
        if (state == 0)
        {
            cout << *game;
            cout << "Player 1 Wins!!!\n";
            cout << "Total Wins\n"
                << "Player 1: " << ++p1Wins << endl
                << "Player 2: " << p2Wins << endl
                << "Draws   : " << draws << endl;
            state = endGame(game);
        }
        if (state == 1)
        {
            cout << *game;
            cout << "Player 2 Wins!!!\n";
            cout << "Total Wins\n"
                << "Player 1: " << p1Wins << endl
                << "Player 2: " << ++p2Wins << endl
                << "Draws   : " << draws << endl;
            state = endGame(game);
        }
        if (state == 2)
        {
            cout << "It's a draw!!!\n";
            cout << "Total Wins\n"
                << "Player 1: " << p1Wins << endl
                << "Player 2: " << p2Wins << endl
                << "Draws   : " << ++draws << endl;
            state = endGame(game);
        }
        if (state == 3)
        {
            state = playGame(game, player);
        }
        if (state == 5)
        {
            state = pregame();
        }
    }
    
    return 0;
}

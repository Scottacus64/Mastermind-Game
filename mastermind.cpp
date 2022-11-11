# include <iostream>
using namespace std;

int board[10][4];                           // board is an array to hold the player's guess
int output[10][4];                          // output is an array that will hold the result of the player's guess
bool gameOver = false;
bool playAgain = true;

void printBoard(){                          // function to print the board
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 4; j++){
            cout << board[i][j] << " ";
        }
        cout << "\t";
        for (int j = 0; j < 4; j++){
            cout << output[i][j] << " ";
        }
        cout << "\n";
  }
}

char again;
void newGame(){                                         // function to check if the player wants to play again
    while (again != 'n' or again != 'y'){               // only 'n' or 'y' will be accepted as inputs
        cout << "Do you want to play agian (y/n)?";
        cin >> again;
        if (again == 'y'){
            playAgain = true;
            gameOver = false;
            return;
        }
        if (again == 'n'){
            playAgain = false;
            return;
        }
    }
}

int main() {
while (playAgain){
    int code[4] = {0,0,0,0};                // this will be the code
    int test[4] = {0,0,0,0};                // this will be the player's guess
    int result[4] = {0,0,0,0};              // this will be the output of the player's guess
    int tempCode[4] = {0,0,0,0};            // this will be a temp code so the original is not overwirtten

    // Make a blank board
    memset(board, 0, 40);                   // set up memory for 10 4 byte ints
    memset(output, 0, 40);

    // Generate the code
    srand (time(NULL));                     // grab the time in seconds since 1970

    while (code[0]==code[1]                 // code to check if each of the four digits in the code is unique
            ||code[0]==code[2]
            ||code[0]==code[3]
            ||code[1]==code[2]
            ||code[1]==code[3]
            ||code[2]==code[3]){
        for (int i = 0; i < 4; i++){
            code[i] = 1 + (rand() % 6);     // make a random number between 0-5 and add 1 to make it 1-6
        }
    }

    int line = 0;                           // this it the line in the output 0-9
    string guess;                           // this will be the player's guess at the code
    // start making guesses
    while (!gameOver){                      // bool that controls if a game is in play
        cout << "\n" << "Enter a guess: ";
        cin >> guess;
        for (int i = 0; i < 4; i++){
            tempCode[i] = code[i];          // make a temp code to not change th actual code
            test[i] = guess[i];             // pull each char of the string guess as an int test
            test[i]-= 48;                   // 1 = 49, 2 = 50... so subtract 48 to translate ascii to int
            board[line][i] = test[i];       // populate the player's guess output on the 10 line board display
        }
        int a = 0;                          // int to keep track of slot (0-3) in completion of code
        for (int i = 0; i < 4; i++){
            if (test[i] == code[i]){        // if the correct number is in the correct place
                output[line][a] = 2;        // output a "2" 
                a++;                        // increment to the next slot
                tempCode[i] = 0;            // set the tempCode to "0" for this digit so not matched again
                test[i] = 0;                // set test to "0" so next section will skip over it to prevent matching agian
            }   
            }
        for (int i = 0; i < 4; i++){                // go through each digit in the code but..
            if (tempCode[i]>0){                     // if the code has already been matched skip (see above)
                for (int j = 0; j < 4; j++){        // go through each player input   
                    if (test[j]== tempCode[i]){     // if a match then...
                        output[line][a] = 1;        // output a "1"
                        a += 1;                     // move to the next output slot
                        tempCode[i] = 0;            // set the tempCode to "0" so not matched again
                        test[j] = 0;                // set the test to "0" as above
                        break;                      // break out of this loop
                    }
                }

            }
        }
        printBoard();
        int finish = 0;                     // int to check if the guess matches the code
        for (int i = 0; i < 4; i++){
            if (output[line][i] == 2){      // for each output of 2
                finish++;                   // increment finish
            }
        }
        if (finish == 4){                   // if finish is 4 then all four numbers are correct
            cout << "WIN!" << "\n";
            gameOver = true;
        }
            if (line > 8){                  // if on the 9th line then this is a loss
            cout << "Loss" << "\n";
            gameOver = true;                // set the bool gameOver to true to end game
        }
        line += 1;                          // increment to the next line (0-9)
    }
    newGame();                              // check if the player wants to play a new game
}   
    cout << endl;                           // end line to get ready for exit
    return 0;
}

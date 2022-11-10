# include <iostream>
using namespace std;

int board[10][4];
int output[10][4];
bool gameOver = false;
bool playAgain = true;

void printBoard(){
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

char again = 'a';
void newGame(){
    while (again != 'n' or again != 'y'){
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
    int code[4] = {0,0,0,0};
    int test[4] = {0,0,0,0};
    int result[4] = {0,0,0,0};
    int tempCode[4] = {0,0,0,0};

    // Make a blank board
    memset(board, 0, 40);
    memset(output, 0, 40);
    // Generate the code
    srand (time(NULL));

    while (code[0]==code[1]
            ||code[0]==code[2]
            ||code[0]==code[3]
            ||code[1]==code[2]
            ||code[1]==code[3]
            ||code[2]==code[3]){
        for (int i = 0; i < 4; i++){
            code[i] = 1 + (rand() % 6);
        }
    }

    int line = 0;
    string guess;
    // start making guesses
    while (!gameOver){
        cout << "\n" << "Enter a guess: ";
        cin >> guess;
        for (int i = 0; i < 4; i++){
            tempCode[i] = code[i];
            test[i] = guess[i];
            test[i]-= 48;
            board[line][i] = test[i];
        }
        int a = 0;
        for (int i = 0; i < 4; i++){
            if (test[i] == code[i]){
                output[line][a] = 2;
                a++;
                tempCode[i] = 0;
                test[i] = 0;
            }
            }
        for (int i = 0; i < 4; i++){
            if (tempCode[i]>0){
                for (int j = 0; j < 4; j++){
                    if (test[j]== tempCode[i]){
                        output[line][a] = 1;
                        a += 1;
                        tempCode[i] = 0;
                        test[j] = 0;
                        break;
                    }
                }

            }
        }
        printBoard();
        int finish = 0;
        for (int i = 0; i < 4; i++){
            if (output[line][i] == 2){
                finish += 1;
            }
        }
        if (finish == 4){
            cout << "WIN!" << "\n";
            gameOver = true;
        }
            if (line > 8){
            cout << "Loss" << "\n";
            gameOver = true;
        }
        line += 1;
    }
    newGame();
}   
    cout << sizeof(int);
    cout << endl;
    return 0;
    
}

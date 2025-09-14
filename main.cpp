#include <iostream>
std::string grid[3][3]{};//The real coordinates of the board
bool turn{false};        //Define who's turn is false = human player
bool win{false};         //True if the game's over or if it has reached a terminal state on minimax
int playerWon{4};        //0 = tie  1 = human player won    -1 = bot won
void updateGrid();
int minimax(bool player, int depth);
//                      position^^[][] is the current state of the board when minimax is deciding and making moves
//                      player is who's turn it is, maximizing player or minimizing

//Shape the empty spaces before drawing the grid
    void createGrid(){
int i {}, j {};
 do{
    grid[i][j]="   ";
    i++;
    if(i>=3){
        j++; i=0;
        }
    }while(j<3);

}


//Two functions for each player's turn
class playerMove{
    int x{}, y{};
    int depth{};

public:
    void p1(){
    std::cout << "Please enter your movement player 1, x y: ";
    std::cin >>x >> y;
    x--; y--;

    if( x > 3 || y > 3 || grid[x][y] != "   "){
    std::cout<<"Please enter a valid movement";
    playerMove().p1();
    }else { grid[x][y]=" X "; }

    turn=true;
    updateGrid();
    }

    void p2(){
    /*std::cout << "\nPlease enter your movement player 2, x y: \n";*/

    depth = 0;
    int bestScore {10000000};
    int bestMov[2]{};

    //Sets the current depth of the game
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(grid[i][j] == "   "){depth++;}
        }
    }

    //Calls the minimax algorithm for every possible move for the O player
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(grid[i][j] == "   "){
                grid[i][j] = " O ";
                int score = minimax(true, depth); //This passes the board corresponding to each move possible by O
                grid[i][j] = "   ";
                if(score < bestScore){  //When it finds the best possible move it saves the flag as bestScore
                bestScore = score;      //so that it doesn't look for draws
                bestMov[0] = i;         //and passes the coordinates to bestMov
                bestMov[1] = j;
                }
            }
        }
    }

    grid[bestMov[0]][bestMov[1]] = " O ";
    turn=false;
    updateGrid();

    /*std::cin >>x >> y;
    x--; y--;

    if( x > 3 || y > 3 || grid[x][y] != "   "){
    std::cout<<"Please enter a valid movement";
    playerMove().p2();
    }else{ grid[x][y]=" O "; }

    turn=false;
    updateGrid();*/
    }
};


bool checkWin(bool player){
    int counter{};  //If counter gets to 3 someone has won
    int tie{};      //If tie gets to 9 the game's a tie

    //Check tie (No available moves)
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(grid[i][j] != "   "){
            tie++;
            }
        }
    }
    if (tie >= 9){
    win = true; playerWon = 0;
    }

    //Checks win for player 1
    if(player == true){
    //Horizontally
    for(int i = 0; i < 3; i++){
        for(int j = 0;  j < 3; j++ ){
            if(grid[i][j]== " X "){counter++;}
                }
            if(counter == 3){win =true; playerWon = 1;}
            counter = 0;
        }
    //Vertically
    for(int i = 0; i < 3; i++){
        for(int j = 0;  j < 3; j++ ){
            if(grid[j][i]== " X "){counter++;}
            }
            if(counter == 3){win =true; playerWon = 1;}
            counter = 0;
        }
    //Diagonally
    for(int i = 0; i < 3; i++ ){
        if(grid[i][i]== " X "){counter++;}

               }
        if(counter == 3){win =true; playerWon = 1;}
        counter = 0;

    int i{0}, j{2};
    do{
        if(grid[i][j]== " X "){counter++;}
        i++; j--;
    }while(i<3);
    if(counter == 3){win =true; playerWon = 1;}
    counter = 0;

    }
    //Check wins for player 2
    if(player == false){
    //Horizontally
    for(int i = 0; i < 3; i++){
        for(int j = 0;  j < 3; j++ ){
            if(grid[i][j]== " O "){counter++;}
                }
            if(counter == 3){win =true; playerWon = -1;}
            counter = 0;
        }
    //Vertically
    for(int i = 0; i < 3; i++){
        for(int j = 0;  j < 3; j++ ){
            if(grid[j][i]== " O "){counter++;}
            }
            if(counter == 3){win =true; playerWon = -1;}
            counter = 0;
        }
    //Diagonally
    for(int i = 0; i < 3; i++ ){
        if(grid[i][i]== " O "){counter++;}
               }
        if(counter == 3){win =true; playerWon = -1;}
        counter = 0;

    int i{0}, j{2};
    do{
        if(grid[i][j]== " O "){counter++;}
        i++; j--;
    }while(i<3);
    if(counter == 3){win =true; playerWon = -1;}
    counter = 0;
    }
    return win;
}

int minimax(bool player,int depth){

    checkWin(player);

    //Return the value corresponding to which player has won
    if(win){

    win = false;
    int scores = playerWon;
    return playerWon;
    }

    //Maximizing player
    if(player){
    int maxEval = -1000000;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){

            if(grid[i][j] == "   "){
        grid[i][j] = " X ";
        int score = minimax(false, depth - 1);
        grid[i][j] = "   ";
        maxEval = std::max (score, maxEval);
                }
            }
        }
    return maxEval;

    //Minimizing player
    }else{
    int minEval = 1000000;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(grid[i][j] == "   "){
        grid[i][j] = " O ";
        int score = minimax(true, depth - 1);
        grid[i][j] = "   ";
        minEval = std::min(score, minEval);
                }
            }
        }
    return minEval;
    }
}


//Draws the grid and turns the players
void updateGrid(){

    std::cout <<"\t 1   2   3 \n";
    std::cout <<"\t"<< grid[0][0]<<"|"<<grid[1][0]<<"|"<<grid[2][0]<<"\t1\n";
    std::cout <<"\t"<<"-----------\n";
    std::cout <<"\t"<< grid[0][1]<<"|"<<grid[1][1]<<"|"<<grid[2][1]<<"\t2\n";
    std::cout <<"\t"<<"-----------\n";
    std::cout <<"\t"<< grid[0][2]<<"|"<<grid[1][2]<<"|"<<grid[2][2]<<"\t3\n";

    if(checkWin(turn)){

        if(playerWon== 1){std::cout<<"Player 1 wins!";}

        if(playerWon== -1){std::cout<<"The bot wins!";}

        if(playerWon== 0){std::cout<<"It's a Draw";}

    }

    else if(turn==false){
    checkWin(turn);
    playerMove().p1();
    }

    else if(turn ==true){
    checkWin(turn);
    playerMove().p2();
    }
}

int main()
{
    createGrid();
    std::cout << "Welcome to TicTacToe!\n";
    updateGrid();

    return 0;
}

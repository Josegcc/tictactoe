#include <iostream>
std::string grid[3][3]{};//The real coordinates of the board
//int coords[5][5]{};      //The coordinates the engine needs in order to play and decide
bool turn{false};
void updateGrid();

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
    std::cout << "\nPlease enter your movement player 2, x y: ";
    std::cin >>x >> y;
    x--; y--;

    if( x > 3 || y > 3 || grid[x][y] != "   "){
    std::cout<<"Please enter a valid movement";
    playerMove().p2();
    }else{ grid[x][y]=" O "; }

    turn=false;
    updateGrid();

    }
};

bool checkWin(bool player){
    bool win{};
    int counter{};

    //Checks win for player 1
    if(player == true){
    //Horizontally
    for(int i = 0; i < 3; i++){
        for(int j = 0;  j < 3; j++ ){
            if(grid[i][j]== " X "){counter++;}
                }
            if(counter == 3){std::cout<<"Player 1 wins!"; win =true;}
            counter = 0;
        }
    //Vertically
    for(int i = 0; i < 3; i++){
        for(int j = 0;  j < 3; j++ ){
            if(grid[j][i]== " X "){counter++;}
            }
            if(counter == 3){std::cout<<"Player 1 wins!"; win =true;}
            counter = 0;
        }
    //Diagonally
    for(int i = 0; i < 3; i++ ){
        if(grid[i][i]== " X "){counter++;}

               }
        if(counter == 3){std::cout<<"Player 1 wins!"; win =true;}
        counter = 0;

    int i{0}, j{2};
    do{
        if(grid[i][j]== " X "){counter++;}
        i++; j--;
    }while(i<3);
    if(counter == 3){std::cout<<"Player 1 wins!"; win =true;}
    counter = 0;

    }
    //Check wins for player 2
    if(player == false){
    //Horizontally
    for(int i = 0; i < 3; i++){
        for(int j = 0;  j < 3; j++ ){
            if(grid[i][j]== " O "){counter++;}
                }
            if(counter == 3){std::cout<<"Player 2 wins!"; win =true;}
            counter = 0;
        }
    //Vertically
    for(int i = 0; i < 3; i++){
        for(int j = 0;  j < 3; j++ ){
            if(grid[j][i]== " O "){counter++;}
            }
            if(counter == 3){std::cout<<"Player 2 wins!"; win =true;}
            counter = 0;
        }
    //Diagonally
    for(int i = 0; i < 3; i++ ){
        if(grid[i][i]== " O "){counter++;}
               }
        if(counter == 3){std::cout<<"Player 2 wins!"; win =true;}
        counter = 0;

    int i{0}, j{2};
    do{
        if(grid[i][j]== " O "){counter++;}
        i++; j--;
    }while(i<3);
    if(counter == 3){std::cout<<"Player 2 wins!"; win =true;}
    counter = 0;
    }


    return win;
}

//Draws the grid and turns the players
void updateGrid(){
    std::cout <<"\t 1   2   3 \n";
    std::cout <<"\t"<< grid[0][0]<<"|"<<grid[1][0]<<"|"<<grid[2][0]<<"\t1\n";
    std::cout <<"\t"<<"-----------\n";
    std::cout <<"\t"<< grid[0][1]<<"|"<<grid[1][1]<<"|"<<grid[2][1]<<"\t2\n";
    std::cout <<"\t"<<"-----------\n";
    std::cout <<"\t"<< grid[0][2]<<"|"<<grid[1][2]<<"|"<<grid[2][2]<<"\t3\n";

    //checkWin(turn);

    if(checkWin(turn) == true){

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

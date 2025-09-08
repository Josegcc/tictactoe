#include <iostream>
std::string grid[3][3]{};//The real coordinates of the board
//int coords[5][5]{};      //The coordinates the engine needs in order to play and decide
bool turn{false};
bool win{false};

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
    int i {}, j {}, counter1{}, counter2{};
    bool win{};
    //First do-while cheks win horizontally
    do{
        if(grid[i][j] == " X " && player == true){counter1++;}
        if(grid[i][j] == " O " && player == false){counter2++;}
    i++;
    if(i>=3){
        j++; i=0;
        if(counter1 == 3 ){std::cout<<"Player 1 wins!"; win = true;}
        if(counter2 == 3 ){std::cout<<"Player 2 wins!"; win = true;}
        counter1 = 0;
        counter2 = 0;
        }

    }while(j<3);

    //Second do-while checks vertically
    do{
        if(grid[i][j] == " X " && player == true){counter1++;}
        if(grid[i][j] == " O " && player == false){counter2++;}

    j++;
    if(j>=3){
        i++; j=0;
        if(counter1 == 3){std::cout<<"Player 1 wins!";  win = true;}
        if(counter2 == 3){std::cout<<"Player 2 wins!";  win = true;}
        counter1 = 0;
        counter2 = 0;
        }
    }while(i<3);

    //Third do-while checks both diagonals

    /*do{
        if(grid[i][j] == " X " && player == true){counter1++;}
        if(grid[i][j] == " O " && player == false){counter2++;}

    j++; i++;
            if(counter1 == 3){std::cout<<"Player 1 wins!";  win = true;}
            if(counter2 == 3){std::cout<<"Player 2 wins!";  win = true;}
    if(j >= 3){
        counter1 = 0;
        counter2 = 0;
        i = 0;

        }
    }while(i>=0);*/

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

    checkWin(turn);

    if(checkWin(turn) == true){

    }

    else if(turn==false){
    playerMove().p1();
    }

    else if(turn ==true){
    playerMove().p2();
    }

    //if(win == true){You win!}
}

int main()
{
    createGrid();
    std::cout << "Welcome to TicTacToe!\n";
    updateGrid();

    return 0;
}

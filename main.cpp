#include <iostream>
std::string Grid[3][3]{};//The real coordinates of the board
int Coords[5][5]{};      //The coordinates the engine needs in order to play and decide
bool turn{false};

void updateGrid();

//Shape the empty spaces before drawing the grid
    void createGrid(){
int i = 0, j = 0;
 do{
    Grid[i][j]="   ";
    i++;

    if(i>=3){
        j++; i=0;
        }

} while(j<=3);

                }

//Two functions for each player's turn
class playerMove{
    int x{}, y{};

public:
    void p1(){
    std::cout << "Please enter your movement player 1, x y: ";
    std::cin >>x >> y;
    x--; y--;
    Grid[x][y]=" X ";
    turn=true;
    updateGrid();
    }

    void p2(){
    std::cout << "\nPlease enter your movement player 2, x y: ";
    std::cin >>x >> y;
    x--; y--;
    Grid[x][y]=" O ";
    turn=false;
    updateGrid();
    }
};


//Draws the grid and turns the players
void updateGrid(){
    std::cout <<"\t 1   2   3 \n";
    std::cout <<"1\t"<< Grid[0][0]<<"|"<<Grid[1][0]<<"|"<<Grid[2][0]<<'\n';
    std::cout <<"\t"<<"-----------\n";
    std::cout <<"2\t"<< Grid[0][1]<<"|"<<Grid[1][1]<<"|"<<Grid[2][1]<<'\n';
    std::cout <<"\t"<<"-----------\n";
    std::cout <<"3\t"<< Grid[0][2]<<"|"<<Grid[1][2]<<"|"<<Grid[2][2]<<'\n';

    if(turn==false){
    playerMove().p1();
    }
    else if(turn ==true){
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

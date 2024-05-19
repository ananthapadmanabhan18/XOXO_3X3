#include <iostream>
#include <ctime>
#include <chrono>
#include <thread>
#include <stdlib.h>

void drawboard(char* cells);

void printWelcome(){


    std::cout<<"      ___       __   __         ___    ___  __       "<<std::endl;
    std::cout<<"|  | |__  |    /  ` /  \\  |\\/| |__      |  /  \\      "<<std::endl;
    std::cout<<"|/\\| |___ |___ \\__, \\__/  |  | |___     |  \\__/      "<<std::endl;
    std::cout<<"                                                     "<<std::endl;
    std::cout<<"___    __     ___       __     ___  __   ___         "<<std::endl;
    std::cout<<" |  | /  `     |   /\\  /  `     |  /  \\ |__          "<<std::endl;
    std::cout<<" |  | \\__,     |  /~~\\ \\__,     |  \\__/ |___         "<<std::endl;
    std::cout<<" __              ___                                 "<<std::endl;
    std::cout<<"/ _`  /\\   |\\/| |__                                  "<<std::endl;
    std::cout<<"\\__> /~~\\  |  | |___                                 "<<std::endl;
    std::cout<<"                                                     "<<std::endl;


    std::cout << "The board numbering is shown below:" << std::endl;

    char sample_cells[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    drawboard(sample_cells);


    std::cout << "You will be playing as 'X' and the computer will be playing as 'O'" << std::endl;

    std::cout << "To make a move, enter the number of the cell you want to place your 'X' in" << std::endl;

    std::cout << "To start the game type s and to quit type q" << std::endl;

    char start;
    std::cin >> start;
    if(start == 'q'){
        std::cout << "Quitting the game!" << std::endl;
        exit(0);
    }
    else if(start == 's'){
        std::cout << "Let's start the game!" << std::endl;
    }
    else{
        std::cout << "Invalid input! Please type s to start the game or q to quit!" << std::endl;
    }

    std::cout << "Let's start the game!" << std::endl;
    

}




void drawboard(char* cells){
    std::cout << " " << cells[0] << " | " << cells[1] << " | " << cells[2] << std::endl;
    std::cout << "---|---|---" << std::endl;
    std::cout << " " << cells[3] << " | " << cells[4] << " | " << cells[5] << std::endl;
    std::cout << "---|---|---" << std::endl;
    std::cout << " " << cells[6] << " | " << cells[7] << " | " << cells[8] << std::endl;
}





void pMove(char* cells, char player){
    int n;
    do{
        std::cout << "Enter a number between 1 and 9: ";
        std::cin >> n;
        n--;

        //Check if n is an integer
        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Invalid input! choose another one!" << std::endl;
            continue;
        }

        if(cells[n] == ' '){
            cells[n] = player;
            break;
        }
        else if (cells[n] == 'X'){
            std::cout << "Cell already Occupied by the player! choose another one!" << std::endl;
        }
        else if (cells[n] == 'O'){
            std::cout << "Cell already Occupied by the computer! choose another one!" << std::endl;
        }
        else{
            std::cout << "Invalid input! choose another one!" << std::endl;
        }
    }while(!n > 0 || !n < 8);
}





void cMove(char* cells, char computer){
    int n_rand;
    srand(time(0));
    while(true){
        n_rand = rand() % 9;
        if(cells[n_rand] == ' '){
            cells[n_rand] = computer;
            break;
        }
    }
    

}







bool checkwin(char* cells, char player, char computer){

    //checking rows
    if(cells[0]!= ' ' && cells[0]==cells[1] && cells[1]==cells[2]){
        // cells[0] == player ? std::cout << "Player wins!" << std::endl : std::cout << "Computer wins!" << std::endl;
        return true;
    }
    else if(cells[3]!= ' ' && cells[3]==cells[4] && cells[4]==cells[5]){
        // cells[3] == player ? std::cout << "Player wins!" << std::endl : std::cout << "Computer wins!" << std::endl;
        return true;
    }
    else if(cells[6]!= ' ' && cells[6]==cells[7] && cells[7]==cells[8]){
        // cells[6] == player ? std::cout << "Player wins!" << std::endl : std::cout << "Computer wins!" << std::endl;
        return true;
    }

    //checking columns
    else if(cells[0]!= ' ' && cells[0]==cells[3] && cells[3]==cells[6]){
        // cells[0] == player ? std::cout << "Player wins!" << std::endl : std::cout << "Computer wins!" << std::endl;
        return true;
    }
    else if(cells[1]!= ' ' && cells[1]==cells[4] && cells[4]==cells[7]){
        // cells[1] == player ? std::cout << "Player wins!" << std::endl : std::cout << "Computer wins!" << std::endl;
        return true;
    }
    else if(cells[2]!= ' ' && cells[2]==cells[5] && cells[5]==cells[8]){
        // cells[2] == player ? std::cout << "Player wins!" << std::endl : std::cout << "Computer wins!" << std::endl;
        return true;
    }

    //checking diagonals
    else if(cells[6]!= ' ' && cells[6]==cells[4] && cells[4]==cells[2]){
        // cells[6] == player ? std::cout << "Player wins!" << std::endl : std::cout << "Computer wins!" << std::endl;
        return true;
    }
    else if(cells[0]!= ' ' && cells[0]==cells[4] && cells[4]==cells[8]){
        // cells[0] == player ? std::cout << "Player wins!" << std::endl : std::cout << "Computer wins!" << std::endl;
        return true;
    }
    else{
        return false;
    }
}







bool checkDraw(char* cells){

    for(int i=0; i<9; i++){
        if(cells[i] == ' '){
            return false;
        }
    }
    return true;
}
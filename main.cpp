#include "game_functions.hpp"



char cells[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

int main() {
    char player = 'X';
    char computer = 'O';
    bool gameOver = false;


    printWelcome();

    int i=1;


    while(gameOver==false){


        // Player's turn
        pMove(cells, player);


        drawboard(cells);

        // Check if the player has won
        if(checkwin(cells, player,computer)){
        std::cout<<"-----------------------------------"<<std::endl;
        std::cout<<"------------- You Win -------------"<<std::endl;
        std::cout<<"-----------------------------------"<<std::endl;
            gameOver = true;
            break;

        }
        else if(checkDraw(cells)){
            drawboard(cells);
            std::cout << "It's a draw!" << std::endl;
            gameOver = true;
            break;

        }


        //sleep for 3 seconds;
        std::cout << "Computer is thinking.." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(3));



        // Computer's turn
        cMove(cells, computer);


        // Check if the computer has won
        if(checkwin(cells, player,computer)){
        drawboard(cells);
        std::cout<<"-----------------------------------"<<std::endl;
        std::cout<<"------------- You Lose ------------"<<std::endl;
        std::cout<<"-----------------------------------"<<std::endl;
            gameOver = true;
            break;
        } 
        else if(checkDraw(cells)){
            // drawboard(cells);
        std::cout<<"-----------------------------------"<<std::endl;
        std::cout<<"------------ Game Drawn -----------"<<std::endl;
        std::cout<<"-----------------------------------"<<std::endl;
            gameOver = true;
            break;

        }               
        system("CLS");
        std::cout<<" The Current Board Position in move number: " <<i<<" is : \n"<<std::endl;
        drawboard(cells);
        i++;
    }


    return 0;
}
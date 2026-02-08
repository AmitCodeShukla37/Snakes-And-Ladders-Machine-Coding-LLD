#include "Game.h"
#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[]){
    if(argc < 2){
        std::cout << "Input File Not Provided. Usage: " << argv[0] << " <filename.txt> " << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::ifstream file(filename);

    if(!file.is_open()){
        std::cout << "Error: Could not open the input file " << filename << std::endl;
        return 1;
    }

    Game snakes_and_ladders;
    snakes_and_ladders.read(file);
    snakes_and_ladders.Play();
    return 0;
}
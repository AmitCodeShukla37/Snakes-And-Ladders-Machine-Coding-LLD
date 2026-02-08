#ifndef GAME_H
#define GAME_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "Player.h"
#include "Environment_Elements.h"

class Game{
    private:
        std::vector<Player> players;
        std::vector<Element> ladders;
        std::vector<Element> snakes;
        std::vector<int> Game_Grid;
        int num_players, turn, num_snakes, num_ladders;

    public:
        void Play();
        void IntializeGame();
        void read(std::istream& file);

    private:
        int RollDice();
        int GetPosition(int curr_pos);
};

#endif
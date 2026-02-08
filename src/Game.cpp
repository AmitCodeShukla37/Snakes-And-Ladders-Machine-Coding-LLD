#include "Game.h"
#include <bits/stdc++.h>
#define GRID_SIZE 100
using namespace std;

void Game::read(istream& file){
    file >> Game::num_snakes;

    for(int i = 0; i < Game::num_snakes; i++){
        Element snake;
        file >> snake.start_pos >> snake.end_pos;
        Game::snakes.push_back(snake);
    }

    file >> Game::num_ladders;

    for(int i = 0; i < Game::num_ladders; i++){
        Element ladder;
        file >> ladder.start_pos >> ladder.end_pos;
        Game::ladders.push_back(ladder);
    }

    string name; file >> Game::num_players;
    while(file >> name){
        Player player;
        player.name = name;
        player.pos = 0;
        Game::players.push_back(player);
    }

    Game::turn = 0;

    IntializeGame();
}


void Game::IntializeGame(){
    Game::Game_Grid.resize(GRID_SIZE + 1);
    for(int i = 0; i < GRID_SIZE + 1; i++){
        Game::Game_Grid[i] = i; 
    }
    
    for(int i = 0; i < Game::num_ladders; i++){
        Game::Game_Grid[Game::ladders[i].start_pos] = Game::ladders[i].end_pos;
    }
    for(int i = 0; i < Game::num_snakes; i++){
        Game::Game_Grid[Game::snakes[i].start_pos] = Game::snakes[i].end_pos;
    }

    cout << "Game Setup Complete ! Proceeding to Playground\n" << endl;

    return;
}


int Game::GetPosition(int curr_pos){
    if(curr_pos > 100){
        return -1;
    }
    else{
        while(Game::Game_Grid[curr_pos] != curr_pos){
            curr_pos = Game::Game_Grid[curr_pos];
        }
        return curr_pos;
    }
}


int Game::RollDice(){
    static std::random_device rd;
    static auto seed_time = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    static std::mt19937 gen(static_cast<unsigned int>(rd() ^ seed_time));
    static std::uniform_int_distribution<int> dice(1, 6);
    int roll = dice(gen);
    return roll;
}


void Game::Play(){
    while(true){
        cout << endl;
        int roll = 0, steps = 1, curr_pos = Game::players[Game::turn].pos, temp_pos = curr_pos;
        vector<int> moves;
        while(true){
            roll = RollDice();
            moves.push_back(roll);
            int new_pos = GetPosition(temp_pos + roll);
            if(new_pos == -1 || roll < 6){
                temp_pos = (new_pos == -1 ? curr_pos : new_pos);
                break;
            }
            else{
                if(steps == 3){
                    temp_pos = curr_pos;
                    break;
                }
            }
            temp_pos = new_pos;
            steps++;
        }
        cout << Game::players[Game::turn].name << " rolled a ";
        for(auto m : moves){
            cout << m << ", ";
        }
        if(temp_pos == curr_pos){
            cout << "and remained at " << temp_pos << endl;
        }
        else{
            cout << "and moved from " << curr_pos << " to " << temp_pos << endl << endl;
        }
        Game::players[turn].pos = temp_pos;
        if(Game::players[turn].pos == GRID_SIZE){
            cout << Game::players[turn].name << " Wins !\n\nGame Over !\n" << endl;
            break;
        }
        cout << endl;
        Game::turn = (Game::turn + 1) % Game::num_players;
    }

    return;
}
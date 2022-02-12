//
//  main.cpp
//  Perdle
//
//  Created by Lexie Finkelstein on 2/8/22.
//  Copyright © 2022 Lexie Finkelstein. All rights reserved.
//

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "newgame.h"
using namespace std;

int main(int argc, const char * argv[]) {
    cout << "Perdle\n Where the P stands for project birthed from procrastination of my homework\n\nby akfink\n";
    //create an instance of game player
    newgame game;
    
    //check if user inputted a file name for custom wordbank
    
    //no file name inputted - set default work bank
    if (argc == 1){
        game.set_custom_wordbank(false);
        game.set_default_bank();
    }
    else if (argc == 2){
        game.set_custom_wordbank(true);
        game.set_custom_file_name(argv[0]);
    }
    else {
        cout << "Invalid argument. Program Exiting\n";
        exit(1);
    }
    
    cout << "Enter a number 1-100: \n";
    cin >> game.seed;
    game.magical_word_picker();
    game.make_magic_map();
    
    bool enter_mode = true;
    cout << "Magic word generated!\n"
     << " Select a mode by typing a number: \n";
    
    while (enter_mode == true){
        cout << "(1) Classic - 6 guesses \n"
        << "(2) Unlimited Guesses \n"
        << "(3) Custom \n";
        cin >> game.mode;
        
        if (game.mode == 1){
            game.MAX_guesses = 6;
            enter_mode = false;
        }
        else if (game.mode == 2){
            game.unlimited = true;
            enter_mode = false;
        }
        else if (game.mode == 3){
            cout << "Enter custom number of maximum guesses: \n";
            cin >> game.MAX_guesses;
            enter_mode = false;
        }
        else {
            cout << "Invalid mode. Please choose a mode 1-3: \n";
        }
    }

    game.create_map();

    cout << " _ _ _ _ _ _ \n";
    while (game.continue_play){
        cin >> game.guess;
        if(game.word_map.find(game.guess) == game.word_map.end()){
            cout << "Not found in word list!\n";
        }
        else if(game.guess.length() != 5){
            cout << "Don't include spaces in guess//5 letter guess max\n";
        }
        else{
            game.check();
            cout << game.process_guess() << endl;
            ++game.num_guesses;
            if (game.num_guesses == game.MAX_guesses){
                game.continue_play = false;
            }
        }
    }
    cout << "Your word was " << game.get_magic() << ". \n";
    cout << "Better Luck Next Time!" << endl;
    return 0;
}

#include <fstream>
#include <iostream>
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <unordered_map>
#include <vector>
#include "defaultbank.h"
#include "newgame.h"
using namespace std;

int main() {
  newgame game;
  game.set_custom_wordbank(true);
  string word = game.get_magic_word();
  game.make_magic_map();
  game.create_map();
  string current_guess = "";
  for(int i = 0; i < 5; i++){
    // get input
    cout << "enter 5 letter guess\n";
    cin >> current_guess;
    game.guess = current_guess;
    game.process_guess();
  }



}
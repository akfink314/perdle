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
  cout << game.magic_word;
  cout << "created new game";
}
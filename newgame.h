#include <fstream>
#include <iostream>
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <unordered_map>
#include <vector>
#include "defaultbank.h"
using namespace std;

//Class to store newgame data

class newgame{
    //private variables
    bool custom_wordbank = false;
    string custom_file_name;
    string magic_word = "hello";
    vector<string> wordbank;
    int magicindex;

    //private functions
    vector<string> open_and_store(string name){
        vector<string> file_content;
        string word;
        ifstream readfile(name);
        while (getline(readfile, word)) {
            file_content.push_back(word);
        }
        return file_content;
    }
    
    vector<string> previous_guess;
    vector<string> guess_state;
    int BANK_SIZE = 0;
 public:
    int num_guesses = 0;
    bool correct = false;
    int seed = -1;
    string guess;
    int MAX_guesses = 0;
    bool unlimited = false;
    int mode = 0;
    bool continue_play = true;
    unordered_map<string, char> word_map;
    unordered_map<char, int> magic_map;
    
    void set_custom_wordbank(bool input){
        if (input == true){
            custom_wordbank = true;
        }
        else{
            custom_wordbank = false;
        }
    }
    
    void set_custom_file_name(string name){
        custom_file_name = name;
        wordbank = open_and_store(name);
        BANK_SIZE = static_cast<int>(wordbank.size());
    }
    void set_default_bank(){
       wordbank = default_bank;
        BANK_SIZE = 5757;
    }

    void add_to_map(string word){
        pair<string, char> insert;
        insert.first = word;
        insert.second = '\0';
        word_map.insert(insert);
    }
    
    void create_map(){
        for (int i = 0; i < BANK_SIZE; ++i){
            add_to_map(wordbank[i]);
        }
    }
    
    void magical_word_picker(){
        srand(seed);
        magicindex = rand() % 5756;
        magic_word = wordbank.at(magicindex);
    }
    
    void make_magic_map(){
        for (int i = 0; i < 5; ++i){
            pair<char, int> letter;
            letter.first = magic_word[i];
            letter.second = i;
            magic_map.insert(letter);
        }
    }
    
    string get_magic_word(){
        return magic_word;
    }
    
    string process_guess(){
        cout << endl;
        for (int i = 0; i < 5; ++i){
            cout << guess[i] << " ";
        }
        cout << endl;
        string results = "";
        for (int i = 0; i < 5; ++i){
            if (magic_map.find(guess[i]) == magic_map.end()){
                results += "X ";
            }
            else {
                if (magic_map.find(guess[i])->second == i){
                    results += "V ";
                }
                else {
                    results += "- ";
                }
            }
        }
        return results;
    }
    
    void check(){
        if (guess == magic_word){
            cout << "VVVVV" << endl << "You Win!" << endl;
            exit(0);
        }
        
    }
};

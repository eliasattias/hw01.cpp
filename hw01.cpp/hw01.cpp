//
//  main.cpp
//  hw01.cpp
//
//  Created by Elias Attias on 1/29/20.
//  Copyright © 2020 Elias Attias. All rights reserved.
//  This program will read an encrypted file and decrypt it line by line.

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

char character(char encrypted, int steps);
void line(string& line, int steps);

//This function decrypts a single character and returns it
char character(char encrypted, int steps){
    char decrypted = encrypted - steps;
    if (encrypted >= 'a' && encrypted <= 'z'){
        if (decrypted < 'a'){
            decrypted += 'z' - 'a' + 'b' - 'a';
        }
        return decrypted;
    }
    return encrypted;
}

//This function calls the character function to decrypt the characters in a line
void line(string& line, int steps){
    for (char item : line){
        item = character(item, steps);
    }
}

int main(){
    ifstream encrypted("encrypted.txt");
    if (!encrypted){
        cerr << "could not open the file";
        exit(1);
    }
    int steps;
    string str;
    vector<string> vectorOfLines;
    encrypted >> steps;
    while (getline(encrypted, str)){ //The loop reads a line and acts accordingly.
        line(str,steps);
        vectorOfLines.push_back(str);
    }
    size_t amount = vectorOfLines.size();
    for (size_t i = amount - 1; i > 0; i--){
        cout << vectorOfLines[i] << endl; //This code outputs the strings inside the vector in reverse order.
    }
    encrypted.close();
}




#include "Lexer.h"
#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char** argv) {


    string inputstr;

    if (argc != 2) {
        return 1;
    }

    // open file
    string fileName = argv[1];
    ifstream input(fileName);
    if (!input.is_open()) {
        return 1;
    }
    while (!input.eof())
    {
        string x;
        getline(input,x);
        inputstr += x;
        if(!input.eof()){
            inputstr += '\n';
        }
    }
    Lexer* lexer = new Lexer();
    lexer->Run(inputstr);

    delete lexer;

    return 0;
}
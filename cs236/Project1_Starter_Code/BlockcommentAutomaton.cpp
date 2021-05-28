#include "BlockcommentAutomaton.h"

void BlockcommentAutomaton::S0(const std::string& input) {
    if (input[index] == '#') {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}
void BlockcommentAutomaton::S1(const std::string& input) {
    if(input[index] == '\n'){
        newLines++;
        index++;
        S1(input);
    }
    else if (input[index] == '|') {
        inputRead++;
        index++;
        S2(input);
    }
    else {
        Serr();
    }
}
void BlockcommentAutomaton::S2(const std::string& input) {
    if((int)input.size() - 1 == (int)index){
        type = TokenType::UNDEFINED;
        inputRead++;
        if(input[index] == '\n'){
            newLines++;
        }
    }
    else if (input[index] == '|') {
        inputRead++;
        index++;
        S3(input);
    }
    else {
        if(input[index] == '\n'){
            newLines++;
        }
        inputRead++;
        index++;
        S2(input);
    }
}
void BlockcommentAutomaton::S3(const std::string& input) {
    if (input[index] == '#') {
        inputRead++;
    }
    else if((int)input.size() - 1 == (int)index){
        type = TokenType::UNDEFINED;
        inputRead++;
        if(input[index] == '\n'){
            newLines++;
        }
    }
    else {
        if(input[index] == '\n'){
            newLines++;
        }
        inputRead++;
        index++;
        S2(input);
    }
}
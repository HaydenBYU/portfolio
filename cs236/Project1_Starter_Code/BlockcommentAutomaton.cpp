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
    if (input[index] == '|') {
        inputRead++;
        index++;
        S3(input);
    }
    else {
        inputRead++;
        index++;
        S2(input);
    }
}
void BlockcommentAutomaton::S3(const std::string& input) {
    if (input[index] == '#') {
        inputRead++;
    }
    else {
        inputRead++;
        index++;
        S2(input);
    }
}
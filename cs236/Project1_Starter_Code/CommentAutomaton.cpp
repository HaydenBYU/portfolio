#include "CommentAutomaton.h"

void CommentAutomaton::S0(const std::string& input) {
    if (input[index] == '#') {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}
void CommentAutomaton::S1(const std::string& input) {
    if (input[index] == '\n' || index == input.size() ) {

    }
    else if(input[index] == '|'){
        Serr();
    }
    else {
        inputRead++;
        index++;
        S1(input);
    }
}

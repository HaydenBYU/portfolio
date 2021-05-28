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
    if (input[index] == '\n' || index == (int)input.size() ) {

    }
    else if(index == 1 && input[index] == '|'){
        Serr();
    }
    else {
        inputRead++;
        index++;
        S1(input);
    }
}

#include "IdAutomaton.h"
#include <cctype>

void IdAutomaton::S0(const std::string& input) {
    if (isalpha(input[index])) {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}
void IdAutomaton::S1(const std::string& input) {
    if(input[index] == ' '){
        if(input.substr(0,inputRead)== "Facts" || input.substr(0,inputRead)== "Rules" || input.substr(0,inputRead)== "Schemes" || input.substr(0,inputRead)== "Queries"){
            Serr();
        }

    }
    else if (isalnum(input[index]) || input[index] =='_') {
        inputRead++;
        index++;
        S1(input);
    }
    //FIXME: if the ID is one of Queries, Facts, Rules, etc it needs to change.
    else {
        if(input.substr(0,inputRead)== "Facts" || input.substr(0,inputRead)== "Rules" || input.substr(0,inputRead)== "Schemes" || input.substr(0,inputRead)== "Queries"){
            Serr();
        }
    }
}

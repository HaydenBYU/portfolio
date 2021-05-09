#ifndef RIGHTPARENAUTOMATON_H
#define RIGHTPARENAUTOMATON_H

#include "Automaton.h"

class RightparenAutomaton : public Automaton
{
public:
    RightparenAutomaton() : Automaton(TokenType::RIGHT_PAREN) {}  // Call the base constructor

    void S0(const std::string& input);
};

#endif // RIGHTPARENAUTOMATON_H


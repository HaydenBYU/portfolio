#ifndef LEFTPARENAUTOMATON_H
#define LEFTPARENAUTOMATON_H

#include "Automaton.h"

class LeftparenAutomaton : public Automaton
{
public:
    LeftparenAutomaton() : Automaton(TokenType::LEFT_PAREN) {}  // Call the base constructor

    void S0(const std::string& input);
};

#endif // LEFTPARENAUTOMATON_H


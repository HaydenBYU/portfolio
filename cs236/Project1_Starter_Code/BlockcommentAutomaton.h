#ifndef BLOCKCOMMENTAUTOMATON_H
#define BLOCKCOMMENTAUTOMATON_H

#include "Automaton.h"

class BlockcommentAutomaton : public Automaton
{
private:
    void S1(const std::string& input);
    void S2(const std::string& input);
    void S3(const std::string& input);

public: BlockcommentAutomaton() : Automaton(TokenType:: COMMENT) {}  // Call the base constructor

    void S0(const std::string& input);

};

#endif // COMEMNTAUTOMATON_H


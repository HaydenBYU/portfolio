#ifndef AUTOMATON_H
#define AUTOMATON_H
#include "Token.h"

class Automaton
{
protected:
    int inputRead = 0;
    int newLines = 0;
    int index = 0;
    TokenType type;

public:
    // Default constructor -- since we have a constructor that takes a parameter,
    //   the compiler will autogenerate a default constructor if not explicit.
    Automaton() : Automaton(TokenType::UNDEFINED) {}

    Automaton(TokenType type) { this->type = type; }

    // Start the automaton and return the number of characters read
    //   read == 0 indicates the input was rejected
    //   read  > 0 indicates the input was accepted
    int Start(const std::string& input) {
        newLines = 0;
        inputRead = 0;
        index = 0;
        S0(input);
        return inputRead;
    }

    // Every subclass must define this method
    //FIXME: States after 0 may not need to be here
    virtual void S0(const std::string& input) = 0;
    /*virtual void S1(const std::string& input) = 0;
    virtual void S2(const std::string& input) = 0;
    virtual void S3(const std::string& input) = 0;
    virtual void S4(const std::string& input) = 0;
    virtual void S5(const std::string& input) = 0;
    virtual void S6(const std::string& input) = 0;
    virtual void S7(const std::string& input) = 0;*/
    void Serr() {
        // Indicate the input was rejected
        inputRead = 0;
    }

    virtual Token* CreateToken(std::string input, int lineNumber) { return new Token(type, input, lineNumber); }

    int NewLinesRead() const { return newLines; }
};

#endif // AUTOMATON_H


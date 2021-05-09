#include "Lexer.h"
#include "ColonAutomaton.h"
#include "ColonDashAutomaton.h"
#include "AddAutomaton.h"
#include "MultiplyAutomaton.h"
#include "QmarkAutomaton.h"
#include "LeftparenAutomaton.h"
#include "RightparenAutomaton.h"
#include "CommentAutomaton.h"
#include "StringAutomaton.h"
#include "QueriesAutomaton.h"
#include "IdAutomaton.h"
#include "RulesAutomaton.h"
#include "FactsAutomaton.h"
#include "SchemesAutomaton.h"
#include "BlockcommentAutomaton.h"
#include <iostream>






Lexer::Lexer() {
    CreateAutomata();
}

Lexer::~Lexer() {
    for(Automaton* automaton : automata){
        delete automaton;
    }
    for (Token* token : tokens) {
        delete token;
    }
    /*automata.push_back(new ColonAutomaton());
    automata.push_back(new ColonDashAutomaton());
    automata.push_back(new AddAutomaton());
    automata.push_back(new MulitplyAutomaton());
    automata.push_back(new QueriesAutomaton());
    automata.push_back(new RulesAutomaton());
    automata.push_back(new CommentAutomaton());
    automata.push_back(new FactsAutomaton());
    automata.push_back(new IdAutomaton());
    automata.push_back(new SchemesAutomaton());
    automata.push_back(new StringAutomaton());
    automata.push_back(new LeftparenAutomaton());
    automata.push_back(new RightparenAutomaton());
    automata.push_back(new QmarkAutomaton());
    //automata.push_back(new UndefinedAutomaton());*/
    // TODO: need to clean up the memory in `automata` and `tokens`
}

void Lexer::CreateAutomata() {
    automata.push_back(new ColonAutomaton());
    automata.push_back(new ColonDashAutomaton());
    automata.push_back(new AddAutomaton());
    automata.push_back(new MultiplyAutomaton());
    automata.push_back(new QueriesAutomaton());
    automata.push_back(new RulesAutomaton());
    automata.push_back(new CommentAutomaton());
    automata.push_back(new FactsAutomaton());
    automata.push_back(new SchemesAutomaton());
    automata.push_back(new StringAutomaton());
    automata.push_back(new LeftparenAutomaton());
    automata.push_back(new RightparenAutomaton());
    automata.push_back(new QmarkAutomaton());
    automata.push_back(new BlockcommentAutomaton());
    automata.push_back(new IdAutomaton());
    //automata.push_back(new UndefinedAutomaton());
    // TODO: Add the other needed automata here
}

void Lexer::Run(std::string& input) {
    // TODO: convert this pseudo-code with the algorithm into actual C++ code
    int lineNum = 1;
    while(input.size() > 0){
        int maxRead = 0;
        //for(int i = 0; i < automata.size(); i++){
        Automaton* maxAutomaton = automata[0];
        for(unsigned int i = 0; i < automata.size(); i++){
          int inputRead = automata[i]->Start(input);
          if (inputRead > maxRead){
              maxRead = inputRead;
              maxAutomaton = automata[i];
          }
        }
        if(maxRead > 0){
            string tokenStr;
            for(unsigned int i = 0; i < maxRead; i++ ){
                tokenStr += input[i];
            }
            Token* newToken = maxAutomaton->CreateToken(tokenStr, lineNum);
            lineNum += maxAutomaton->NewLinesRead();
            tokens.push_back(newToken);
        }
        else{
            maxRead = 1;
            if(input[0] == ' '){
            }
            else if(input[0] == '\n'){
                lineNum++;
            }
            else{
                Token* newToken= maxAutomaton->CreateToken(input.substr(0,maxRead),lineNum);
                newToken->SetType("UNDEFINED");
                tokens.push_back(newToken);
            }


        }
        input.erase(input.begin(),input.begin()+maxRead);
        //cout << "This is my input after deleting" << input << endl;

    }
    Automaton* Deceptaton = automata[0];
    Token* EOFToken = Deceptaton->CreateToken("",lineNum);
    EOFToken->SetType("EOF_TYPE");
    tokens.push_back(EOFToken);
    Token* JRRToken;
    for(unsigned int i = 0; i < tokens.size(); i++){
        JRRToken->ToString(tokens.at(i));

    }
    cout << "Total Tokens = " << tokens.size() << endl;
    /*
    set lineNumber to 1
    // While there are more characters to tokenize
    loop while input.size() > 0 {
        set maxRead to 0
        set maxAutomaton to the first automaton in automata
        // TODO: you need to handle whitespace inbetween tokens
        // Here is the "Parallel" part of the algorithm
        //   Each automaton runs with the same input
        foreach automaton in automata {
            inputRead = automaton.Start(input)
            if (inputRead > maxRead) {
                set maxRead to inputRead
                set maxAutomaton to automaton
            }
        }
        // Here is the "Max" part of the algorithm
        if maxRead > 0 {
            set newToken to maxAutomaton.CreateToken(...)
                increment lineNumber by maxAutomaton.NewLinesRead()
                add newToken to collection of all tokens
        }
        */
    /*
        // No automaton accepted input
        // Create single character undefined token
        else {
            set maxRead to 1
                set newToken to a  new undefined Token
                (with first character of input)
                add newToken to collection of all tokens
        }
        // Update `input` by removing characters read to create Token
        remove maxRead characters from input
    }
    add end of file token to all tokens
    */
}

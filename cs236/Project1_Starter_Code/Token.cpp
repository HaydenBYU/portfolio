#include "Token.h"
#include <iostream>
Token::Token(TokenType type, std::string description, int line) {
    kind = enum_to_string(type);
    tokValue = description;
    lineNum = line;
}

void Token::SetType(string maDude) {
    kind = maDude;
}

string Token::enum_to_string(TokenType type) {
    switch(type) {
        case TokenType::COMMA:
            return "COMMA";
        case TokenType::PERIOD:
            return "PERIOD";
        case TokenType::Q_MARK:
            return "Q_MARK";
        case TokenType::LEFT_PAREN:
            return "LEFT_PAREN";
        case TokenType::RIGHT_PAREN:
            return "RIGHT_PAREN";
        case TokenType::MULTIPLY:
            return "MULTIPLY";
        case TokenType::ADD:
            return "ADD";
        case TokenType::SCHEMES:
            return "SCHEMES";
        case TokenType::FACTS:
            return "FACTS";
        case TokenType::RULES:
            return "RULES";
        case TokenType::QUERIES:
            return "QUERIES";
        case TokenType::ID:
            return "ID";
        case TokenType::COLON:
            return "COLON";
        case TokenType::COLON_DASH:
            return "COLON_DASH";
        case TokenType::EOF_TYPE:
            return "EOF";
        case TokenType::UNDEFINED:
            return "UNDEFINED";
        case TokenType::STRING:
            return "STRING";
        case TokenType::COMMENT:
            return "COMMENT";
        default:
            return "COMMA";

    }
    return "UNDEFINED";
}
void Token::ToString(Token* MotherToken) {

    cout << "(" << MotherToken->kind << ",\"" << MotherToken->tokValue << "\"," << MotherToken->lineNum << ")" << endl;
}


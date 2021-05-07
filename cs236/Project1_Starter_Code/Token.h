#ifndef TOKEN_H
#define TOKEN_H
#include <string>
using namespace std;

enum class TokenType {
    COMMA,
    PERIOD,
    Q_MARK,
    LEFT_PAREN,
    RIGHT_PAREN,
    MULTIPLY,
    ADD,
    SCHEMES,
    FACTS,
    RULES,
    QUERIES,
    ID,
    COLON,
    COLON_DASH,
    COMMENT,
    STRING,
    EOF_TYPE,
    UNDEFINED
};

class Token
{
private:
    int lineNum;
    string tokValue;
    string kind;



public:
    Token(TokenType type, std::string description, int line);
    void ToString(Token* MotherToken);
    string enum_to_string(TokenType type);
    void SetType(string maDude);
    // TODO: add other needed methods
};

#endif // TOKEN_H


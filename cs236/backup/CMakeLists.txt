cmake_minimum_required(VERSION 3.16.5)
project(project_1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(project1-exampleIO cmake-build-debug ColonAutomaton.cpp
        ColonAutomaton.h ColonDashAutomaton.cpp ColonDashAutomaton.h Lexer.h Lexer.cpp Token.cpp Token.h
        Automaton.h CommaAutomaton.cpp CommaAutomaton.h main.cpp PeriodAutomaton.cpp PeriodAutomaton.h
        QmarkAutomaton.cpp QmarkAutomaton.h LeftparenAutomaton.cpp LeftparenAutomaton.h RightparenAutomaton.cpp
        RightparenAutomaton.h MultiplyAutomaton.cpp MultiplyAutomaton.h AddAutomaton.cpp AddAutomaton.h
        FactsAutomaton.cpp FactsAutomaton.h RulesAutomaton.cpp RulesAutomaton.h QueriesAutomaton.h
        QueriesAutomaton.cpp SchemesAutomaton.cpp SchemesAutomaton.h IdAutomaton.cpp IdAutomaton.h
        StringAutomaton.cpp StringAutomaton.h CommentAutomaton.cpp CommentAutomaton.h BlockcommentAutomaton.cpp
        BlockcommentAutomaton.h)

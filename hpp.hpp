#ifndef _H_HPP
#define _H_HPP

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <map>
using namespace std;

struct Base {					// must be virtual class
	string val;
	virtual string dump();
};

struct Num:Base { Num(double d); double val; string dump(); };
struct Str:Base { Str(string *s); Str(char*); string *val; string dump(); };

extern map<string,Base*> vars;

extern int yylex();				// lexer interface
extern int yylineno;
extern char* yytext;
extern int yyparse();			// parser interface
extern void yyerror(string);	// error callback
#include "ypp.tab.hpp"

#endif // _H_HPP

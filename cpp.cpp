#include "hpp.hpp"

int main(int argc, char *argv[]) {
	// dump parameters
	for (int i = 0; i < argc; i++)
		cout << i << ": " << argv[i] << endl;
	// run .ini interpreter
	yyparse();
	// dump variables
	for (auto it = vars.begin(),e=vars.end(); it!=e; it++)
		cout << it->first << "=" << it->second << endl;
	return 0;
}

// syntax parser error callback
#define YYERR "\n\n"<<yylineno<<":"<<msg<<"["<<yytext<<"]\n\n"
void yyerror(string msg) { cout<<YYERR; cerr<<YYERR; exit(-1); }

// variables table
map<string,Base*> vars;

string Base::dump() { return "<base>"; }

Num::Num(double d) { val = d; }
string Num::dump() { ostringstream os;
	os << "<num:" << val << ">"; return os.str(); }

Str::Str(string *s) { val = s; }
Str::Str(char *c) { val = new string(c); }
string Str::dump() { ostringstream os;
	os << "<str:" << *val << ">"; return os.str(); }

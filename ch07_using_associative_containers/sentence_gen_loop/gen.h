#ifndef GUARD_gen_h
#define GUARD_gen_h

#include <vector>
#include <string>
#include <map>
#include <iostream>

typedef std::vector<std::string> Rule;
typedef std::vector<Rule> Rule_collection;
typedef std::map<std::string, Rule_collection> Grammar;

Grammar read_grammar(std::istream &);
std::vector<std::string> gen_sentence(const Grammar &);
bool bracketed(const std::string &);
void gen_aux(const Grammar &, const std::string &, std::vector<std::string> &);
int nrand(int n);

#endif

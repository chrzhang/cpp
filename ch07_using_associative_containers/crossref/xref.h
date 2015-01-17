#ifndef GUARD_xref_h
#define GUARD_xref_h

#include <map>
#include <string>
#include <vector>
#include <iostream>
#include "split.h"

std::map<std::string, std::vector<int> > xref(std::istream & in,
              std::vector<std::string> find_words(const std::string &) = split);

#endif

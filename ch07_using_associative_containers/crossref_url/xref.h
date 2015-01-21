#ifndef GUARD_xref_h
#define GUARD_xref_h

#include <map>
#include <string>
#include <vector>
#include <iostream>
#include "split.h"
#include "url.h"

std::map<std::string, std::vector<int> > xref(std::istream & in,
              std::vector<std::string> find_words(const std::string &) =
              find_urls);

#endif

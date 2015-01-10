#ifndef GUARD_kwic_h
#define GUARD_kwic_h

#include <list>
#include <string>

std::list<std::list<std::string>> generateRotations(
    const std::list<std::string> &);
bool compare(const std::list<std::string> &, const std::list<std::string> &);
void unRotate(std::list<std::string> & words);

#endif

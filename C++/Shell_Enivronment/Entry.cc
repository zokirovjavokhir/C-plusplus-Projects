#include "Entry.h"

Entry::~Entry() = default;
//overload << operator here
std::ostream& operator<<(std::ostream& os, const Entry& entry)
{
	entry.print(std::cout);
	return os;
}
#ifndef SDDS_STRINGSET_H
#define SDDS_STRINGSET_H

#include <string>

using namespace std;

namespace sdds {
	class StringSet
	{
	public:
		string *ss_strings;		// strings
		int ss_string_count;	// string counter

		StringSet();	// A no argument default constructor.
		~StringSet();
		StringSet(char* new_string);	// 1-argument constructor that receives the address of a c-style null terminated string containing the name of a file from which this member function populates the current object.
		

		size_t size();	// A query that returns the number of strings stored in the current object,
		string getEvent(int index); // A query that returns a copy of the string at the index received.
	};
}

#endif
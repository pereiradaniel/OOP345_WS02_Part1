#include "StringSet.h"

namespace sdds {

	StringSet::StringSet()
	{
		ss_strings = nullptr;
		ss_string_count = 0;
	}

	StringSet::~StringSet()
	{
		delete[] ss_strings;
		ss_strings = nullptr;
	}

	StringSet::StringSet(char *new_string)
	{
		string _b;
		ifstream file(new_string);
		int i = 0;
		while (!file.eof())
		{
			getline(file, _b, " ");
			++i;
		}
		ss_strings = new string[i + 1];
		_b = {};
		file.close();
		file.open(new_string);
		i = 0;
		while (getline(file, _b, " "))
		{
			ss_strings[i] = _b;
			++i;
		}
		ss_string_count = i;
	}

	StringSet::StringSet(const StringSet& input_string)
	{
		*this = input_string;
	}

	StringSet& StringSet::operator=(const StringSet& string)
	{
		ss_string_count = string.ss_string_count;
		ss_strings = new string[ss_string_count];
		for (int i = 0; i < ss_string_count; ++i)
		{
			ss_strings[i] = string.ss_strings[i];
		}
		return *this;
	}

	size_t StringSet::size()
	{
		return ss_string_count;
	}

	string StringSet::getEvent(int index)
	{
		if (ss_strings != nullptr)
		{
			return string(ss_strings[index]);
		}
		else
		{
			return "";
		}
	}

	StringSet::StringSet(StringSet &&input_string)
	{
		*this = move(input_string);
	}

	StringSet& StringSet::operator=(StringSet&& input_string)
	{
		if (this != &input_string)
		{
			ss_string_count = input_string.ss_string_count;
			ss_strings = new string[ss_string_count];
			for (int i = 0; i < ss_string_count; ++i)
			{
				ss_strings[i] = input_string.ss_strings[i];
			}
			delete[] input_string.ss_strings;
			input_string.ss_strings = nullptr;
			input_string.ss_string_count = 0;
		}
		return *this;
	}
}
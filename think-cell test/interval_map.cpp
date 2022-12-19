#include <iostream>
#include <limits>
#include <map>

template <typename K, typename V>

class interval_map
{
	friend void IntervalMapTest();
	V m_valBegin;
	std::map<K, V> m_map;

public:
	// constructor associates whole range of K with val
	interval_map(V const &val)
		: m_valBegin(val)
	{
	}

	// Assign value val to interval [keyBegin, keyEnd).
	// Overwrite previous values in this interval.
	// Conforming to the C++ Standard Library conventions, the interval
	// includes keyBegin, but excludes keyEnd.
	// If !( keyBegin < keyEnd ), this designates an empty interval,
	// and assign must do nothing.
	void assign(K const &keyBegin, K const &keyEnd, V const &val)
	{
		if (!(keyBegin < keyEnd))
			return;

		auto ptrEnd = m_map.upper_bound(keyEnd);
		if (!(operator[](keyEnd) == val))
		{
			m_map.insert(std::make_pair(keyEnd, operator[](keyEnd)));
			ptrEnd = m_map.find(keyEnd);
		}

		auto ptrBegin = m_map.lower_bound(keyBegin);
		K keyInsert = keyBegin;
		if (ptrBegin != m_map.begin() && std::prev(ptrBegin)->second == val)
		{
			ptrBegin = std::prev(ptrBegin);
			keyInsert = ptrBegin->first;
		}

		if (ptrBegin != m_map.end())
			m_map.erase(ptrBegin, ptrEnd);

		m_map.insert_or_assign(keyInsert, val);

		return;
	}

	// look-up of the value associated with key
	V const &operator[](K const &key) const
	{
		auto it = m_map.upper_bound(key);
		if (it == m_map.begin())
		{
			return m_valBegin;
		}
		else
		{
			return (--it)->second;
		}
	}

	// a function to print the content
	void print_map()
	{
		K min_val = std::numeric_limits<K>::min();
		if (m_map.find(min_val) == m_map.end())
			std::cout << min_val << " -> " << m_valBegin << std::endl;

		for (auto entry : m_map)
		{
			std::cout << entry.first << " -> " << entry.second << std::endl;
		}
	}
};

// Many solutions we receive are incorrect. Consider using a randomized test
// to discover the cases that your implementation does not handle correctly.
// We recommend to implement a test function that tests the functionality of
// the interval_map, for example using a map of int intervals to char.

int main(int argc, char *argv[])
{
	std::cout << "example test:" << std::endl;
	interval_map<int, char> M{'A'};
	M.assign(1, 3, 'B');
	M.print_map();
	std::cout << std::endl;

	std::cout << "<int, char> test:" << std::endl;
	interval_map<int, char> int_char_map{'$'};
	int_char_map.assign(3, 8, '!');
	int_char_map.assign(5, 10, '%');
	int_char_map.assign(100, 20, '?');
	int_char_map.print_map();
	std::cout << std::endl;

	std::cout << "<int, int> test:" << std::endl;
	interval_map<int, int> int_int_map{0};
	int_int_map.assign(3, 8, 1);
	int_int_map.assign(-2147483648, -100, 8);
	int_int_map.assign(1337, 110, 404);
	int_int_map.print_map();
	std::cout << std::endl;

	std::cout << "<char, int> test:" << std::endl;
	interval_map<char, int> char_int_map{0};
	char_int_map.assign('A', 'D', 1);
	char_int_map.assign('S', 'z', 5);
	char_int_map.assign('a', 'A', 10);
	char_int_map.print_map();
	std::cout << std::endl;

	return 0;
}

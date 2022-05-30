#include <iostream>
#include <string>

using namespace std;

struct tanggal
{
	int thn,bln,hr;
};

struct Range_error : out_of_range {	// enhanced vector range error reporting
	int index;
	Range_error(int i) :out_of_range("Range error: " +to_string(i)), index(i) { }
};

struct Exit : runtime_error {
	Exit() : runtime_error("Exit") {}
};

// error() simply disguises throws:
inline void error(const string& s)
{
	throw runtime_error(s);
};

void init_day(tanggal& dd, int y, int m, int d);
void add_day(int y, int m, int d);
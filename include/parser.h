#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

class Parser{

public:
	static std::vector<std::string> parse_csv_line(std::string line);
};

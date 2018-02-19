#include <unordered_map>
#include <string>

class Dataframe {
	std::unordered_map< std::string, std::vector<std::string> > data;	
	Dataframe(std::string filename);
	std::vector<std::string> getDataColumnNames();
};

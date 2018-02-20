#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <string>
#include "parser.h"

class Dataframe {
private:
	std::unordered_map< std::string, std::vector<std::string> > data;	

public:
	Dataframe(std::string filename);
	std::vector<std::string> columnNames();
	std::vector< std::pair<std::string, std::string> > rowAtIndex(int rowIndex);
	std::vector<std::string> getColumn(std::string columnName);
	std::vector<std::string> columnTypes();
	Dataframe transpose();
	void print();
};

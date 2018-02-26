#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <string>
#include "parser.h"

typedef std::unordered_map< std::string, std::vector<std::string> > Str2VecStrMap_t; 
 
class DataFrame {
private:
	String2VectorOfStringsMap_t data;	
	std::vector<std::string> header;
	int column_count, row_count;

public:
	DataFrame(std::string filename);
	std::vector<std::string> column_names();
	//FZ: avoid copying by using references
	//FZ: if you care preserving the original data: use const 
	std::vector< std::pair<std::string, std::string> > row_at_index(int row_index);
	std::vector<std::string> get_column(std::string column_name);
	std::vector<std::string> column_types();
    std::vector<std::string> operator[](std::string column_name);
    std::vector<std::string> operator[](int i);
    DataFrame transpose();
	void print();
};

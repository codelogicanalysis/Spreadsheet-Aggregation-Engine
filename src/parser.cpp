#include "parser.h"

std::vector<std::string> Parser::parse_csv_line(std::string line) {
	std::vector<std::string> result;
	std::stringstream lineStream(line);
	std::string cell;

	while(std::getline(lineStream,cell, ',')) {
		// Remove any whitespaces in values or column names, then delete extra character
		cell.erase(remove_if(cell.begin(), cell.end(), isspace), cell.end()); 
		result.push_back(cell);
	}
    	// This checks for a trailing comma with no data after it.
    	if (!lineStream && cell.empty()) {
        	// If there was a trailing comma then add an empty element.
        	result.push_back("");
	}
	return result;
}


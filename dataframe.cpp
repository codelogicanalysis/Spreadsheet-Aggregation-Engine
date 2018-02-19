#include "dataframe.h"

Dataframe::Dataframe(std::string filename) {

}

std::vector<std::string> Dataframe::columnNames() {
	std::vector<std::string> retVal;
	for(auto & element : data) {
		retVal.push_back(element.first);
	}
	return retVal;
}

std::vector< std::pair<std::string, std::string> > Dataframe::rowAtIndex(int rowIndex) {
	std::vector< std::pair<std::string, std::string> > retVal;
	for(auto & element : data) {
		retVal.push_back(std::make_pair(element.first, element.second[rowIndex]));
	}
	return retVal;
}

std::vector<std::string> Dataframe::getColumn(std::string columnName) {
	return data[columnName];
}



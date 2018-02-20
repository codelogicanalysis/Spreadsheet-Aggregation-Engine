#include "dataframe.h"

Dataframe::Dataframe(std::string filename) {
    std::ifstream file(filename);
    if (!file) throw std::runtime_error("File '"+filename+"' did not open successfully. Check the relative file path or file contents.");
    

    std::string line;
    std::getline(file, line);

    std::vector<std::string> header_line; //!< Vector of strings to store title row
    header_line = Parser::parse_csv_line(line);

    std::vector<std::vector<std::string>> columns; //!< Vector of all the columns in the spreadsheet

    // Initialize columns first order vector
    std::vector<std::string> temp_line; //!< Using this to initialize columns' high level vector
    std::getline(file, line);
    temp_line = Parser::parse_csv_line(line);

    for(int i = 0; i < header_line.size(); i++){
    	std::vector<std::string> temp_vector;
    	temp_vector.push_back(temp_line[i]);
    	columns.push_back(temp_vector);
    }

    while(std::getline(file,line)){

    	std::vector<std::string> current_line = Parser::parse_csv_line(line);
    	for(int i = 0; i < current_line.size(); i++){
    		columns[i].push_back(current_line[i]);
    		// std::cout<<current_line[1]<<std::endl;
    	}
    }

	for(int i = 0; i<header_line.size(); i++){
		data.emplace(header_line[i], columns[i]);
		// std::cout<<header_line[i];
		// std::cout<<columns[i][1]<<std::endl;

	}
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
	//NEED TO CHECK IF rowIndex is valid
    for(auto & element : data) {
		retVal.push_back(std::make_pair(element.first, element.second[rowIndex]));
	}
	return retVal;
}

std::vector<std::string> Dataframe::getColumn(std::string columnName) {
	return data[columnName];
}

void Dataframe::print(){
    std::vector<std::string> columns = columnNames();
    
    if(!columns.size()) std::cout<<"Dataframe is empty\n";
    
    std::cout<<columns[0];
    for(int i = 1; i < columns.size(); i++){
        std::cout<<',' <<columns[i];
    }
    std::cout<<std::endl;
    
    for(int i = 0; i < data[columns[0]].size(); i++){
        std::cout<<data[columns[0]][i];
        for(int j = 1; j < columns.size(); j++){
            std::cout<<',' <<data[columns[j]][i];
        }
        std::cout<<std::endl;
    }
}

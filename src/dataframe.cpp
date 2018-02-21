#include "dataframe.h"


DataFrame::DataFrame(std::string filename) {
	std::ifstream file(filename);
	if (!file) throw std::runtime_error("File '"+filename+"' did not open successfully. Check the relative file path or file contents.");
	
	std::string line;
	std::getline(file, line);

	std::vector<std::string> header_line; //!< Vector of strings to store title row
	header = header_line = Parser::parse_csv_line(line);

	for(size_t i = 0; i < header_line.size(); i++) {
		data[header_line[i]] = std::vector<std::string>();
	}

	while(std::getline(file, line)) {
		std::vector<std::string> current_line = Parser::parse_csv_line(line);
		for(size_t i = 0; i < current_line.size(); i++) {
			data[header_line[i]].push_back(current_line[i]);
		}
	}
	
	column_count = header_line.size();
	row_count = data[header_line[0]].size();
}

/**
 * @brief Returns column names in the current DataFrame
 * @return Vector of strings containing the column names
 */
std::vector<std::string> DataFrame::column_names() {
	return header;
}


/**
 * @brief      Returns row by index
 *
 * @param  row_index  The row index
 *
 * @return     Vector of pairs of strings
 */
std::vector< std::pair<std::string, std::string> > DataFrame::row_at_index(int row_index) {
	if(row_index >= row_count) { 
		//return empty vector
		return std::vector< std::pair<std::string, std::string> >();
	}	

	std::vector< std::pair<std::string, std::string> > ret_val;
	for(auto & element : data) {
		ret_val.push_back(std::make_pair(element.first, element.second[row_index]));
	}
	return ret_val;
}


std::vector<std::string> DataFrame::get_column(std::string column_name) {
	return data[column_name];
}

std::vector<std::string> DataFrame::operator[](std::string column_name) {
    return data[column_name];
}

std::vector<std::string> DataFrame::operator[](int i) {
    return data[header[i]];
}

void DataFrame::print() {
	std::vector<std::string> columns = column_names();
    	
	if(!column_count) std::cout << "DataFrame is empty\n";
    
	for(size_t i = 0; i < column_count; i++){	
		std::cout << columns[i] << " ,"[i != column_count - 1] << " \n"[i == column_count - 1];
		//Explanation of the above: " \n" is a char*, " \n"[0] is ' ' and " \n"[1] is '\n'
	}
    
	for(size_t row = 0; row < row_count; row++) {
		for(size_t col = 0; col < column_count; col++){
			std::cout << data[columns[col]][row] << " ,"[col != column_count - 1] << " \n"[col == column_count - 1];
		}
	}
}

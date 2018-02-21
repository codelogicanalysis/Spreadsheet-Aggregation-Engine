#include "dataframe.h"

int main(){

	DataFrame df("tests/test.csv");

    df.print();

    std::cout<<df[1][1] <<std::endl;
    std::cout<<df["Books"][0] <<std::endl;
	return 0;
}

#include "dataframe.h"

int main(){

	Dataframe df("tests/test.csv");

    df.print();

    std::cout<<df[1][1] <<std::endl;
    std::cout<<df["Books"][0] <<std::endl;
	return 0;
}

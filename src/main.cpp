#include "dataframe.h"

int main(){

	Dataframe df("../test.csv");

    df.print();

    std::cout<<df[1][1] <<std::endl;
    std::cout<<df["Books"][0] <<std::endl;
	return 0;
}

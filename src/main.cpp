#include <iostream>
#include "funcs.hpp"		 //include header that has matrix based functions
#include "matrix_struct.hpp" //include header that has matrix defenition
#include "commands.hpp"		 //include header that has commands related functions
#include <vector>
using namespace std;

int main()
{
	vector<matrixS> matrixV; //main container thar keeps matrixes
	menu(matrixV);			 //menu function that shows menu and calls other functions based on input

	return EXIT_SUCCESS; //end of program
}

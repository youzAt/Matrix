#ifndef MATRIX_STRUCT_HPP
#define MATRIX_STRUCT_HPP
#include <string>

struct matrixS //struct that keeps matrixes information
{
	std::string name = "";		   //name of string
	int size = 0;				   //the number of rows and columns of matrix if its square (0 otherwize)
	int row;					   // number of rows of matrix
	int col;					   // number of columns of matrix
	int data_type;				   // keeps the data type of matrix elements (1:number- 2:characters- 3:string)
	float **mat_n = nullptr;	   // pointer for numbers matrix
	char **mat_c = nullptr;		   //pointers for character matrix
	std::string **mat_s = nullptr; ///pointers for string matrix
};

#endif // MATRIX_STRUCT_HPP

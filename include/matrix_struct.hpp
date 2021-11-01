#ifndef MATRIX_STRUCT_HPP
#define MATRIX_STRUCT_HPP
#include<string>

struct matrixS
{
	std::string name = "";
	int size = 0;
	int row;
	int col;
	int data_type;
	float** mat_n = nullptr;
	char** mat_c = nullptr;
	std::string** mat_s = nullptr;
};


#endif // MATRIX_STRUCT_HPP

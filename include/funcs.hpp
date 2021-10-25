#ifndef FUNCS_HPP
#define FUNCS_HPP

//function that checks is a matrix is diagonal
template <typename T>
bool is_diagonal(T matrix, int size, int data_type = 1)
{
	bool diagonal = true;
	switch (data_type)
	{
		// numbers(special number : 0)
		case 1:
		{
			for (int i = 0; i < size && diagonal; i++)
			{
				for (int j = 0; j < size; j++)
				{
					if (i != j && matrix[i][j] != 0)
					{
						diagonal = false;
						break;
					}
				}
			}
		}
		break;
		// char(special char : o)
		case 2:
		{
			for (int i = 0; i < size && diagonal; i++)
			{
				for (int j = 0; j < size; j++)
				{
					if (i != j && matrix[i][j] != 'o')
					{
						diagonal = false;
						break;
					}
				}
			}
		}
		break;
		//string(special string: ooo)
		case 3:
		{
		}
		break;
	}
	return diagonal; //return the resault
}



#endif // FUNCS_HPP

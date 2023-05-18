

#include <iostream>
#include <clocale>
#include <cstdlib> 



template<typename Type>
Type Search_min_max(const Type* arr, int row, int column, int list) {
	Type min = arr[0][0][0];
	Type max = arr[0][0][0];
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			for (size_t f = 0; f < list ; f++)
			{
				if (arr[i][j][f] < min) min = arr[i][j][f];
				if (arr[i][j][f] > max) max = arr[i][j][f];
			}
			
		}
	}
	return min, max;
}

template<typename Type>
std::pair<Type, Type> Search_min_max(const Type* arr, int row, int column){
	Type min = arr[0][0];
	Type max = arr[0][0];
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			if (arr[i][j] < min) min = arr[i][j];
			if (arr[i][j] > max) max = arr[i][j];
		}
	}
	return std::make_pair(min, max);
}


template<typename Type>
Type Search_min_max(const Type* arr, int length){
	Type min = arr[0];
	Type max = arr[0];
	for  (int i = 0; i < length; i++)
	{
		if (max < arr[i]) {
			max = arr[i];
		}
		if (min > arr[i]) {
			 min = arr[i];
		}
	}
	
	return min, max;
}

template<typename Type>
void Print(const Type* arr, int length) {
	std::cout << '[';
	for (int i = 0; i < length; i++)
	{
		std::cout << *(arr + i);
		if (i != length - 1) {
			std::cout << ", ";
		}
	}
	std::cout << ']';
}


template<typename Type>
void Print(const Type* arr, int rows, int column) {
	std::cout << '[';
	for (int i = 0; i < rows; i++)
	{
		std::cout << '[';
		for (int j = 0; j < column; j++)
		{
			std::cout << *(arr + i * j + j);
			if (j != column - 1)
			{
				std::cout << ", ";
			}
		}
		std::cout << ']';
		if (i != rows - 1) {
			std::cout << ", ";
		}
	}
	std::cout << ']';
}
template<typename Type>
void Print(const Type* arr, int rows, int column, int list) {
	for (int k = 0; k < list; k++)
	{
		std::cout << '\n';
		std::cout << '[';
		std::cout << '\n';
		for (int i = 0; i < rows; i++)
		{
			std::cout << '[';
			for (int j = 0; j < column; j++)
			{
				std::cout << *(arr + i * j + j);
				if (j != column - 1)
				{
					std::cout << ", ";
					
				}
			}
			
			std::cout << ']';
			std::cout << '\n';
			
			if (i != rows - 1) {
				std::cout << ", ";
				std::cout << '\n';
			}
		}
		std::cout << ']';
		std::cout << '\n';
	}
	
}



void Fill(int* arr, int lenght) {
    for (int i = 0; i < lenght; i++)
    {
        *(arr + i) = ::rand() % 99 + 10;
    }
}
void Fill(double* arr, int lenght) {
	for (int i = 0; i < lenght; i++)
	{
		*(arr + i) = ::rand() % 99 + 10;
	}
}

void Fill(int* arr, int row, int clumn)
{
    ::srand(::time(NULL));
    for (int i = 0; i < row * clumn; i++)
    {
        *(arr + i) = ::rand() % 99 + 10;
    }
}

void Fill(int* arr, int row, int column, int list) {
	::srand(::time(NULL));
	for (int i = 0; i < row * column* list; i++)
	{
		*(arr + i) = ::rand() % 99 + 10;
	}
}


int main()
{
    int mass_1[5]{};
    int mass_2[3][3]{};
    int mass_3[3][3][3]{};

	Fill(mass_1, 5);
	Print(mass_1, 5);
	std::cout << '\n';
	Fill(&mass_2[0][0], 3, 3);
	Print(&mass_2[0][0], 3,3);
	std::cout << '\n';
	std::cout << '\n';
	Fill(&mass_3[0][0][0], 3, 3, 3);
	Print(&mass_3[0][0][0], 3, 3, 3);
	
	//Search_min_max(mass_1, 5);
	std::cout << Search_min_max(&mass_2[0][0], 3, 3);
}
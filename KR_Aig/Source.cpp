#include<iostream>
#include<vector>
#include<fstream>
#include<iomanip>
#include<Windows.h>
#include"queue.h"
#include"function.h"
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::ifstream file;
	file.open("text.txt", std::ios::in);
	queue* que = new queue;
	reading(que, file);
	int size = que->get_size();
	int** matrix, ** matrix_1;
	matrix = new int* [size];
	matrix_1 = new int* [size];
	for (int i = 0; i < size; i++) {
		matrix[i] = new int[size];
	}
	for (int i = 0; i < size; i++) {
		matrix_1[i] = new int[size];
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			matrix[i][j] = 0;
		}
	}
	file.clear();
	file.seekg(0);
	creating_matrix(que, file, matrix, size);
	file.close();
	Pushing_preflow(size, matrix, matrix_1);
	int flow = 0;
	for (int i = 0; i < size; i++)
		if (matrix[0][i])
			flow += matrix_1[0][i];
	cout << "Матрица смежности сети:\n";
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			std::cout << std::setw(3) << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
	cout << "Максимальный поток сети c истоком "<<que->at(0) <<" и стоком "<< que->at(que->get_size()-1)<<" : ";
	cout << max(flow, 0);

}
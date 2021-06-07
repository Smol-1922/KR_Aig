#include<iostream>
#include<fstream>
#include<string>
#include"queue.h"
void push(int u, int v, int** f, int* e, int** c)
{
	int d = std::min(e[u], c[u][v] - f[u][v]);
	f[u][v] += d;
	f[v][u] = -f[u][v];
	e[u] -= d;
	e[v] += d;
}

void lift(int u, int* h, int** f, int** c, int size)
{
	int d = 999999;
	for (int i = 0; i < size; i++)
		if (c[u][i] - f[u][i] > 0)
			d = std::min(d, h[i]);
	if (d == 999999)
		return;
	h[u] = d + 1;
}
void Pushing_preflow(int size,int**matrix,int** matrix_1) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			matrix_1[i][j] = 0;
		}
	}
	for (int i = 1; i < size; i++)
	{
		matrix_1[0][i] = matrix[0][i];
		matrix_1[i][0] = -matrix[0][i];
	}
	int* vect_1 = new int[size];
	vect_1[0] = size;
	int* vect_2 = new int[size];
	for (int i = 1; i < size; i++)
		vect_2[i] = matrix_1[0][i];

	for (; ; )
	{
		int i;
		for (i = 1; i < size - 1; i++)
			if (vect_2[i] > 0)
				break;
		if (i == size - 1)
			break;

		int j;
		for (j = 0; j < size; j++)
			if (matrix[i][j] - matrix_1[i][j] > 0 && vect_1[i] == vect_1[j] + 1)
				break;
		if (j < size)
			push(i, j, matrix_1, vect_2, matrix);
		else
			lift(i, vect_1, matrix_1, matrix, size);
	}
}
void reading(queue* que, std::ifstream& text) {
	std::string str, graf;
	int count = 0;
	bool flag = true;
	while (!text.eof()) {
		std::getline(text, str);
		for (unsigned int i = 0; i < str.size(); i++) {
			if (count == 2) {
				break;
			}
			if (str[i] != ' ')
			{
				graf += str[i];			
				if (str[i + 1] != ' ')
					throw "incorrect input";
			}
			else if (count != 2) {
				for (int j = 0; j < que->get_size(); j++) {
					if (graf == que->at(j)) {
						flag = false;
					}
				}
				if (flag) {
					que->push(graf);
				}
				flag = true;
				count++;
				graf.clear();
			}
			else {
				graf.clear();
				break;
			}
		}
		graf.clear();
		count = 0;
	}
	str.clear();
	graf.clear();
}
void creating_matrix(queue* que, std::ifstream& text, int** matrix, int N) {
	std::string str, word;
	int count = 0;
	int unit_1 = 0, unit_2 = 0;
	while (!text.eof()) {
		std::getline(text, str);
		for (unsigned int i = 0; i < str.size() + 1; i++) {
			if (str[i] != ' ' && i < str.size())
			{
				word += str[i];
			}
			else if (count < 2) {
				if (count == 1) {
					if(str[i+1]!='0'&& str[i + 1] != '1'&& str[i + 1] != '2'&& str[i + 1] != '3'&& str[i + 1] != '4'&& str[i + 1] != '5'&& str[i + 1] != '6'&& str[i + 1] != '7'& str[i + 1] != '8'&& str[i + 1] != '9')
						throw "incorrect input";
				}
				for (int j = 0; j < que->get_size(); j++) {
					if (word == que->at(j)) {
						if (count == 0)
							unit_1 = j;
						else
							unit_2 = j;
						break;
					}
				}
				count++;
				word.clear();
			}
			else {
				if (count == 2) {
						matrix[unit_1][unit_2] = atoi(word.c_str());
				}
				count++;
				word.clear();
			}
		}
		count = 0;
		word.clear();
	}
	str.clear();
	word.clear();
}
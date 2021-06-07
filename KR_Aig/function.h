#include"queue.h"
void push(int u, int v, int** f, int* e, int** c);
void lift(int u, int* h, int** f, int** c, int size);
void reading(queue* que, std::ifstream& text);
void creating_matrix(queue* que, std::ifstream& text, int** matrix, int N);
void Pushing_preflow(int size, int** matrix, int** matrix_1);
#include <iostream>

using namespace std;

bool check_command(string command);

void help();



int **create_matrix_int(int rows, int columns);

bool fill_matrix(int **matrix, int rows, int columns);

void print_matrix(int **matrix, int rows, int columns);

int **addMatrix(int **matrix_a, int **matrix_b, int rows_a, int columns_a);

int **subtractMatrix(int **matrix_a, int **matrix_b, int rows_a, int columns_a);

int **multiplyMatrix(int **matrix_a, int **matrix_b, int rows_a, int columns_a, int columns_b);

int **multiplyByScalar(int **matrix, int rows, int columns, int scalar);

int **transpozeMatrix(int **matrix, int rows, int columns);

int **powerMatrix(int **matrix, int rows, int columns, int m_power);

int **submatrix(int **matrix, int row_index, int column_index, int matrix_size);

int determinantMatrix(int **matrix, int rows, int columns);

bool matrixIsDiagonal(int **matrix, int rows, int columns);

void swap(int *a, int *b);

void sortRow(int *row, int columns);

void sortRowsInMatrix(int **matrix, int rows, int columns);

void delete_matrix(int **matrix, int rows);



double **create_matrix_double(int rows, int columns);

bool fill_matrix(double **matrix, int rows, int columns);

void print_matrix(double **matrix, int rows, int columns);

double **addMatrix(double **matrix_a, double **matrix_b, int rows_a, int columns_a);

double **subtractMatrix(double **matrix_a, double **matrix_b, int rows_a, int columns_a);

double **multiplyMatrix(double **matrix_a, double **matrix_b, int rows_a, int columns_a, int columns_b);

double **multiplyByScalar(double **matrix, int rows, int columns, double scalar);

double **transpozeMatrix(double **matrix, int rows, int columns);

double **powerMatrix(double **matrix, int rows, int columns, double m_power);

double **submatrix(double **matrix, int row_index, int column_index, int matrix_size);

double determinantMatrix(double **matrix, int rows, int columns);

bool matrixIsDiagonal(double **matrix, int rows, int columns);

void swap(double *a, double *b);

void sortRow(double *row, int columns);

void sortRowsInMatrix(double **matrix, int rows, int columns);

void delete_matrix(double **matrix, int rows);
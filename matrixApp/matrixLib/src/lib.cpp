#include "../include/lib.h"

//funkcja sprawdza czy podana przez uzytkownika komenda jest obslugiwana
bool command_check(string operator){

    //tablica z dostepnymi operacjami
    string commands_list[9] = {"addMatrix", "subtractMatrix", "multiplyMatrix", "multiplyByScalar",
                              "transpozeMatrix", "powerMatrix", "determinantMatrix",
                              "matrixIsDiagonal", "sortRowsInMatrix"};

    //sprawdza czy podana komenda wystepuje w tablicy
    for (int i = 0; i < 9; ++i)
    {
        if (operator == commands_list[i])
            return true;
    }

    return false;
}

void help(){

    cout << "Program wykonuje operacje na macierzach, by wykonac operacje nalezy wpisac nastepujace komendy: \n
    addMatrix - dodawanie dwóch macierzy \n
    subtractMatrix - odejmowanie dwóch macierzy \n
    multiplyMatrix - mnożenie dwóch macierzy \n
    multiplyByScalar - mnożenie przez skalar \n
    transpozeMatrix - transponowanie macierzy \n
    powerMatrix - potęgowanie macierzy, jako drugi parametr przyjmuje wartość potęgi \n
    determinantMatrix - wyznacznik macierzy \n
    matrixIsDiagonal - - sprawdzanie, czy macierz jest diagonalna \n
    swap - zamiana dwóch wartości miejscami \n
    sortRow - sortowanie tablicy za pomocą sortowania bombelkowego \n
    sortRowsInMatrix - sortowanie wszystkich wierszy w macierzy" << endl;

    cout << "Po wybraniu komendy, wybierz typ zmiennych wpisywanych w komorki macierzy, [int] lub [double]" << endl;

    cout << "Nastepnie wpisz liczby do komorek" << endl;
}

/* funkcje int */

int **create_matrix_int(int rows, int columns){

    /*wiersze*/
    int **tmp_matrix = new int *[rows];

    /* kolumny */
    for (int i = 0; i < rows; i++)
    {
        tmp_matrix[i] = new int[columns];
        for (int j = 0; j < columns; ++j)
        {
            /* wyzerowanie komorek */
            tmp_matrix[i][j] = 0;
        }
    }
    return tmp_matrix;
}

/* przypisanie wartosci */
bool fill_matrix(int **matrix, int rows, int columns){

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            cout << "Liczba do komorki " << i + 1 << " " << j + 1 << endl;
            if (!(cin >> matrix[i][j]))
            {
                cout << "nieprawidlowy znak" << endl;
                return false;
            }
        }
    }
    return true;
}

/* wypisanie macierzy */
void print_matrix(int **matrix, int rows, int columns){

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            cout << " " << matrix[i][j] << " ";
        }
        cout << "\n";
    }
}

/* dodawanie macierzy: do komorek macierzy wynikowej wstawiana jest wartosc dodania macierzy a i b*/
int **addMatrix(int **matrix_a, int **matrix_b, int rows_a, int columns_a){

    int **wynik = nullptr;

    wynik = create_matrix_int(rows_a, columns_a);

    for (int i = 0; i < rows_a; ++i)
    {
        for (int j = 0; j < columns_a; ++j)
        {
            wynik[i][j] = matrix_a[i][j] + matrix_b[i][j];
        }
    }
    return wynik;
}

/* odejmowanie macierzy: do komorek macierzy wynikowej wstawiana jest wartosc dodania macierzy a i b*/
int **subtractMatrix(int **matrix_a, int **matrix_b, int rows_a, int columns_a){

    int **wynik = nullptr;

    wynik = create_matrix_int(rows_a, columns_a);

    for (int i = 0; i < rows_a; ++i)
    {
        for (int j = 0; j < columns_a; ++j)
        {
            wynik[i][j] = matrix_a[i][j] - matrix_b[i][j];
        }
    }
    return wynik;
}

/* mnozenie macierzy: do komorek macierzy wynikowej wstawiana jest wartosc mnozenia macierzy a i b*/
int **multiplyMatrix(int **matrix_a, int **matrix_b, int rows_a, int columns_a, int columns_b){

    int **wynik = nullptr;

    wynik = create_matrix_int(rows_a, columns_b);

    for (int i = 0; i < rows_a; ++i)
    {
        for (int j = 0; j < columns_b; ++j)
        {
            for (int k = 0; k < columns_a; ++k)
            {
                wynik[i][j] += matrix_a[i][k] * matrix_b[k][j];
            }
        }
    }
    return wynik;
}

/* mnozenie macierzy przez skalar: do komorek macierzy wynikowej wstawiana jest wartosc mnozenia macierzy a przez skalar*/
int **multiplyByScalar(int **matrix_a, int rows_a, int columns_a, int scalar){

    int **wynik = nullptr;

    wynik = create_matrix_int(rows_a, columns_a);

    for (int i = 0; i < rows_a; ++i)
    {
        for (int j = 0; j < columns_a; ++j)
        {
            wynik[i][j] = matrix_a[i][j] * scalar;
        }
    }
    return wynik;
}

/* transpozycja */
int **transpozeMatrix(int **matrix, int rows, int columns)
{
    
    int **wynik = nullptr;

   /* maciezr pomocnicza np 2x3 -> 3x2 */
    wynik = create_matrix_int(columns, rows);

    /* kopiuje wartosc z podanego macierza do wyniku*/
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            wynik[j][i] = matrix[i][j];
        }
    }
    return wynik;
}

/* potegowanie */
int **powerMatrix(int **matrix, int rows, int columns, int m_power){

    /* przypadek potegi 1 == zwaraca macierz */
    if (m_power == 1)
        return matrix;
    else if (m_power == 0)
    {
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < columns; ++j)
            {
                if (i == j)
                    matrix[i][j] = 1;
                else
                    matrix[i][j] = 0;
            }
        }
    return matrix;
    }
    else
        return multiplyMatrix(matrix, powerMatrix(matrix, rows, columns, m_power - 1), rows, columns, columns);
}

/* tworzy pomocniczy macierz 'wykreslajac' odpowiedne wierzsze i kolumny */
int **submatrix(int **matrix, int row_index, int column_index, int matrix_size){

    int i = 0, j = 0;

    int **wynik = nullptr;

    wynik = create_matrix_int(matrix_size, matrix_size);

    for (int r = 0; r < matrix_size; ++r)
    {
        for (int c = 0; c < matrix_size; ++c)
        {
            /* pomijanie wierzy i kolumn podanych w komendzie */
            if (r != row_index && c != column_index)
            {
                wynik[i][j++] = matrix[r][c];

                /* zerowanie wartosci i przejscie do koljenego wiersza */
                if (j == matrix_size - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
    return wynik;
}

int determinantMatrix(int **matrix, int rows, int columns){

    /* macierz 1x1 */
    if (rows == 1)
        return matrix[0][0];
    /* macierz 2x2 */
    else if (rows == 2)
        return (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
    else
    {
        int result = 0, sign = 1;

        int **temp_matrix = nullptr;

        for (int i = 0; i < rows; ++i)
        {
            /*podmacierz pomniejszona o odpowiedni wiersz i kolumne */
            temp_matrix = submatrix(matrix, 0, i, rows);

            result += sign * matrix[0][i] * determinantMatrix(temp_matrix, rows - 1, columns - 1);

            /* zmiana znaku */
            sign = -sign;
        }
        return result;
    }
}

/* czy maciezr jest diagonalna */
bool matrixIsDiagonal(int **matrix, int rows, int columns){

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            if (i != j && matrix[i][j] != 0)
            {
                return false;
            }
        }
    }

    return true;
}

/* zamaina dwoch wartosci */
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/* bubble sort od 0 do konca */
void sortRow(int *row, int columns){
    
    int i, j;
    for (i = 0; i < columns - 1; i++)
        for (j = 0; j < columns - i - 1; j++)
            if (row[j] > row[j + 1])
                swap(&row[j], &row[j + 1]);
}

/* sortowanie w kolejnych wierszach */
void sortRowsInMatrix(int **matrix, int rows, int columns){
    
    for (int i = 0; i < rows; i++)
    {
        sortRow(matrix[i], columns);
    }
}

/* usuwanie macierzy */
void delete_matrix(int **matrix, int rows){
    
    for (int i = 0; i < rows; ++i)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

//double
/* przeciazenie funkcji dla double */

double **create_matrix_double(int rows, int columns){

    double **tmp_matrix = new double *[columns];

    for (int i = 0; i < rows; i++)
    {
        tmp_matrix[i] = new double[columns];

        for (int j = 0; j < rows; ++j)
        {
            tmp_matrix[i][j] = 0;
        }
    }
    return tmp_matrix;
}

bool fill_matrix(double **matrix, int rows, int columns){

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            cout << "Liczba do komorki " << i + 1 << " " << j + 1 << endl;
            if (!(cin >> matrix[i][j]))
            {
                cout << "nieprawidlowy znak" << endl;
                return false;
            }
        }
    }
    return true;
}

void print_matrix(double **matrix, int rows, int columns){

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            cout << " " << matrix[i][j] << " ";
        }
        cout << "\n";
    }
}

double **addMatrix(double **matrix_a, double **matrix_b, int rows_a, int columns_a){

    double **wynik = nullptr;

    wynik = create_matrix_double(rows_a, columns_a);

    for (int i = 0; i < rows_a; ++i)
    {
        for (int j = 0; j < columns_a; ++j)
        {
            wynik[i][j] = matrix_a[i][j] + matrix_b[i][j];
        }
    }
    return wynik;
}

double **subtractMatrix(double **matrix_a, double **matrix_b, int rows_a, int columns_a){

    double **wynik = nullptr;

    wynik = create_matrix_double(rows_a, columns_a);

    for (int i = 0; i < rows_a; ++i)
    {
        for (int j = 0; j < columns_a; ++j)
        {
            wynik[i][j] = matrix_a[i][j] - matrix_b[i][j];
        }
    }
    return wynik;
}

double **multiplyMatrix(double **matrix_a, double **matrix_b, int rows_a, int columns_a, int columns_b){

    double **wynik = nullptr;

    wynik = create_matrix_double(rows_a, columns_b);

    for (int i = 0; i < rows_a; ++i)
    {
        for (int j = 0; j < columns_b; ++j)
        {
            for (int k = 0; k < columns_a; ++k)
            {
                wynik[i][j] += matrix_a[i][k] * matrix_b[k][j];

            }
        }
    }
    return wynik;
}

double **multiplyByScalar(double **matrix, int rows, int columns, double scalar){

    double **wynik = nullptr;

    wynik = create_matrix_double(rows, columns);

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            wynik[i][j] = matrix[i][j] * scalar;
        }
    }
    return wynik;
}

double **transpozeMatrix(double **matrix, int rows, int columns){

    double **wynik = nullptr;

    wynik = create_matrix_double(columns, rows);

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            wynik[j][i] = matrix[i][j];
        }
    }
    return wynik;
}

double **powerMatrix(double **matrix, int rows, int columns, double m_power){

    if (m_power == 1)
        return matrix;
    else if (m_power == 0)
    {
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < columns; ++j)
            {
                if (i == j)
                    matrix[i][j] = 1;
                else
                    matrix[i][j] = 0;
            }
        }

        return matrix;
    }
    else
        return multiplyMatrix(matrix, powerMatrix(matrix, rows, columns, m_power - 1), rows, columns, columns);
}

double **submatrix(double **matrix, int row_index, int column_index, int matrix_size){

    int i = 0, j = 0;

    double **wynik = nullptr;

    wynik = create_matrix_double(matrix_size, matrix_size);

    for (int r = 0; r < matrix_size; ++r)
    {
        for (int c = 0; c < matrix_size; ++c)
        {
            if (r != row_index && c != column_index)
            {
                wynik[i][j++] = matrix[r][c];

                if (j == matrix_size - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
    return wynik;
}

double determinantMatrix(double **matrix, int rows, int columns){

    if (rows == 1)
        return matrix[0][0];
    else if (rows == 2)
        return (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
    else
    {
        double result = 0, sign = 1;

        double **temp_matrix = nullptr;

        for (int i = 0; i < rows; ++i)
        {
            temp_matrix = submatrix(matrix, 0, i, rows);

            result += sign * matrix[0][i] * determinantMatrix(temp_matrix, rows - 1, columns - 1);

            sign = -sign;
        }
        return result;
    }
}

bool matrixIsDiagonal(double **matrix, int rows, int columns){

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            if (i != j && matrix[i][j] != 0)
            {
                return false;
            }
        }
    }
    return true;
}

void swap(double *a, double *b){

    double tmp = *a;
    *a = *b;
    *b = tmp;
}

void sortRow(double *row, int columns){

    int i, j;
    for (i = 0; i < columns - 1; i++)
        for (j = 0; j < columns - i - 1; j++)
            if (row[j] > row[j + 1])
                swap(&row[j], &row[j + 1]);
}

void sortRowsInMatrix(double **matrix, int rows, int columns){

    for (int i = 0; i < rows; i++)
    {
        sortRow(matrix[i], columns);
    }
}

void delete_matrix(double **matrix, int rows){

    for (int i = 0; i < rows; ++i)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}
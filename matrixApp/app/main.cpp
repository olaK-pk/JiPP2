#include <iostream>
#include <string>
#include "../matrixLib/include/lib.h"

int main(int argc, char *argv[]){

    string operacja = "help";
    /* przypoisanie operacji do wykonania*/
    operacja = argv[1];    

    if (operacja == "help"){

        help();
    }
    /* czy komenda jest prawidlowa */
    else if (command_check(operacja)){

        /* liczba kolumn, wierszy i rodzaj danych*/
        int rows_a = 1, columns_a = 1, zmienne = 0;

        int **int_matrix_a = nullptr;
        double **double_matrix_a = nullptr;

        cout << "Zmienne typu int -> 0 czy double -> 1:" << endl;
        if (!(cin >> zmienne)){

            cout << "Wprowadzono nieprawidlowy znak" << endl;
            return 0;
        }

        /* wprowadzenie danych dla pierwszego macierza */
        cout << "Podaj liczbe wierszy i kolumn macierzy" << endl;
        if (!(cin >> rows_a)){

            cout << "Wprowadzono nieprawidlowy znak" << endl;
            return 0;
        }
        else if (!(cin >> columns_a)){

            cout << "Wprowadzono nieprawidlowy znak" << endl;
            return 0;
        }

        /* alokacja int */
        if (zmienne == 0){

            int_matrix_a = create_matrix_int(rows_a, columns_a);
            if (!fill_matrix(int_matrix_a, rows_a, columns_a))
            {
                delete_matrix(int_matrix_a, rows_a);
                return 0;
                /* w razie bledu, usuwa macierz i konczy program */
            }
        }
        
        /* alokacja double */
        else if (zmienne == 1){

            double_matrix_a = create_matrix_double(rows_a, columns_a);
            if (!fill_matrix(double_matrix_a, rows_a, columns_a))
            {
                delete_matrix(double_matrix_a, rows_a);
                return 0;
            }
        }
        else{

            cout << "zly wybor" << endl;
            return 0;
        }

        /* operacje */
        if (operacja == "addMatrix"){

            if (zmienne == 0)
            {
                int rows_b = 1, columns_b = 1;

                int **int_matrix_b = nullptr, **wynik = nullptr;

                cout << "Podaj liczbe wierszy i kolumn drugiej macierzy" << endl;
                if (!(cin >> rows_b)){

                    cout << "Wprowadzono nieprawidlowy znak" << endl;
                    delete_matrix(int_matrix_a, rows_a);
                    return 0;
                }

                if (!(cin >> columns_b)){

                    cout << "Wprowadzono nieprawidlowy znak" << endl;
                    delete_matrix(int_matrix_a, rows_a);
                    return 0;
                }
                
                int_matrix_b = create_matrix_int(rows_b, columns_b);
                if (!fill_matrix(int_matrix_b, rows_b, columns_b)){
                
                    /* wyjscie przy bledzie */
                    delete_matrix(int_matrix_a, rows_a);
                    delete_matrix(int_matrix_b, rows_b);
                    return 0;
                }

                wynik = addMatrix(int_matrix_a, int_matrix_b, rows_a, columns_a);

                cout << "Wynik to:" << endl;
                print_matrix(wynik, rows_a, columns_a);

                /* czyszczenie pamieci */
                delete_matrix(int_matrix_b, rows_b);
                delete_matrix(wynik, rows_b);
            }
            else if (zmienne == 1){
            
                int rows_b = 1, columns_b = 1;

                double **double_matrix_b = nullptr, **wynik = nullptr;

                cout << "Podaj liczbe wierszy i kolumn 2 macierzy" << endl;

                if (!(cin >> rows_b)){
                
                    cout << "nieprawidlowy znak" << endl;
                    delete_matrix(double_matrix_a, rows_a);
                    return 0;
                }

                if (!(cin >> columns_b)){
                
                    cout << "nieprawidlowy znak" << endl;
                    delete_matrix(double_matrix_a, rows_a);
                    return 0;
                }

                double_matrix_b = create_matrix_double(rows_b, columns_b);
                if (!fill_matrix(double_matrix_b, rows_b, columns_b)){
                
                    delete_matrix(double_matrix_a, rows_a);
                    delete_matrix(double_matrix_b, rows_b);
                    return 0;
                }

                wynik = addMatrix(double_matrix_a, double_matrix_b, rows_a, columns_a);

                cout << "Wynik to:" << endl;
                print_matrix(wynik, rows_a, columns_a);

                delete_matrix(double_matrix_b, rows_b);
                delete_matrix(wynik, rows_b);
            }
        }
        else if (operacja == "subtractMatrix")
        {
            if (zmienne == 0){
            
                int rows_b = 1, columns_b = 1;

                int **int_matrix_b = nullptr, **wynik = nullptr;

                cout << "Podaj liczbe wierszy i kolumn 2 macierzy" << endl;
                if (!(cin >> rows_b)){
                
                    cout << "nieprawidlowy znak" << endl;
                    delete_matrix(int_matrix_a, rows_a);
                    return 0;
                }

                if (!(cin >> columns_b)){
                
                    cout << "nieprawidlowy znak" << endl;
                    delete_matrix(int_matrix_a, rows_a);
                    return 0;
                }

                int_matrix_b = create_matrix_int(rows_b, columns_b);
                if (!fill_matrix(int_matrix_b, rows_b, columns_b)){
                
                    delete_matrix(int_matrix_a, rows_a);
                    delete_matrix(int_matrix_b, rows_b);
                    return 0;
                }

                wynik = subtractMatrix(int_matrix_a, int_matrix_b, rows_a, columns_a);

                cout << "Wynik to:" << endl;
                print_matrix(wynik, rows_a, columns_a);

                delete_matrix(int_matrix_b, rows_b);
                delete_matrix(wynik, rows_b);
            }
            else if (zmienne == 1){
            
                int rows_b = 1, columns_b = 1;

                double **double_matrix_b = nullptr, **wynik = nullptr;

                cout << "Podaj liczbe wierszy i kolumn 2 macierzy" << endl;
                if (!(cin >> rows_b)){
                
                    cout << "nieprawidlowy znak" << endl;
                    delete_matrix(double_matrix_a, rows_a);
                    return 0;
                }

                if (!(cin >> columns_b)){
                
                    cout << "nieprawidlowy znak" << endl;
                    delete_matrix(double_matrix_a, rows_a);
                    return 0;
                }

                double_matrix_b = create_matrix_double(rows_b, columns_b);
                if (!fill_matrix(double_matrix_b, rows_b, columns_b)){
                
                    delete_matrix(double_matrix_a, rows_a);
                    delete_matrix(double_matrix_b, rows_b);
                    return 0;
                }

                wynik = subtractMatrix(double_matrix_a, double_matrix_b, rows_a, columns_a);

                cout << "Wynik to:" << endl;
                print_matrix(wynik, rows_a, columns_a);

                delete_matrix(double_matrix_b, rows_b);
                delete_matrix(wynik, rows_b);
            }
        }
        else if (operacja == "multiplyMatrix")
        {
            if (zmienne == 0){
            
                int rows_b = 1, columns_b = 1;

                int **int_matrix_b = nullptr, **wynik = nullptr;

                cout << "Podaj liczbe wierszy i kolumn 2 macierzy" << endl;
                if (!(cin >> rows_b)){
                
                    cout << "nieprawidlowy znak" << endl;
                    delete_matrix(int_matrix_a, rows_a);
                    return 0;
                }

                if (!(cin >> columns_b)){
                
                    cout << "nieprawidlowy znak" << endl;
                    delete_matrix(int_matrix_a, rows_a);
                    return 0;
                }

                int_matrix_b = create_matrix_int(rows_b, columns_b);

                if (!fill_matrix(int_matrix_b, rows_b, columns_b)){
                
                    delete_matrix(int_matrix_a, rows_a);
                    delete_matrix(int_matrix_b, rows_b);
                    return 0;
                }

                wynik = multiplyMatrix(int_matrix_a, int_matrix_b, rows_a, columns_a, columns_b);

                cout << "Wynik to:" << endl;
                print_matrix(wynik, rows_a, columns_b);

                delete_matrix(int_matrix_b, rows_b);
                delete_matrix(wynik, rows_b);
            }
            else if (zmienne == 1){
            
                int rows_b = 1, columns_b = 1;

                double **double_matrix_b = nullptr, **wynik = nullptr;

                cout << "Podaj liczbe wierszy i kolumn 2 macierzy" << endl;
                if (!(cin >> rows_b)){
                
                    cout << "nieprawidlowy znak" << endl;
                    delete_matrix(double_matrix_a, rows_a);
                    return 0;
                }

                if (!(cin >> columns_b)){
                
                    cout << "nieprawidlowy znak" << endl;
                    delete_matrix(double_matrix_a, rows_a);
                    return 0;
                }

                double_matrix_b = create_matrix_double(rows_b, columns_b);
                if (!fill_matrix(double_matrix_b, rows_b, columns_b)){
                
                    delete_matrix(double_matrix_a, rows_a);
                    delete_matrix(double_matrix_b, rows_b);
                    return 0;
                }

                wynik = multiplyMatrix(double_matrix_a, double_matrix_b, rows_a, columns_a, columns_b);

                cout << "Wynik to:" << endl;
                print_matrix(wynik, rows_a, columns_b);

                delete_matrix(double_matrix_b, rows_b);
                delete_matrix(wynik, rows_b);
            }
        }
        else if (operacja == "multiplyByScalar"){
        
            if (zmienne == 0){
            
                int scalar;

                int **wynik = nullptr;

                cout << "Podaj skalar" << endl;
                if (!(cin >> scalar)){
                
                    cout << "nieprawidlowy znak" << endl;
                    delete_matrix(int_matrix_a, rows_a);
                    return 0;
                }

                wynik = multiplyByScalar(int_matrix_a, rows_a, columns_a, scalar);

                cout << "Wynik to:" << endl;
                print_matrix(wynik, rows_a, columns_a);

                delete_matrix(wynik, columns_a);
            }
            else if (zmienne == 1){
            
                double scalar;

                double **wynik = nullptr;

                cout << "Podaj skalar" << endl;
                if (!(cin >> scalar)){
                
                    cout << "nieprawidlowy znak" << endl;
                    delete_matrix(double_matrix_a, rows_a);
                    return 0;
                }

                wynik = multiplyByScalar(double_matrix_a, rows_a, columns_a, scalar);

                cout << "Wynik to:" << endl;
                print_matrix(wynik, rows_a, columns_a);

                delete_matrix(wynik, columns_a);
            }
        }
        else if (operacja == "transpozeMatrix"){
        
            if (zmienne == 0){
            
                int **wynik = nullptr;

                cout << "macierz podana:" << endl;
                print_matrix(int_matrix_a, rows_a, columns_a);

                wynik = transpozeMatrix(int_matrix_a, rows_a, columns_a);

                cout << "Wynik to:" << endl;
                print_matrix(wynik, columns_a, rows_a);

                delete_matrix(wynik, rows_a);
            }
            else if (zmienne == 1){
            
                double **wynik = nullptr;

                cout << "macierz podana:" << endl;
                print_matrix(double_matrix_a, rows_a, columns_a);

                wynik = transpozeMatrix(double_matrix_a, rows_a, columns_a);

                cout << "Wynik to:" << endl;
                print_matrix(wynik, columns_a, rows_a);

                delete_matrix(wynik, rows_a);
            }
        }
        else if (operacja == "powerMatrix"){
        
            if (zmienne == 0){
            
                int power;

                int **wynik = nullptr;

                cout << "Podaj potege" << endl;
                if (!(cin >> power)){
                
                    cout << "nieprawidlowy znak" << endl;
                    delete_matrix(int_matrix_a, rows_a);
                    return 0;
                }

                wynik = powerMatrix(int_matrix_a, rows_a, columns_a, power);

                cout << "Wynik to:" << endl;
                print_matrix(wynik, rows_a, columns_a);

                delete_matrix(wynik, rows_a);
            }
            else if (zmienne == 1){
            
                double power;

                double **wynik = nullptr;

                cout << "Podaj potege" << endl;
                if (!(cin >> power)){
                
                    cout << "nieprawidlowy znak" << endl;
                    delete_matrix(int_matrix_a, rows_a);
                    return 0;
                }


                wynik = powerMatrix(double_matrix_a, rows_a, columns_a, power);

                cout << "Wynik to:" << endl;
                print_matrix(wynik, rows_a, columns_a);

                delete_matrix(wynik, rows_a);
            }
        }
        else if (operacja == "determinantMatrix"){
        
            if (zmienne == 0){
            
                int result = 0;

                result = determinantMatrix(int_matrix_a, rows_a, columns_a);

                cout << "Wynik to:" << result << endl;

            }
            else if (zmienne == 1){
            
                double result = 0;

                result = determinantMatrix(double_matrix_a, rows_a, columns_a);

                cout << "Wynik to:" << result << endl;
            }
        }
        else if (operacja == "matrixIsDiagonal") {
       
            if (zmienne == 0){
            
                bool result = false;

                result = matrixIsDiagonal(int_matrix_a, rows_a, columns_a);

                if (result)
                    cout << "Podana maciez jest diagonalna" << endl;
                else
                    cout << "Podana maciez nie jest diagonalna" << endl;

            }
            else if (zmienne == 1){
            
                bool result = false;

                result = matrixIsDiagonal(double_matrix_a, rows_a, columns_a);

                if (result)
                    cout << "Podana maciez jest diagonalna" << endl;
                else
                    cout << "Podana maciez nie jest diagonalna" << endl;
            }
        }
        else if (operacja == "sortRowsInMatrix"){
        
            if (zmienne == 0){
            
                sortRowsInMatrix(int_matrix_a, rows_a, columns_a);

                cout << "Wynik to:" << endl;
                print_matrix(int_matrix_a, rows_a, columns_a);
            }
            else if (zmienne == 1){
            
                sortRowsInMatrix(double_matrix_a, rows_a, columns_a);

                cout << "Wynik to:" << endl;
                print_matrix(double_matrix_a, rows_a, columns_a);
            }
        }
        else{
        
            cout << "error" << endl;
        }

        /* czyszczenie pamieci */
        if (zmienne == 0){
            delete_matrix(int_matrix_a, rows_a);
        }
        else if (zmienne == 1){
            delete_matrix(double_matrix_a, rows_a);
        }

    }
    else{
    
        cout << "bledna komenda" << endl;
        help();
    }


    return 0;
}
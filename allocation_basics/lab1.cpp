#include <iostream>

using namespace std;

int main(char argc, int *argv[]) {
    switch (argc)
    {
    case add:
        int sum;
        sum = argv[0] + argv[1];
        cout << sum;
        break;
    case subtract:
        int sum;
        sum = argv[0] - argv[1];
        cout << sum;
        break;
    case volume:
        float sum;
        sum = ((argv[0] + argv[1])*argv[2])/2*argv[3];
        cout << sum;
        break;
    case help:
        printf("Działania:
            add [a] [b]
        Dodawanie dwóch liczb ([a] i [b]) całkowitych.
            subtract [a] [b]
        Odejmowanie dwóch liczb ([a] i [b]) całkowitych.
            volume [a] [b] [h] [H]
        Obliczanie objętości graniastosłupa prostego o podstawie trapezu [podstawy a,b i wysokość h]
            help
        wyświetlanie dokumentacji");
        break;    
    default:
        printf("Wystapil blad w komendzie. Sprawdz dokumentacje dla poprawngeo zapisu:\n");
        printf("Działania:
            add [a] [b]
        Dodawanie dwóch liczb ([a] i [b]) całkowitych.
            subtract [a] [b]
        Odejmowanie dwóch liczb ([a] i [b]) całkowitych.
            volume [a] [b] [h] [H]
        Obliczanie objętości graniastosłupa prostego o podstawie trapezu [podstawy a,b i wysokość h]
            help
        wyświetlanie dokumentacji");
        break;
    }
    
    return 0;
}

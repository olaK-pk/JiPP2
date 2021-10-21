#include <iostream>
#include "src.cpp"
#include <math.h>

using namespace std;

int main()
{
    
    // random number
    cout<<"podaj zakres liczb:\n";
    cin>>a;
    cin>>b;
    cout<< "numer to:" << random_number(a,b);

    // najwieksza w tablicy
    cout<< "podaj rozmiar tablicy:\n";
    int x;
    cin>>x;

    cout<< "najwieksza liczba w tablicy to: " << tablica(x);

    //odwrot tablicy
    int rozmiar;
    int *tab2 = new int[rozmiar];
    cout>>"podaj rozmiar:\n";
    cin<<rozmiar;
    for(int i=0; i<rozmiar; i++){
        int a = random_number(1,100);
        tab[i] = a;
    }
    odwrot(*tab2[]);



    // przeciazenie
    cout<<"Podaj czego pole chcesz policzyc\n"
    <<"1 - pole kola\n"
    <<"2 - pole trapezu\n"
    <<"3 - pole prostokatu\n";

    int wybor,a,b,c;

    cin>>wybor;

    switch(wybor){
        case 1:
            cout<<"Podaj dlugosc promienia\n r = ";
            cin>>a;
            cout<<"Pole kola = "<<pole(a);
            break;
        case 2:
            cout<<"Podaj dlugosci bokow trapezu\n a = ";
            cin>>a;
            cout<<"b = ";
            cin>>b;
            cout<<"c = ";
            cin>>c;
            cout<<"Pole trapezu = "<<pole(a,b,c);
            break;
        case 3:
            cout<<"Podaj dlugosci bokow prostokatu\n a = ";
            cin>>a;
            cout<<"b = ";
            cin>>b;
            cout<<"Pole prostokatu = "<<pole(a,b);
            break;
        default:
            cout<<"Podano niepoprawna wartosc";
            break;
    }
    
}

//wskazniki srednia
int a, int b;
cout>>"podaj dwie liczby:\n"
cin<<a;
cin<<b;
int *wsk_a = &a;
int *wsk_b = &b;
cout<<"Srednia tych liczb to: " << wskazniki(wsk_a,wsk_b);

//wskaznik tab
int z;
int *tab3 = new int[z];
for(int i=0; i<x; i++){
    int a = random_number(-100,100);
    tab[i] = a;
}
int *wsk = tab3[];
tab_0(wsk);


//dzielenie z wyjatkiem
int a, int b;
cout<<"podaj dwie liczby\n"
cin<<a;
cin<<b;
try{
    MyFunc(a,b);
}

catch (invalid_argument& e){
    cerr << e.what() << endl;
}




return 0;
}
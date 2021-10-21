#define M_PI 3.14159265358979323846

//zadanie 1
int random_number(int a, int b){
    srand (time(NULL));
    int result = rand() % b + a;
    return result;
}

//zadanie 2
int tablica(int x){
    int *tab = new int[x];
    int max = 0;
    for(int i=0; i<x; i++){
        int a = random_number(1,100);
        tab[i] = a;
        if(a>max) max = a;
    }

    return max;
}

//zadanie 3
void odwrot(tab2[]){
    int i, j, pom;
    int x = sizeof(tab2[]);
    j = x-1;
    for(int i=0; i++; i<(x/2)){
        pom = tab2[i];
        tab2[i] = tab2[j];
        tab2[j] = pom;
        j--;
    }
}

//przeciazenie
float pole(int a)
{
    float result;
    result = M_PI*a*a;
    return result;
}

int pole (int a, int b, int c)
{
    int result;
    result=(a+b)*c/2;
    return result;
}

int pole(int a, int b)
{
    int result;
    result=a*b;
    return result;
}


//srednia wskaznikow
float wskazniki(*int a, *int b){
    float srednia = (*a + *b)/2;
    return srednia;
}

//tablica wskazniki
void tab_0(*int tab[]){
    int x = sizeof(tab[]);
    for(int i=0; i++; i<x){
        if(tab[i]>0){
            cout<<tab[i];
        }
    }
}

//zapis zmiennej za pomoca wskaznika
void zapis(int x, *int w){
    int zmienna;
    *w = &zmienna;
    *w = x;
    cout<<zmienna;
}


void MyFunc(int a, b)
{
    if (b == 0)
        throw invalid_argument("dzielnik jest zerem");
    
    float wynik = a/b;
    cout<<wynik;
}

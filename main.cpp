#include <iostream>

class Figura {
protected:
    string kolor, nazwa;
public:
    void printKolor();

    void printNazwa();
};

class Prostokat : public Figura{
protected:
    double a,b;
public:
    void obwodProstokat();
    void poleProstokat();
};

class Kolo : public Figura{
protected:
    double r;
public:
    void obwodKolo();
    void poleKolo();
};


class Trapez : public Figura{
protected:
    double a,b,h;
public:
    void obwodTrapez();
    void poleTrapez();
};

class Trojkat : public Figura{
protected:
    double a,h;
public:
    void obwodTrojkat();
    void poleTrojkat();
};





int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
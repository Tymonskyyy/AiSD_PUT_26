#include <iostream>
#include <string>
using namespace std;

class Zwierz
{
public:
    string gatunek;
    string imie;
    Zwierz()
    {
        cout << "podaj imie\n";
        cin >> imie;
        cout << "utworzono zwierza o imieniu" << imie << "\n";
    }
    ~Zwierz()
    {
        cout << "ubioto zwierza\n";
    };

    void edytuj()
    {
        cout << "podaj nowe imie\n";
        cin >> imie;
    }
};

class Ssak : public Zwierz
{
public:
    int nogi;
    Ssak()
    {
        cout << "utworzono ssaka\n";
    }
    ~Ssak()
    {
        cout << "ubito ssaka\n";
    };
};

class Trojkat
{
public:

    int bok;
    int wysokosc;
    Trojkat()
    {
        cout << "Podaj a\n";
        cin >> bok;
        cout << "Podaj wysokosc\n";
        cin >> wysokosc;
    }
    void licz() {
        cout << "pole wynosi\n" << ((bok * wysokosc / 2));
    }
};


int main() {
    int ile = 0;
    while (true)
    {
        Trojkat dupa;
        dupa.licz();
        ile++;
        cout << "Licznik" << ile << endl;
    }
    return 0;
}
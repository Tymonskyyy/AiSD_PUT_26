	#include <iostream>
	#include <string>
	using namespace std;

	int main() {
		int n;
		int tablica[1000];
		int poczatek = 0;
		int koniec = 0;
		cout << "Wprowadz liczby:";
		cin >> n;
		string deccision;

		for (int i = 0; i < n; i++) {
			cout << "CO chcesz:" << endl;
			cin >> deccision;
			if (deccision == "ISEMPTY") {
				if (poczatek == koniec) {
					cout << "YES" << endl;
				}
				else {
					cout << "NO" << endl;
				}
			}
			if (deccision == "ADD") {
				int x = 0;
				cin >> x;
				tablica[koniec] = x;
				koniec++;
				cout << "Dodano do tablicy";
			}
			if (deccision == "DEL") {
				if (poczatek == koniec) {
					cout << " " << endl;
				}
				else {
					cout << tablica[poczatek] << endl;
					poczatek++;
					}
				}
			}

	}

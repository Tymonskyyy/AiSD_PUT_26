#include <iostream>
#include <vector>
#include <ctime>      // Do pomiaru czasu
#include <iomanip>    // Do ładnego formatowania liczb (setprecision)
#include <cstdlib>    // Do generowania liczb losowych (rand)

using namespace std;

// Twoja funkcja sortująca (Selection Sort)
void selectionSort(vector<int>& v) {
    int n = v.size();
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;

        for (int j = i + 1; j < n; j++) {
            if (v[j] < v[min_idx]) {
                min_idx = j;
            }
        }
        // Zamiana miejscami
        int temp = v[i];
        v[i] = v[min_idx];
        v[min_idx] = temp;
    }
}

int main() {
    int n;
    cout << "Podaj liczbe elementow n: ";
    if (!(cin >> n)) return 0;

    const int REPEATS = 10; // Liczba powtórzeń zgodnie z dobrą praktyką

    // Generowanie instancji (losowej)
    vector<int> data(n);
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        data[i] = rand() % 10000;
    }

    // Pomiar czasu
    clock_t begin = clock();

    for (int i = 0; i < REPEATS; i++) {
        // Ważne: kopiujemy dane, aby każda iteracja sortowała nieposortowaną tablicę
        vector<int> tmp = data;
        selectionSort(tmp);
    }

    clock_t end = clock();

    // Obliczanie średniego czasu
    double duration = (double)(end - begin) / CLOCKS_PER_SEC / REPEATS;

    // Wynik w wymaganym formacie
    cout << "dla n =" << n << " czas potrzebny to: " << fixed << setprecision(6) << duration << endl;

    return 0;
}
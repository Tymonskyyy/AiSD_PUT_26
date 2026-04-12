#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>

using namespace std;

struct Node {
    long long key;
    Node* left, * right;
};

Node* newNode(long long key) {
    Node* node = new Node();
    node->key = key;
    node->left = node->right = nullptr;
    return node;
}

// Funkcja budujaca idealnie zrownowazone drzewo
Node* buildBalancedTree(const vector<long long>& arr, int start, int end) {
    if (start > end) return nullptr;
    int mid = start + (end - start) / 2;
    Node* node = newNode(arr[mid]);
    node->left = buildBalancedTree(arr, start, mid - 1);
    node->right = buildBalancedTree(arr, mid + 1, end);
    return node;
}

// Funkcja szukania - to ja mierzymy
bool treeSearch(Node* root, long long x) {
    while (root != nullptr) {
        if (x == root->key) return true;
        if (x < root->key) root = root->left;
        else root = root->right;
    }
    return false;
}

int main() {
    // UWAGA: Przy BST musimy dac DUZO wieksze k, bo drzewo jest za szybkie!
    int n = 7000;
    int k = 50000; // Liczba powtorzen szukania calego zbioru

    vector<long long> tablica;
    for (int i = 1; i <= n; i++) tablica.push_back(i);

    // Drzewo budujemy z posortowanej tablicy (idealny balans)
    Node* root = buildBalancedTree(tablica, 0, n - 1);

    // Przemieszanie tablicy do szukania, zeby nie szukac po kolei
    auto rng = default_random_engine{};
    shuffle(tablica.begin(), tablica.end(), rng);

    long long znalezione = 0;
    auto start = chrono::high_resolution_clock::now();

    // Glowna petla pomiarowa
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            if (treeSearch(root, tablica[j])) {
                znalezione++;
            }
        }
    }

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> diff = end - start;

    cout << "Zrownowazone BST n=" << n << ", k=" << k << endl;
    cout << "Czas calkowity: " << diff.count() << " s" << endl;
    cout << "Sredni czas jednej operacji: " << diff.count() / (n * k) << " s" << endl;
    cout << "Kontrola (znalezione): " << znalezione << endl;

    return 0;
}
#include <iostream>
#include <queue>
#include <string>

using namespace std;
int main() {
	int n;
	cin >> n;

	queue<int> kolejka; // kolejka z liczbami
	string komenda;	  // kolejka z poleceniami
	for (int i = 0; i < n; i++) {
		cin >> komenda;
		if (komenda == "ADD") {
			int x;
			kolejka.push(x);
		}
		if (komenda == "DEL") {
			if (kolejka.empty()) {
				cout << endl;
			}
			else {
				cout << kolejka.front() << endl;
				kolejka.pop();
			}
		}

		if (kolejka == "ISEMPTY") {
			if (kolejka.empty()) {
				cout << "YES" << endl;
			}
			else {
				cout << "NO" << endl;
			}
		}
		}
	}
}
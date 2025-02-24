#include <iostream>

using namespace std;

void imprimirTriangulo(int altura) {
    for (int i = 1; i <= altura; i++) {
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }
}

int main() {
    int h1, h2, h3;

    cin >> h1 >> h2 >> h3;

    imprimirTriangulo(h1);
    imprimirTriangulo(h2);
    imprimirTriangulo(h3);

    return 0;
}

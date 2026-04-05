#include <iostream>
using namespace std;

int main() {
    int valor1, valor2, valor3;

    cout << "Digite o primeiro valor: ";
    cin >> valor1;

    cout << "Digite o segundo valor: ";
    cin >> valor2;

    cout << "Digite o terceiro valor: ";
    cin >> valor3;

    double resultado = (valor1 + valor2 + valor3) / 3.0;

    cout << "O resultado e " << resultado;

    return 0;
}
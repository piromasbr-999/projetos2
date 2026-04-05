#include <iostream>
#include <random>
using namespace std;

int main() {

    string usuario;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 3);

    cout << "pedra papel ou tesoura: ";
    cin >> usuario;

    int computador = dist(gen);

    if (computador == 1)
        cout << "computador escolheu pedra\n";
    else if (computador == 2)
        cout << "computador escolheu papel\n";
    else
        cout << "computador escolheu tesoura\n";

    // Empates
    if (usuario == "pedra" && computador == 1)
        cout << "empate";
    else if (usuario == "papel" && computador == 2)
        cout << "empate";
    else if (usuario == "tesoura" && computador == 3)
        cout << "empate";

    // Jogador vence
    else if (usuario == "pedra" && computador == 3)
        cout << "jogador venceu";
    else if (usuario == "papel" && computador == 1)
        cout << "jogador venceu";
    else if (usuario == "tesoura" && computador == 2)
        cout << "jogador venceu";

    // Computador vence
    else
        cout << "computador venceu";

    return 0;
}
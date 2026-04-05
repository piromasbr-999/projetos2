#include <iostream>
#include <random>
using namespace std;

int main() {

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(100, 999);

    int segredo = dist(gen);

    int tentativa;

    int centena = segredo / 100;
    int dezena = (segredo / 10) % 10;
    int unidade = segredo % 10;

    cout << "Digite o codigo de 3 digitos: ";
    cin >> tentativa;

    while (tentativa != segredo) {

        int c_t = tentativa / 100;
        int d_t = (tentativa / 10) % 10;
        int u_t = tentativa % 10;

        if (c_t == centena)
            cout << "Centena correta\n";
        else if (c_t == dezena || c_t == unidade)
            cout << "Centena existe mas posicao errada\n";
        else
            cout << "Centena nao existe\n";

        if (d_t == dezena)
            cout << "Dezena correta\n";
        else if (d_t == centena || d_t == unidade)
            cout << "Dezena existe mas posicao errada\n";
        else
            cout << "Dezena nao existe\n";

        if (u_t == unidade)
            cout << "Unidade correta\n";
        else if (u_t == centena || u_t == dezena)
            cout << "Unidade existe mas posicao errada\n";
        else
            cout << "Unidade nao existe\n";

        cout << "\nTente novamente: ";
        cin >> tentativa;
    }

    cout << "COFRE ABERTO 💰\n";

    return 0;
}
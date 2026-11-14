#include <iostream>
#include <string>  // permite usar o tipo string
    using namespace std;

// Tabela com todos os simbolos possiveis; a posicao de cada um e o seu valor
string DIGITOS = "0123456789ABCDEF";

// Recebe um caractere e devolve o valor dele. Ex: 'A' -> 10
int valorDoDigito(char c)
{
    // Percorre as posicoes de 0 a 15 da tabela DIGITOS
    for (int i = 0; i < 16; i++)
    {
        if (DIGITOS[i] == c)
        {
            return i;
        }
    }
    return -1; // simbolo invalido, pois nao existe em DIGITOS
}

// Converte um numero de qualquer base para decimal
int paraDecimal(string numero, int base)
{
    int resultado = 0; // guarda o valor acumulado

    // Percorre cada caractere do numero, da esquerda para a direita
    for (int i = 0; i < numero.size(); i++)
    {
        // Transforma o caractere em valor (ex: 'A' vira 10)
        int valor = valorDoDigito(numero[i]);
        // Empurra o que ja foi acumulado uma casa e soma o novo digito
        resultado = resultado * base + valor;
    }

    return resultado;
}

// Converte um numero decimal para qualquer base
string deDecimal(int numero, int base)
{
    // sem isso, o while nao roda e o resultado fica vazio
    if (numero == 0)
    {
        return "0";
    }

    string resultado = ""; // comeca vazio e vai sendo montado

    // Repete ate o numero chegar a zero
    while (numero > 0)
    {
        int resto = numero % base;              // o resto da divisao e o proximo digito
        resultado = DIGITOS[resto] + resultado; // insere o novo digito na frente
        numero = numero / base;                 // divide para continuar no proximo ciclo
    }

    return resultado;
}

int main()
{
    // Variaveis que guardam o que o usuario digitar
    int baseOrigem, baseDestino;
    string numero; // string, pois o numero pode ter letras (ex: 1A)

    cout << "Bases disponiveis: 2, 8, 10, 12, 16\n";
    cout << "Base de origem: ";
    cin >> baseOrigem;
    cout << "Base de destino: ";
    cin >> baseDestino;
    cout << "Numero (inserir letras em maiusculo): ";
    cin >> numero;

    // vai da base de origem para decimal
    int emDecimal = paraDecimal(numero, baseOrigem);
    // vai do decimal para a base de destino
    string resultado = deDecimal(emDecimal, baseDestino);

    cout << "Resultado: " << resultado << "\n";

    return 0;
}

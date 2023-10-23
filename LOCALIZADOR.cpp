
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <iostream>
#include <chrono>
#include <thread>
#include <string>

using namespace std;

void tempo()
{
    for (int i = 0; i < 10; i++)
    {
        printf("Carregando %d", i);
        for (long j = 0; j < 30; j++)
        {
            printf(".");
            Sleep(20);
        }
        printf("\r");
        for (int j = 0; j < 60; j++)
        {
            printf(" ");
        }
        printf("\r");
    }
}

void exibirLetraPorLetra(const string &texto)
{
    const int caracteresPorLinha = 100;
    int contador = 0;

    for (char c : texto)
    {
        cout << c << flush;
        contador++;

        if (contador == caracteresPorLinha)
        {
            cout << endl;
            contador = 0;
        }

        this_thread::sleep_for(chrono::milliseconds(10));
    }
    cout << endl;
}

void drawRectangleWithText(long width, int height, const string &text)
{
    for (int i = 0; i < width; ++i)
        cout << "-";
    cout << endl;

    int verticalPadding = height - 3;
    int remainingVerticalPadding = verticalPadding;
    for (int i = 0; i < verticalPadding / 2; ++i)
    {
        cout << "|";
        for (int j = 0; j < width - 2; ++j)
            cout << " ";
        cout << "|" << endl;
        remainingVerticalPadding -= 2;
    }
    int textLength = text.length();
    int remainingSpace = width - 2;
    int leftSpace = (remainingSpace - textLength) / 2;
    int rightSpace = remainingSpace - leftSpace - textLength;
    cout << "|";
    for (int i = 0; i < leftSpace; ++i)
        cout << " ";
    cout << text;
    for (int i = 0; i < rightSpace; ++i)
        cout << " ";
    cout << "|" << endl;

    for (int i = 0; i < remainingVerticalPadding; ++i)
    {
        cout << "|";
        for (int j = 0; j < width - 2; ++j)
            cout << " ";
        cout << "|" << endl;
    }
    for (int i = 0; i < width; ++i)
        cout << "-";
    cout << endl;
}

float pergunta1(int a, float &r)
{
    string line(100, '=');
    cout << line << endl;
    exibirLetraPorLetra("A) O que faz nosso corpo estar \"preso\" a terra?");
    exibirLetraPorLetra("1- O estado natural do ser humano busca o seu lugar natural na terra, logo ao realizar um movimento forcado ele possui tendencia a voltar a ela.");
    exibirLetraPorLetra("2- Existe uma forca de acao mutua entre corpos massivos, a terra produz uma forca no nosso corpo que estabelece uma aceleracao constante e nos mantem \"preso\".");
    exibirLetraPorLetra("3- Uma forca que nos mantem preso na terra por causa da rotacao da terra em volta do sol.");
    exibirLetraPorLetra("4- A curvatura do espaco-tempo causada pela presenca de massa e energia, que faz com que os corpos sigam trajetorias determinadas por essa curvatura.");

    cout << "Insira sua resposta: ";
    cin >> a;
    cout << endl;

    if (a == 1)
    {
        r = 4;
    }
    if (a == 2)
    {
        r = 12.5;
    }
    if (a == 3)
    {
        r = 8.5;
    }
    if (a == 4)
    {
        r = 25;
    }
    return r;
}

float pergunta2(int a, float &r)
{
    string line(100, '=');
    cout << line << endl;
    exibirLetraPorLetra("B) Qual conceito fisico parece estar *ERRADO* para voce?");
    exibirLetraPorLetra("1- Em situacoes com ausencia de forca externa um objeto possui tendencia a manter seu estado infinitamente, ate uma força externa agir sobre ele.");
    exibirLetraPorLetra("2- A atitude de utilizar um arco e flecha comeca com uma vontade (forca) aplicada a flecha pelo arco, que adquire uma velocidade e momento mas decai devido a ser um ato forcado e ir contra seu estado natural.");
    exibirLetraPorLetra("3- A luz solar consegue chegar na terra devido a capacidade das particulas da luz conseguirem se locomover em locais que não apresentem materia, diferente do som.");
    exibirLetraPorLetra("4- Para um objeto se manter em movimento eh necessario uma forca constante agindo sobre ele.");
    cout << "Insira sua resposta: ";
    cin >> a;
    cout << endl;

    if (a == 1)
    {
        r = r + 4;
    }
    if (a == 2)
    {
        r = r + 25;
    }
    if (a == 3)
    {
        r = r + 8.5;
    }
    if (a == 4)
    {
        r = r + 12.5;
    }

    return r;
}
float pergunta3(int a, float &r)
{
    string line(100, '=');
    cout << line << endl;
    exibirLetraPorLetra("C) Reduzindo-se o *peso* do corpo a metade do seu valor inicial, ele percorrera a mesma distancia na metade do tempo, ou o dobro da distancia no mesmo tempo.");
    exibirLetraPorLetra("1- Verdade.");
    exibirLetraPorLetra("2- Falso.");
    cout << "Insira sua resposta: ";
    cin >> a;
    cout << endl;
    if (a == 1)
    {
        r = r;
    }
    if (a == 2)
    {
        r = r + 25;
    }
    return r;
}
float pergunta4(int a, float &r)
{
    string line(100, '=');
    cout << line << endl;
    exibirLetraPorLetra("D)Eh possivel ocorrer a interacao entre dois corpos com apenas uma forca?");
    exibirLetraPorLetra("1- Verdade.");
    exibirLetraPorLetra("2- Falso.");
    cout << "Insira sua resposta: ";
    cin >> a;
    cout << endl;

    if (a == 2)
    {
        r = r + 25;
    }
    return r;
}
void resultado(float r)
{
    string animationChars = "|/-\\";
    int animationDelay = 100;
    int numFrames = 50;
    for (int i = 0; i < numFrames; i++)
    {
        cout << "Analisando respostas..." << animationChars[i % animationChars.size()] << "\r";
        cout.flush();

        this_thread::sleep_for(chrono::milliseconds(animationDelay));
    }

    cout << endl;
    string loadingText = "Resultado obtido!";
    int rectangleWidth = 100;
    int rectangleHeight = 6;

    drawRectangleWithText(rectangleWidth, rectangleHeight, loadingText);

    cout << endl;

    if (r < 42)
    {
        exibirLetraPorLetra("Com base nos seus conhecimentos voce veio da linha temporal de Aristoteles! voce possui um conhecimento primitivo sobre a fisica e ainda esta desenvolvendo um empirismo!");
    }
    if (r >= 42 && r <= 75)
    {
        exibirLetraPorLetra("Analisando suas respostas posso ver que sua linha temporal esta entre Galileu e Newton, que incrivel! voce ja tem um empirismo desenvolvido e ja quebrou o senso comum");
    }
    if (75 < r && r <= 87.5)
    {
        exibirLetraPorLetra("Uauuu, seu conhecimento eh semelhante ao criador da minha base de dados Jose Garcia, conhecimento desbalanceado o seu... voce eh da epoca do grande fisico Jose Garcia, tem um conhecimento fisico apurado");
    }
    if (r > 87.5)
    {
        exibirLetraPorLetra("Nossa...... voce tem um conhecimento exepecional, pelos meus calculos voce ja concluio a lendaria materia Conceitos B, uma materia que segundo a lenda apenas discipulos de  Jose Garcia ou o mesmo possuiam capacidade de ensina-la..... voce eh um viajante do tempo que veio do futuro, nao possuo capacidade para calcular seu conhecimento fisico... parabens.");
    }
}
int main()
{
    int a;
    float r = 0;
    tempo();
    long width = 100;
    int height = 6;
    string text = "PROGRAMA LOCALIZADOR TEMPORAL INICIADO";
    drawRectangleWithText(width, height, text);
    exibirLetraPorLetra("Bem Vindo anomalia \u2605\u2190\u25CF$\u25CB, sou a inteligencia artificial JARGPT, meu objetivo eh te ajudar a voltar a sua linha do tempo original, mas para isso preciso que voce responda certas perguntas, certo?");
    cout << endl;
    exibirLetraPorLetra("Entao vamos comecar, vao ser 4 perguntas sendo 2 de multipla escolha e 2 de verdadeiro ou falso, cada alternativa possui uma pontuacao que ira calcular seu conhecimento de fisica, coloque o numero que representa a alternativa que voce identifica como correta no local de resposta, para  assim eu identificar a que epoca temporal voce pertence...");
    cout << endl;
    exibirLetraPorLetra("OBSERVACAO: Infelizmente por problemas com a biblioteca de linguagens e por ter muitos usuarios simultaneamente nao possuo acentos, perdao pela situacao incoveniente.");
    cout << endl;
    pergunta1(a, r);
    pergunta2(a, r);
    pergunta3(a, r);
    pergunta4(a, r);
    resultado(r);
    cout << endl
         << "Insira um caractere para terminar o programa.";
    cin >> r;
    return 0;
}

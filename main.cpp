#include <iostream>
#include <ctype.h>
using namespace std;

//Variáveis Globais
char tabuleiro[3][3];
char vencedor = ' ';
bool proxima_partida = true;
int posicoes_usadas[9];

//Funções
void desenhar();
void limpar_tela();
bool verif_podemarcar(int posicao);
void marcar_tabuleiro(int posicao, char player);
bool verif_ganhar();
void reset();


int main()
{

    while(proxima_partida){
        vencedor = ' ';
        for (int l = 0; l < 3; l++)
            {
                for (int c = 0; c < 3; c++)
                {
                    tabuleiro[l][c] = ' ';
                }
            }


            int posicao;
            char player1, player2;
            string resposta;
            int n = 0;
            bool prosseguir = true, fim = false, valido;

            desenhar();
            cout << "Voce quer jogar de X ou O: ";
            cin >> player1;
            player1 = toupper(player1);
            while(prosseguir){
                if (player1 == 'X')
                {
                    player2 = 'O';
                    prosseguir = false;
                }
                else if (player1 == 'O')
                {
                    player2 = 'X';
                    prosseguir = false;
                }
                else
                {
                    desenhar();
                    cout << "Erro, digite X ou O: ";
                    cin >> player1;
                    player1 = toupper(player1);
                }
            }


            while (fim == false && n < 9)
            {
                //Player1
                if(fim == false && n < 9){
                    desenhar();
                    cout << "Player 1 digite onde voce quer colocar " << player1 << ": ";
                    cin >> posicao;
                    valido = verif_podemarcar(posicao);
                    while (valido == false)
                    {
                        desenhar();
                        cout << "Erro, digite uma posicao valida: ";
                        cin >> posicao;
                        valido = verif_podemarcar(posicao);
                    }
                    posicoes_usadas[n] = posicao;
                    n++;
                    marcar_tabuleiro(posicao, player1);
                    fim = verif_ganhar();            
                }

                //Player 2
                if(fim == false && n < 9){
                    desenhar();
                    cout << "Player 2 digite onde voce quer colocar " << player2 << ": ";
                    cin >> posicao;
                    valido = verif_podemarcar(posicao);
                    while (valido == false)
                    {
                        desenhar();
                        cout << "Erro, digite uma posicao valida: ";
                        cin >> posicao;
                        valido = verif_podemarcar(posicao);
                    }
                    posicoes_usadas[n] = posicao;
                    n++;
                    marcar_tabuleiro(posicao, player2);
                    fim = verif_ganhar();            
                }
            }
            desenhar();
            cout<<"\n\nFIM!"<<endl<<endl;
            if(vencedor == 'X' || vencedor == 'O'){
                cout<<vencedor<<" ganhou a partida!"<<endl<<endl; 
            }else{
                cout<<"Empate!"<<endl<<endl;
            }
            cout<<"Quer jogar mais uma partida[s/n]: ";
            cin>>resposta;
            if(resposta == "S" || resposta == "SIM" || resposta == "s" || resposta == "sim"){
                proxima_partida = true;
                reset();
            }else if(resposta == "N" || resposta == "Nao" || resposta == "n" || resposta == "nao"){
                proxima_partida = false;
                limpar_tela;
            }     
        limpar_tela();        
    }
    
}

void limpar_tela()
{
#ifdef OS_Windows
    system("cls");
#else
    system("clear");
#endif
}

void desenhar()
{
    limpar_tela();
    int posicoes_inicias[3][3];
    int n = 1;
    for (int l = 0; l < 3; l++)
    {
        for (int c = 0; c < 3; c++)
        {
            posicoes_inicias[l][c] = n;
            n++;
        }
    }

    cout << "=================" << endl;
    cout << "  Jogo da Velha  " << endl;
    cout << "=================" << endl
         << endl;

    for (int l = 0; l < 3; l++)
    {
        for (int c = 0; c < 3; c++)
        {
            if (tabuleiro[l][c] == 'X' || tabuleiro[l][c] == 'O')
            {
                cout << "[" << tabuleiro[l][c] << "]";
            }
            else
            {
                cout << "[" << posicoes_inicias[l][c] << "]";
            }
        }
        cout << endl;
    }
}

bool verif_podemarcar(int posicao)
{
    bool retornar = true;

    //Verifica se posição é um número aceito
    if (posicao < 0 || posicao > 9)
    {
        retornar = false;
    }

    //Verifica se posição é igual as poisções já usadas
    for (int i = 0; i < 9; i++)
    {
        if (posicao == posicoes_usadas[i])
        {
            retornar = false;
        }
    }
    return retornar;
}

void marcar_tabuleiro(int posicao, char player)
{
    int n = 1;
    for (int l = 0; l < 3; l++)
    {
        for (int c = 0; c < 3; c++)
        {
            if (posicao == n)
            {
                tabuleiro[l][c] = player;
            }
            n++;
        }
    }
}

bool verif_ganhar(){
    int vezesC_x = 0;
    int vezesC_o = 0;

    int vezesL_x = 0;
    int vezesL_o = 0;

    int vezesDD_x = 0;
    int vezesDD_o = 0;

    bool fim = false;


    //Verifica se ganhou por coluna
    for(int l = 0;l < 3;l++){
        vezesC_x = 0;
        vezesC_o = 0;
        for(int c = 0;c < 3;c++){
            if(tabuleiro[l][c] == 'X'){
                vezesC_x++;
            }
            if(tabuleiro[l][c] == 'O'){
                vezesC_o++;
            }
        }
        if(vezesC_x == 3){
            fim = true;
            vencedor = 'X';
        }

        if(vezesC_o == 3){
            fim = true;
            vencedor = 'O';
        }
    }


    //Verifica se ganhou por linha
    for(int c = 0;c < 3;c++){
        vezesL_x = 0;
        vezesL_o = 0;
        for(int l = 0;l < 3;l++){
            if(tabuleiro[l][c] == 'X'){
                vezesL_x++;
            }
            if(tabuleiro[l][c] == 'O'){
                vezesL_o++;
            }
        }
        if(vezesL_x == 3){
            fim = true;
            vencedor = 'X';
        }

        if(vezesL_o == 3){
            fim = true;
            vencedor = 'O';
        }
    }

    //Verifica se ganhou pela diagonal da direita
    for(int l = 0;l < 3;l++){
        for(int c = 0;c < 3;c++){
            if(l == c){
                if(tabuleiro[l][c] == 'X'){
                    vezesDD_x++;
                }
                if(tabuleiro[l][c] == 'O'){
                    vezesDD_o++;
                } 
            }
        }
        if(vezesDD_x == 3){
            fim = true;
            vencedor = 'X';
        }

        if(vezesDD_o == 3){
            fim = true;
            vencedor = 'O';
        }
    }

    //Verifica se ganhou pela diagonal da esquerda
    if(tabuleiro[0][2] == 'X'){
        if(tabuleiro[1][1] == 'X'){
            if(tabuleiro[2][0] == 'X'){
                fim = true;
                vencedor = 'X';
            }
        }
    }
    if(tabuleiro[0][2] == 'O'){
        if(tabuleiro[1][1] == 'O'){
            if(tabuleiro[2][0] == 'O'){
                fim = true;
                vencedor = 'O';
            }
        }
    }

    return fim;

}

void reset(){
    for(int i = 0;i < 9;i++){
        posicoes_usadas[i] = 0;
    }
}

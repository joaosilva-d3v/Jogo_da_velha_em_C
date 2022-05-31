#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char tabuleiro[3][3];
int l, c, jogador, jogadas, ganhou, opcao = 0;
void inicia_tabuleiro(char tab[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            tab[i][j] = ' ';
        }
    }

}
void apresenta_tabuleiro(char tab[3][3]){
    printf("\n\t     0     1     2\n\t   -----------------\n");
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(j == 0)
                    printf("\t%d| ",i);
                printf("  %c  ",tab[i][j]);
                if(j < 2)
                    printf("|");
            }
            if(i < 2)
                printf("\n\t   -----------------");
            printf("\n");
        }
}

int main(){
    do{
        jogador = 1;
        jogadas = 1;
        ganhou = 0;
        system("clear");
        
        //função para inicialização do tabulleiro, para preenchê-lo com espaços vazios
        inicia_tabuleiro(tabuleiro);

        do{

        printf("\t  ----JOGO DA VELHA---\n");
        //apresentação "grafica" do tabuleiro no terminal
        apresenta_tabuleiro(tabuleiro);

        printf("\n\tJOGADOR 1 [x]  JOGADOR 2[o]\n");
        //ler coordenadas para realizar as jogadas
        do{
            printf("\n\tJOGADOR %d\n",jogador);
            printf("\tDigite as coordenadas para jogar [l][c]:");
            scanf("%d%d", &l, &c);
            if(l < 0 || l > 2 || c < 0 || c > 2 || tabuleiro[l][c] != ' '){
                printf("\t-Ops, jogada inválida. Tente novamente.");
            }
        }while(l < 0 || l > 2 || c < 0 || c > 2 || tabuleiro[l][c] != ' ');

        if(jogador == 1){
            tabuleiro[l][c] = 'X';
            jogador ++;
        }else{
            tabuleiro[l][c] = 'O';
            jogador = 1;
        }

        // verifica se o jogador 1 venceu após cada jogada
        if(tabuleiro[0][0] == 'X' && tabuleiro[0][1] == 'X' && tabuleiro[0][2] == 'X' ||
        tabuleiro[1][0] == 'X' && tabuleiro[1][1] == 'X' && tabuleiro[1][2] == 'X' ||
        tabuleiro[2][0] == 'X' && tabuleiro[2][1] == 'X' && tabuleiro[1][2] == 'X')
        {
            system("clear");
            printf("\t  Jogador %d ganhou!!!\n", jogador - 1);
            apresenta_tabuleiro(tabuleiro);
            ganhou = 1;
        }

        if(tabuleiro[0][0] == 'X' && tabuleiro[1][0] == 'X' && tabuleiro[2][0] == 'X' ||
        tabuleiro[0][1] == 'X' && tabuleiro[1][1] == 'X' && tabuleiro[2][1] == 'X' ||
        tabuleiro[0][2] == 'X' && tabuleiro[1][2] == 'X' && tabuleiro[2][2] == 'X')
        {
            system("clear");
            printf("\t Jogador %d ganhou!!!\n", jogador - 1);
            apresenta_tabuleiro(tabuleiro);
            ganhou = 1;
        }
        if(tabuleiro[0][0] == 'X' && tabuleiro[1][1] == 'X' && tabuleiro[2][2] == 'X'){
            system("clear");
            printf("\t  Jogador %d ganhou!!!\n", jogador - 1);
            apresenta_tabuleiro(tabuleiro);
            ganhou = 1;
        }
        if(tabuleiro[0][2] == 'X' && tabuleiro[1][1] == 'X' && tabuleiro[2][0] == 'X'){
            system("clear");
            printf("\t  Jogador %d ganhou!!!\n", jogador - 1);
            apresenta_tabuleiro(tabuleiro);
            ganhou = 1;
        }

        //verifica se o jogador 2 venceu apos cada jogada
        if(tabuleiro[0][0] == 'O' && tabuleiro[0][1] == 'O' && tabuleiro[0][2] == 'O' ||
        tabuleiro[1][0] == 'O' && tabuleiro[1][1] == 'O' && tabuleiro[1][2] == 'O' ||
        tabuleiro[2][0] == 'O' && tabuleiro[2][1] == 'O' && tabuleiro[1][2] == 'O')
        {
            system("clear");
            printf("\t  Jogador %d ganhou!!!\n", jogador + 1);
            apresenta_tabuleiro(tabuleiro);
            ganhou = 1;
        }
        if(tabuleiro[0][0] == 'O' && tabuleiro[1][0] == 'O' && tabuleiro[2][0] == 'O' ||
        tabuleiro[0][1] == 'O' && tabuleiro[1][1] == 'O' && tabuleiro[2][1] == 'O' ||
        tabuleiro[0][2] == 'O' && tabuleiro[1][2] == 'O' && tabuleiro[2][2] == 'O')
        {
            system("clear");
            printf("\t  Jogador %d ganhou!!!\n", jogador + 1);
            apresenta_tabuleiro(tabuleiro);
            ganhou = 1;
        }
        if(tabuleiro[0][0] == 'O' && tabuleiro[1][1] == 'O' && tabuleiro[2][2] == 'O'){
            system("clear");
            printf("\t  Jogador %d ganhou!!!\n", jogador + 1);
            apresenta_tabuleiro(tabuleiro);
            ganhou = 1;
        }
        if(tabuleiro[0][2] == 'O' && tabuleiro[1][1] == 'O' && tabuleiro[2][0] == 'O'){
            system("clear");
            printf("\t  Jogador %d ganhou!!!\n", jogador + 1);
            apresenta_tabuleiro(tabuleiro);
            ganhou = 1;
        }
        jogadas ++;
        }while(jogadas < 10 && ganhou == 0);
        if(ganhou == 0)
            printf("Ops, parece que ninguém ganhou!\n");
            //verifica se os jogadores querem jogar novamente
        printf("\n\tPara jogar novamente digite 1: ");
        scanf("%d",&opcao);
    }while(opcao == 1);
    return 0;
}
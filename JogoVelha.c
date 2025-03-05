#include <stdio.h>

void imprimirJogo(char str[][3]){
    for (int i = 0; i < 3; i ++){
        if(i == 0) 
            printf("  %d  %d  %d\n",0, 1,2);
        else 
            printf("%d", i );
        for (int j = 0; j < 3; j++){
            if(j == 0 && i == 0) 
                printf("%d", 0);
            printf(" %c ", str[i][j]);
        }
        printf("\n");
    }
}

int verificar(int a,int b, char str[][3]){
    if ((b > 2 || b < 0)) return 1;
    else if (a > 2 || a < 0 ) return 1;
    else if (str[a][b] != '-') return 1;
    else return 0;
}

int vaiVencer(char str[][3], int *a, int *b){
    int c1 = 0 ,c2 = 0;
    //verificar diagonal principal
    if((str[0][0] == 'X' && str[1][1] == 'X' && str[2][2] == '-') ){
        *a = 2;
        *b = 2;
        return 1;
    }
    else if((str[2][2] == 'X' && str[0][0] == 'X' && str[1][1] == '-')){
        *a = 1;
        *b = 1;
        return 1;
    }
    else if((str[1][1] == 'X' && str[2][2] == 'X' && str[0][0] == '-')){
        *a = 0;
        *b = 0;
        return 1;
    }
    else if((str[0][2] == 'X' && str[1][1] == 'X' && str[2][0] == '-') ){
        *a = 2;
        *b = 0;
        return 1;
    }
    else if((str[0][2] == 'X' && str[2][0] == 'X' && str[1][1] == '-')){
        *a = 1;
        *b = 1;
        return 1;
    }
    else if((str[1][1] == 'X' && str[2][0] == 'X' && str[0][2] == '-')){
        *a = 0;
        *b = 2;
        return 1;
    }

    int k = 0,x = 0;
    //testar cada coluna
    while (x < 3){
        if (str[k][x] == 'X'){
            c1++;
        }
        k++;
        if(k > 2){
            if(c1 == 2) {
                int aux = 0;
                printf("Entrou 100%%\n");
                while(aux < 3){
                    if(str[aux][x] == '-'){
                        *a = aux;
                        *b = x;
                        return 1;
                    }
                    aux++;
                }
            }
            else{
                c1 = 0;
            }
            k = 0;
            x++;
        }   
    }
    x = 0, k = 0;

    //verificar linha
    while (x < 3){
        if (str[x][k] == 'X'){
            c1++;
        }
        k++;
        if(k > 2){
            if(c1 == 2) {
                int aux = 0;
                while(aux < 3){
                    if(str[x][aux] == '-'){
                        *a = x;
                        *b = aux;
                        return 1;
                    }
                    aux++;
                }
            }
            else{
                c1 = 0;
            }
            k = 0;
            x++;
        }   
    }
    return 0;
}

int cpuGanhar(char str[][3],int *a, int *b){
    int c1 = 0 ,c2 = 0;
    //verificar diagonal principal
    if((str[0][0] == 'O' && str[1][1] == 'O' && str[2][2] == '-') ){
        *a = 2;
        *b = 2;
        return 1;
    }
    else if((str[2][2] == 'O' && str[0][0] == 'O' && str[1][1] == '-')){
        *a = 1;
        *b = 1;
        return 1;
    }
    else if((str[1][1] == 'O' && str[2][2] == 'O' && str[0][0] == '-')){
        *a = 0;
        *b = 0;
        return 1;
    }
    else if((str[0][2] == 'O' && str[1][1] == 'O' && str[2][0] == '-') ){
        *a = 2;
        *b = 0;
        return 1;
    }
    else if((str[0][2] == 'O' && str[2][0] == 'O' && str[1][1] == '-')){
        *a = 1;
        *b = 1;
        return 1;
    }
    else if((str[1][1] == 'O' && str[2][0] == 'O' && str[0][2] == '-')){
        *a = 0;
        *b = 2;
        return 1;
    }

    int k = 0,x = 0;
    //testar cada coluna
    while (x < 3){
        if (str[k][x] == 'O'){
            c1++;
        }
        k++;
        if(k > 2){
            if(c1 == 2) {
                int aux = 0;
                printf("Entrei aqui! (coluna)");
                while(aux < 3){
                    if(str[aux][x] == '-'){
                        *a = aux;
                        *b = x;
                        return 1;
                    }
                    aux++;
                }
            }
            c1 = 0;
            k = 0;
            x++;
        }   
    }
    x = 0, k = 0;

    //verificar linha
    while (x < 3){
        if (str[x][k] == 'O'){
            c1++;
        }
        k++;
        if(k > 2){
            if(c1 == 2) {
                int aux = 0;
                while(aux < 3){
                    if(str[x][aux] == '-'){
                        printf("Entrei aqui! (linha)");
                        *a = x;
                        *b = aux;
                        return 1;
                    }
                    aux++;
                }
            }
            c1 = 0;
            k = 0;
            x++;
        }   
    }
    return 0;
}

int verificarVencedor(char str[][3]){
    int c1 = 0 ,c2 = 0;
    //verificar diagonal principal
    if(str[0][0] == 'X' &&str[1][1] == 'X' && str[2][2] == 'X') return 1; // jogador ganhou
    else if(str[0][0] == 'O'&& str[1][1] == 'O' && str[2][2] == 'O') return 0; // cpu ganhou
    //verificar diagonal secundaria
    if(str[0][2] == 'X' &&str[1][1] == 'X' && str[2][0] == 'X') return 1; //jogador ganhou
    else if (str[0][2] == 'O' &&str[1][1] == 'O' && str[2][0] == 'O') return 0; // cpu ganhou

    int k = 0,x = 0;
    //testar cada coluna
    while (x < 3){
        if (str[k][x] == 'X'){
            c1++;
        }
        else if(str[k][x] == 'O'){
            c2++;
        }
        k++;
        if(k > 2){
            x++;
            k = 0;
            if(c1 == 3) return 1;
            else if (c2 == 3) return 0;
            else{
                c1 = 0;
                c2 = 0;
            }
        }   
    }

    //verificar linha
    for (int i = 0; i < 3; i ++){
        for (int j = 0; j < 3; j++){
            if(str[i][j] == 'X'){
                c1++;
            }
            else if(str[i][j] == 'O'){
                c2++;
            }
        }
        //jogador ganhou
        if(c1 == 3) 
            return 1;
        //cpu ganhou
        else if (c2 == 3) 
            return 0;
        //se ninguem ganhou, retorna contagem
        else{
            c1 = 0;
            c2 = 0;
        }
    }
    return 2;
}

void cpuJoga(int jogadas, int a, int b, char str[][3]){
    int x,y;
    if(jogadas >= 2){
        if (cpuGanhar(str,&x,&y) == 1){
            printf("Entrou aqui!");
            str[x][y] = 'O';
        }
        else if (vaiVencer(str,&x,&y) == 1){
            str[x][y] = 'O';
        }
        else{
            if(a == 0 && b == 0) {
                if(str[0][2] == '-'){
                    str[0][2] = 'O';
                }
            }
            else if (a == 0 && b == 2){
                if(str[0][0] == '-'){
                    str[0][0] = 'O';
                }
            }
            else if (a == 2 && b == 0){
                if(str[2][2] == '-'){
                    str[2][2] = 'O';
                }
            }
            else if (a == 2 && b == 2){
                if(str[1][2] == '-'){
                    str[1][2] = 'O';
                }
            }
        }    
    }
    else{
        if(a == 0 && b == 0) {
            if(str[1][1] == '-'){
                str[1][1] = 'O';
            }
        }
        else if (a == 0 && b == 2){
            if(str[1][1] == '-'){
                str[1][1] = 'O';
            }
        }
        else if (a == 2 && b == 0){
            if(str[1][1] == '-'){
                str[1][1] = 'O';
            }
        }
        else if (a == 2 && b == 2){
            if(str[1][1] == '-'){
                str[1][1] = 'O';
            }
        }
        else{
            if (str[0][0] == '-') str[0][0] = 'O';
        }
    }
}

void jogarVelha(char str[][3]){
    int jogadas = 0;
    int posx,posy;
    do{
        printf("Digite a posicao (x,y): ");
        scanf("%d%d", &posx,&posy);
        if(verificar(posx,posy,str) == 0){
            printf("Voce jogou!\n");
            str[posx][posy] = 'X';
            jogadas++;
            imprimirJogo(str);
            if(verificarVencedor(str) != 1)
            {
                cpuJoga(jogadas,posx,posy,str);
                printf("Cpu jogou!\n");
            }
            imprimirJogo(str);
        }
        else{
            printf("Posicao invaldia!\n");
        }
    }while(verificarVencedor(str) == 2 && jogadas < 5);
    if(verificarVencedor(str) == 1) printf("Ganhou!\n");
    else if (verificarVencedor(str) == 0) printf("CPU ganhou!");
    else printf("Empate!");
}


int main(){
    char str[3][3];
    for (int i = 0; i < 3; i ++){
        for (int j = 0; j < 3; j++){
            str[i][j] = '-';
        }
    }
    imprimirJogo(str);
    jogarVelha(str);

    return 0;
}
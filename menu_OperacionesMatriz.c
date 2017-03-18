#include <stdio.h>
#include <windows.h>
void Capturar(int *n1, int *m1, float fMat01[10][10]);
void Imprimir(int n1, int m1, float fMat01[10][10]);
void renglonPorConstante(int renglon, float constante, float matriz[10][10], int columnas);
void intercambiarRenglones(int primerRenglon, int segundoRenglon,float matriz[10][10],int columnas);
void R2_R2MCteR1(int n1, int m1, int R1, int R2, float fCte, float fMat01[10][10]);

int main()
{
    int opcion,n,m,iRen1,iRen2;
    float fMat[10][10],fCte;
    do{
        printf("=====================================\n");
        printf("1. Capturar Matriz.\n");
        printf("2. Imprimir. \n");
        printf("3. Multiplicar renglon por constante.\n");
        printf("4. Intercambiar renglones\n");
        printf("5. R2_R2MCteR1\n");
        printf("6. Terminar\n");
        printf("\nProporcione la opcion deseada: ");
        scanf("%d",&opcion);
        system("cls");
        switch(opcion){
            case 1: Capturar(&n,&m,fMat);break;
            case 2: Imprimir(n,m,fMat);break;
            case 3: {
                    printf("Proporcione en numero de renglon: ");
                    scanf("%d",&iRen1);
                    printf("Proporcione el valor de la constante: ");
                    scanf("%f",&fCte);
                    renglonPorConstante(iRen1,fCte,fMat,m);
                    break;
            }
            case 4: {
                printf("Proporcione el primer renglon: ");
                scanf("%d",&iRen1);
                printf("Proporcione el segundo renglon: ");
                scanf("%d",&iRen2);
                intercambiarRenglones(iRen1,iRen2,fMat,m);
                break;
            }
            case 5: {
                printf("Proporcione en numero del primer renglon: ");
                scanf("%d",&iRen1);
                printf("Proporcione en numero del segundo renglon: ");
                scanf("%d",&iRen2);
                printf("Proporcione el valor de la constante: ");
                scanf("%f",&fCte);
                R2_R2MCteR1(n,m,iRen1,iRen2,fCte,fMat);
                break;
            }
        }
    }
    while(opcion!=6);
    return 0;
}

void Capturar(int *n1, int *m1, float fMat01[10][10]){
    int i,j;
    printf("Proporcione la cantidad de renglones: ");
    scanf("%d",&*n1);
    printf("Proporcione la cantidad de columnas: ");
    scanf("%d",&*m1);
    for(i=0;i<*n1;i++){
        for(j=0;j<*m1;j++){
            printf("Proporcione el valor de M[%d][%d]: ",i,j);
            scanf("%f",&fMat01[i][j]);
        }
    }
}

void Imprimir(int n1, int m1, float fMat01[10][10]){
    int i,j;
    for(i=0;i<n1;i++){
        for(j=0;j<m1;j++){
            printf("%2.2f\t",fMat01[i][j]);
        }
        printf("\n");
    }
}

void renglonPorConstante(int renglon, float constante, float matriz[10][10],int columnas){
    int i;
    for(i=0;i<columnas;i++){
        matriz[renglon][i]*=constante;
    }
}

void intercambiarRenglones(int primerRenglon, int segundoRenglon,float matriz[10][10],int columnas){
    int i;
    float auxiliar;
    for(i=0;i<columnas;i++){
        auxiliar=matriz[primerRenglon][i];
        matriz[primerRenglon][i]=matriz[segundoRenglon][i];
        matriz[segundoRenglon][i]=auxiliar;
    }
}

void R2_R2MCteR1(int n1, int m1, int R1, int R2, float fCte, float fMat01[10][10]){
    int i;
    float fTerm;
    for(i=0;i<m1;i++){
        fTerm=fCte*fMat01[R1][i];
        fMat01[R2][i]=fMat01[R2][i]+fTerm;
    }
    return;
}

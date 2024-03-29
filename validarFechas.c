#include <stdio.h>
#include <stdlib.h>
#define DIAS 365

int bisiesto(int);
int cantidadDiasDelMes(int, int);
int esFechaValida(int, int, int);
//##############################//
int valNumero();
void sumarDia(int, int, int);
void restarDia(int, int, int);
void sumarNdias(int, int, int);
void restarNdias(int, int, int);

int main(){
    int dia, mes, year, opcion, b = 0;

    do{
        system("cls");
        printf("Ingresar fecha(DD/MM/AAAA): ");
        scanf("%d %d %d", &dia, &mes, &year);

    }while(esFechaValida(dia, mes, year) != 1);

    printf("\n\nFecha validada: %d/%d/%d\n\n", dia, mes, year);

    do{
        if(b != 0)
            system("cls");

        printf("Opciones:"
                "\n\t1. Sumar un dia"
                "\n\t2. Restar un dia"
                "\n\t3. Sumar n dias"
                "\n\t4. Restar n dias\n"
                "\n\t9. Salir\n");
        scanf("%d", &opcion);
    }while(opcion < 1 || opcion > 4 && !(opcion == 9));

    switch(opcion){
        case 1:
            sumarDia(dia,mes,year);
            break;
        case 2:
            restarDia(dia,mes,year);
            break;
        case 3:
            sumarNdias(dia,mes,year);
            break;
        case 4:
            restarNdias(dia,mes,year);
            break;
        case 9:
            system("cls");
            printf("###########\n");
            printf("# Saludos #\n");
            printf("###########\n");
            break;
    }

    return 0;
}

int esFechaValida(int d, int m, int a){
    int r = 0;

    if(a>1582 && a<2019){
        if(m>=1 && m<=12){
            if(d>=1 && d<=cantidadDiasDelMes(m,a)){
                r = 1;
            }
        }
    }
    return r;
}

int cantidadDiasDelMes(int m, int a){
    int cdm;

    if(m==4 || m==6 || m==9 || m==11){
        cdm = 30;
    }else{
        if(m==2){
            cdm = 28 + bisiesto(a);
        }else{
            cdm = 31;
        }
    }
    return cdm;
}

int bisiesto(int a){
    if(a % 4 == 0 && (a%100 != 0 || a%400 == 0)){
        return 1;
    }else{
        return 0;
    }
}

//##############################//

int valNumero(){
    int n;
    do{
        printf("\nIngrese un numero: ");
        scanf("%d", &n);
        if(n<0)
            n*=-1;
    }while(n==0);

    return n;
}

void sumarDia(int d, int m, int a){
    int dias;
    dias=cantidadDiasDelMes(m,a);

    if(d<dias){
        d++;
    }else{
        if(m<12){

            m++;
            d=1;
        }else{
            m=1;
            d=1;
            a++;
        }
    }
    system("cls");
    printf("Nueva fecha: %d/%d/%d\n",d,m,a);
}

void restarDia(int d, int m, int a){
    if(d>1){
        d--;
    }else{
        if(m>1){
            m--;
            d=cantidadDiasDelMes(m,a);
        }else{
            m=12;
            a--;
            d=cantidadDiasDelMes(m,a);
        }
    }
    system("cls");
    printf("Nueva fecha: %d/%d/%d\n",d,m,a);
}

void sumarNdias(int d, int m, int a){
    int num, dias, cont = 0;
    num = valNumero();

    do{
        dias = cantidadDiasDelMes(m,a);
        if(num==DIAS){
            a++;
            num=0;
        }else if(num>DIAS){
            num-= DIAS;
            a++;
            printf("Dias restantes: %d\n", num);
            printf("%d/%d/%d",d,m,a);
        }else{
            if(num>dias){
                num-= dias;
                m++;
                d++;
                cont++;
            }else{
                d+=num-cont;
                num-=num;
                printf("\n\nDias restantes: %d\n", num);
                break;
            }

            printf("\n\nDias restantes: %d\n", num);
            printf("%d/%d/%d",d,m,a);
        }
    }while(num>0);

    //system("cls");
    printf("Nueva fecha: %d/%d/%d\n",d,m,a);
}

void restarNdias(int d, int m, int a){
    int num;
    num = valNumero();

    system("cls");
    printf("Nueva fecha: %d/%d/%d\n",d,m,a);
}



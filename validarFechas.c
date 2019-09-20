#include <stdio.h>
#include <stdlib.h>

int bisiesto(int);
int cantidadDiasDelMes(int, int);
int esFechaValida(int, int, int);
//##############################//
int valNumero();
int fecha(int, int, int);
int sumarDia(int, int, int);
int restarDia(int, int, int);
int sumarNdias(int, int, int);
int restarNdias(int, int, int);
void mostrarFecha(int);

int main(){
    int dia, mes, year, opcion, fecha, b = 0;

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
            b = 1;
    }while(opcion < 1 || opcion > 4 && !(opcion == 9));

    switch(opcion){
        case 1:
            fecha = sumarDia(dia,mes,year);
            mostrarFecha(fecha);
            break;
        case 2:
            fecha = restarDia(dia,mes,year);
            mostrarFecha(fecha);
            break;
        case 3:
            fecha = sumarNdias(dia,mes,year);
            mostrarFecha(fecha);
            break;
        case 4:
            fecha = restarNdias(dia,mes,year);
            mostrarFecha(fecha);
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
    }while(n<=0);

    return n;
}

int sumarDia(int d, int m, int a){
    int dias, f;
    dias=cantidadDiasDelMes(m,a);

    if(d<dias){
        d+=1;
    }else{
        if(m<12){
            m+=1;
            d=1;
        }else{
            m=1;
            d=1;
            a+=1;
        }
    }
    f = fecha(d,m,a);

    return f;
}

int restarDia(int d, int m, int a){
    int f;

    if(d>1){
        d-=1;
    }else{
        if(m>1){
            m-=1;
            d=cantidadDiasDelMes(m,a);
        }else{
            m=12;
            a-=1;
            d=cantidadDiasDelMes(m,a);
        }
    }
    f = fecha(d,m,a);

    return f;
}

int sumarNdias(int d, int m, int a){
    int num;
    num = valNumero();

}

int restarNdias(int d, int m, int a){
    int num;
    num = valNumero();

}

int fecha(int d, int m, int a){
    int f;
    if(d<10){
        d*=100000;
        m*=10000;
    }else{
        d*=1000000;
        m*=10000;
    }
    f=d+m+a;

    return f;
}

void mostrarFecha(int f){
    int d, mr, m, a;
    if(f<999999){
        d = f/100000;
        mr = f%100000;
        m = mr/10000;
        a = mr%10000;
    }else{
        d = f/1000000;
        mr = f%1000000;
        m = mr/10000;
        a = mr%10000;
    }

    printf("\n%d/%d/%d",d,m,a);
}

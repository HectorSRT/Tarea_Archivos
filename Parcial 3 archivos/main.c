#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char lastName[50];
    float average;
} Alumno;

void guardar_arreglo(int n, Alumno a[n], FILE *fp);
void ordenar(int n, Alumno *a);
void imprimir(int n, Alumno *a);

int main(){
    int n;
    scanf("%d", &n);
    Alumno arreglo[n];
    FILE *fp = fopen("aprendizaje2.dat","rb");
    guardar_arreglo(n, arreglo, fp);
    fclose(fp);
    imprimir(n, arreglo);
    ordenar(n, arreglo);
    imprimir(n, arreglo);

    return 0;
}

void guardar_arreglo(int n, Alumno a[n], FILE *fp){
    int i = 0;
    while(!feof(fp)){
        fscanf(fp, "%s%s%f", a[i].name, a[i].lastName, &a[i].average);
    }
}

void ordenar(int n, Alumno *a){
    Alumno temp;
    for (int i = 0; i < n-1; i++){
        for (int j = 0; j < n-i-1; j++){
            if (strcmp(a[j].lastName ,a[j+1].lastName) > 0){
                temp.average = a[j].average;
                strcpy(temp.name,a[j].name);
                strcpy(temp.lastName,a[j].lastName);

                a[j].average = temp.average;
                strcpy(a[j].name, a[j+1].name);
                strcpy(a[j].lastName,a[j+1].lastName);

                a[j+1].average = temp.average;
                strcpy(a[j+1].name, temp.name);
                strcpy(a[j+1].lastName,temp.lastName);
            }
        }
    }
}

void imprimir(int n, Alumno *a){
    for(int i = 0; i < n; i++){
        printf("%s %s %.1f", a[i].lastName, a[i].name, a[i].average);
    }
}

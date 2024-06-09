#include <stdio.h>

const char diasUteisSemana[][8] = {"Segunda", "Terca", "Quarta", "Quinta", "Sexta"};

typedef struct Hora{
    int h, min;
}Hora;

typedef struct Dia
{
    Hora horarioInicio, horarioFim;
} Dia;

typedef struct Materia
{
    char nome[20];
    Dia horarios[5];
} Materia;

void mostraFormatoHora(Hora tempo){
    if(tempo.h < 10){
        printf("0");
    }
    printf("%d:", tempo.h);

    if(tempo.min < 10){
        printf("0");
    }
    printf("%d", tempo.min);
}

Materia novaMateria()
{
    Materia nova;
    int i;
    scanf("%s", nova.nome);
    for (i = 0; i < 5; i++)
    {
        scanf("%d:%d %d:%d", &nova.horarios[i].horarioInicio.h,
        &nova.horarios[i].horarioInicio.min,
        &nova.horarios[i].horarioFim.h,
        &nova.horarios[i].horarioFim.min);
    }
    return nova;
}

void mostrarMateria(Materia materia){
    int i;
    printf("%s\n", materia.nome);
    for(i = 0; i < 5; i++){
        if(materia.horarios[i].horarioFim.h && materia.horarios[i].horarioInicio.h){
            printf("%s\nInicio: ", diasUteisSemana[i]);
            mostraFormatoHora(materia.horarios[i].horarioInicio);
            printf(" Fim: ");
            mostraFormatoHora(materia.horarios[i].horarioFim);
            printf("\n");
        }
    }
}

int main()
{
    int nMaterias, i;
    Materia materias[20];
   
    scanf("%d", &nMaterias);
    for(i = 0; i < nMaterias; i++){
        materias[i] = novaMateria();
    }
    
    return 0;
}
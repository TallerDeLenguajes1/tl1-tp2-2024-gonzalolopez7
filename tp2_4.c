#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define TAMA 5

struct 
{
    
    int velocidad;
    int anio;
    int cantidad;
    char *tipo_cpu;

} typedef compu;


void cargarPC(compu *compus);
void listaPC(compu *compus);
void mostrarVieja(compu *compus);
void mostrarMasRapida(compu *compus);

int main() {

    compu compus[TAMA];

    cargarPC(compus);
    listaPC(compus);
    mostrarVieja(compus);
    mostrarMasRapida(compus);

    return 0;
}

void cargarPC(compu *compus)
{

    char tipos[6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};

    srand(time(NULL));

    for (int i = 0; i < TAMA; i++)
    {
        
        compus[i].velocidad = rand() % 3 + 1;
        compus[i].anio = rand() % 10 + 2015;
        compus[i].tipo_cpu = (char *)malloc(strlen(tipos[i]) + 1);
        strcpy(compus[i].tipo_cpu, tipos[i]);
        compus[i].cantidad = rand() % 8 + 1;

    }

}

void listaPC(compu *compus)
{

    for (int i = 0; i < TAMA; i++)
    {
        
        printf("\n\n PC %d\n", i+1);
        printf("Velocidad: %d - Anio: %d - Tipo CPU: ", compus[i].velocidad, compus[i].anio);
        puts(compus[i].tipo_cpu);
        printf(" - Cantidad nucleos: %d", compus[i].cantidad);

    }
    

}

void mostrarVieja(compu *compus)
{

    int aux = 2024, vieja = 0;

    for (int i = 0; i < TAMA; i++)
    {
        
        if (compus[i].anio < aux)
        {
            aux = compus[i].anio;
            vieja = i;
        }
        
    }
    
    printf("\n\nPC MAS VIEJA: PC %d\n", vieja+1);
    printf("Velocidad: %d - Anio: %d - Tipo CPU: ", compus[vieja].velocidad, compus[vieja].anio);
    puts(compus[vieja].tipo_cpu);
    printf(" - Cantidad nucleos: %d", compus[vieja].cantidad);

}

void mostrarMasRapida(compu *compus)
{

    int aux = 1, rapida = 0;

    for (int i = 0; i < TAMA; i++)
    {
        
        if (compus[i].velocidad > aux)
        {
            aux = compus[i].velocidad;
            rapida = i;
        }
        
    }
    
    printf("\n\nPC MAS RAPIDA: PC %d\n", rapida+1);
    printf("Velocidad: %d - Anio: %d - Tipo CPU: ", compus[rapida].velocidad, compus[rapida].anio);
    puts(compus[rapida].tipo_cpu);
    printf(" - Cantidad nucleos: %d", compus[rapida].cantidad);

}

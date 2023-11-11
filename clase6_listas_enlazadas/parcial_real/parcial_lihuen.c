#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct alumno {
    int legajo;
    char nombre[32];
    int edad;
    int grupo;
    char final_aprobado[3];
    struct alumno *next;
} Alumno;

void insertar_alumno(Alumno **head_r, int legajo, char *nombre, int edad, int grupo, char *final_aprobado) {
    Alumno *alumno = malloc(sizeof(Alumno));
    alumno->legajo = legajo;
    alumno->edad = edad;
    alumno->grupo = grupo;
    strcpy(alumno->nombre, nombre);
    strcpy(alumno->final_aprobado, final_aprobado);
    alumno->next = *head_r;
    *head_r = alumno;
}

void cargar_alumnos(Alumno **head_r) {
    int legajo, edad, grupo;

    printf("Cargar alumno (ingrese legajo 0 para finalizar)\n");
    printf("Legajo: ");
    scanf("%d", &legajo);

    while (legajo != 0) {
        char nombre[32], final_aprobado[3];

        printf("Nombre: ");
        scanf("%s", nombre);

        printf("Edad (mayor a 17): ");
        scanf("%d", &edad);
        while (edad < 18) {
            printf("ERROR - La edad debe ser mayor a 17\n");
            printf("Edad (mayor a 17): ");
            scanf("%d", &edad);
        }

        printf("Grupo de investigacion (1, 2, 3): ");
        scanf("%d", &grupo);
        while (grupo < 1 || grupo > 3) {
            printf("ERROR - Ingrese una opcion valida\n");
            printf("Grupo de investigacion (1, 2, 3): ");
            scanf("%d", &grupo);
        }
        
        printf("Final de Introduccion Aprobado (si, no): ");
        scanf("%s", final_aprobado);
        while (strcmp(final_aprobado, "si") && strcmp(final_aprobado, "no")) {
            printf("ERROR - Ingrese una opcion valida\n");
            printf("Final de Introduccion Aprobado (si, no): ");
            scanf("%s", final_aprobado);
        }

        insertar_alumno(head_r, legajo, nombre, edad, grupo, final_aprobado);

        // siguiente alumno
        printf("Cargar alumno\n");
        printf("Legajo: ");
        scanf("%d", &legajo);
    }

    printf("Fin de ingreso de datos\n");
}

void mostrar_alumnos(Alumno *head) {
    Alumno *alumno = head;
    if (alumno == NULL) {
        printf("No hay alumnos\n");
        return;
    }
    printf("Legajo\tNombre\tEdad\tGrupo\tAprobado\n");
    while (alumno) {
        printf("%d\t%s\t%d\t%d\t%s\n", alumno->legajo, alumno->nombre, alumno->edad, alumno->grupo, alumno->final_aprobado);
        alumno = alumno->next;
    }
}

Alumno* crear_alumnos_desaprob_g3(Alumno *head) {
    Alumno *desaprob_g3 = NULL;
    Alumno *alumno = head;

    while (alumno) {
        char final_aprobado[3];
        strcpy(alumno->final_aprobado, final_aprobado);
        if (alumno->grupo == 3 && strcmp(final_aprobado, "no")) {
            insertar_alumno(&desaprob_g3, alumno->legajo, alumno->nombre, alumno->edad, 3, "no");
        }
        alumno = alumno->next;
    }

    return desaprob_g3;
}

void eliminar_alumno(Alumno **head_r, int legajo) {
    Alumno *alumno = *head_r, *prev = NULL;

    if (alumno == NULL) {
        printf("No hay alumnos\n");
        return;
    }

    while (alumno) {
        Alumno *next = alumno->next;

        if (alumno->legajo == legajo) {
            if (prev == NULL) {
                *head_r = next;
            } else {
                prev->next = next;
            }
            free(alumno);
            printf("Alumno eliminado\n");
            return;
        }
        
        prev = alumno;
        alumno = alumno->next;
    }

    printf("No se encontro el alumno\n");
}

void promedio_25_30(Alumno *head) {
    Alumno *alumno = head;
    int acc = 0, cant = 0;

    while (alumno) {
        if (alumno->edad >= 25 || alumno->edad <= 30) {
            acc += alumno->edad;
            cant++;
        }
        alumno = alumno->next;
    }

    if (cant > 0) {
        int promedio = acc / cant;
        printf("El promedio de edad es %d\n", promedio);
    } else {
        printf("No se encontraron alumnos entre 25 y 30 años\n");
    }
}

void insertar_pepe(Alumno **head_r, int legajo) {
    Alumno *alumno = *head_r, *prev = NULL;

    while (alumno) {
        Alumno *next = alumno->next;

        if (alumno->legajo == legajo) {
            Alumno *pepe = malloc(sizeof(Alumno));
            pepe->legajo = 9999;
            pepe->edad = 99;
            pepe->grupo = 1;
            pepe->next = alumno;
            strcpy(pepe->nombre, "PEPE");
            strcpy(pepe->final_aprobado, "si");

            if (prev == NULL) {
                *head_r = pepe;
            } else {
                prev->next = pepe;
            }

            printf("Elemento insertado\n");
            return;
        }

        prev = alumno;
        alumno = next;
    }

    printf("No se encontro el alumno\n");
}

int main() {
    Alumno *alumnos = NULL;

    int opcion;
    do {
        printf("[0] Finalizar\n");
        printf("[1] Cargar alumnos\n");
        printf("[2] Mostrar alumnos\n");
        printf("[3] Mostrar alumnos que no aprobaron el final y estan en grupo 3\n");
        printf("[4] Promedio de edad entre 25 y 30\n");
        printf("[5] Eliminar estudiante\n");
        printf("[6] Insertar PEPE\n");

        scanf("%d", &opcion);

        if (opcion == 1) {
            cargar_alumnos(&alumnos);
        }
        else if (opcion == 2) {
            mostrar_alumnos(alumnos);
        }
        else if (opcion == 3) {
            Alumno *alumnos_desaprob_g3 = crear_alumnos_desaprob_g3(alumnos);
            mostrar_alumnos(alumnos_desaprob_g3);
        }
        else if (opcion == 4) {
            promedio_25_30(alumnos);
        }
        else if (opcion == 5) {
            int legajo;
            printf("Numero de legajo: ");
            scanf("%d", &legajo);
            eliminar_alumno(&alumnos, legajo);
        }
        else if (opcion == 6) {
            int legajo;
            printf("Numero de legajo: ");
            scanf("%d", &legajo);
            insertar_pepe(&alumnos, legajo);
        }
    } while (opcion != 0);
}
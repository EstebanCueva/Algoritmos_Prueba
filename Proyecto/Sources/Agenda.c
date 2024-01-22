#include "Agenda.h"
#include <stdio.h>
#include <string.h>
#include <time.h>

void obtenerFechaActual(char fechaActual[]) {
  time_t tiempoActual;
  struct tm *infoTiempo;

  time(&tiempoActual);
  infoTiempo = localtime(&tiempoActual);

  strftime(fechaActual, MAX_FECHA, "%d/%m/%Y", infoTiempo);
}

void guardarCitas(struct Cita citas[], int numCitas) {
  FILE *archivo = fopen(NOMBRE_ARCHIVO, "w");

  if (archivo == NULL) {
    printf("Error al abrir el archivo para escritura.\n");
    return;
  }

  for (int i = 0; i < numCitas; i++) {
    fprintf(archivo, "%s %s\n", citas[i].nombre, citas[i].fecha);
  }

  fclose(archivo);
}

void cargarCitas(struct Cita citas[], int *numCitas) {
  FILE *archivo = fopen(NOMBRE_ARCHIVO, "r");

  if (archivo == NULL) {
    printf("No se encontró el archivo de citas. Creando uno nuevo.\n");
    return;
  }

  while ((*numCitas < MAX_CITAS) &&
         fscanf(archivo, "%s %s", citas[*numCitas].nombre,
                citas[*numCitas].fecha) == 2) {
    (*numCitas)++;
  }

  fclose(archivo);
}

void agregarCita(struct Cita citas[], int *numCitas) {
  if (*numCitas < MAX_CITAS) {
    printf("Ingrese el nombre del paciente: ");
    scanf("%s", citas[*numCitas].nombre);

    char fechaActual[MAX_FECHA];
    obtenerFechaActual(fechaActual);
    printf("Fecha actual: %s\n", fechaActual);

    printf("Ingrese la fecha de la cita (DD/MM/YYYY): ");
    scanf("%s", citas[*numCitas].fecha);

    if (strcmp(citas[*numCitas].fecha, fechaActual) < 0) {
      printf("Error: No se puede agendar una cita en una fecha pasada.\n");
      return;
    }

    (*numCitas)++;
    guardarCitas(citas, *numCitas);
    printf("Cita agendada con éxito.\n");
  } else {
    printf("Ya se alcanzó el límite de citas.\n");
  }
}

void mostrarCitas(struct Cita citas[], int numCitas) {
  printf("\nLista de Citas Agendadas:\n");
  for (int i = 0; i < numCitas; i++) {
    printf("Cita %d:\n", i + 1);
    printf("Nombre: %s\n", citas[i].nombre);
    printf("Fecha: %s\n", citas[i].fecha);
    printf("------------------------\n");
  }
}

void buscarCitasPorMes(struct Cita citas[], int numCitas) {
  char mes[3];
  printf("Ingrese el mes a buscar (MM): ");
  scanf("%s", mes);

  printf("\nCitas agendadas para el mes %s:\n", mes);
  for (int i = 0; i < numCitas; i++) {

    if (strncmp(citas[i].fecha + 3, mes, 2) == 0) {
      printf("Cita %d:\n", i + 1);
      printf("Nombre: %s\n", citas[i].nombre);
      printf("Fecha: %s\n", citas[i].fecha);
      printf("------------------------\n");
    }
  }
}

void eliminarCita(struct Cita citas[], int *numCitas, int posicion) {
  if (posicion < 1 || posicion > *numCitas) {
    printf("Error: Posición de cita no válida.\n");
    return;
  }

  for (int i = posicion - 1; i < *numCitas - 1; i++) {
    strcpy(citas[i].nombre, citas[i + 1].nombre);
    strcpy(citas[i].fecha, citas[i + 1].fecha);
  }

  (*numCitas)--;
  guardarCitas(citas, *numCitas);
  printf("Cita eliminada con éxito.\n");
}

void modificarCita(struct Cita citas[], int numCitas, int posicion) {
  if (posicion < 1 || posicion > numCitas) {
    printf("Error: Posición de cita no válida.\n");
    return;
  }

  printf("Ingrese el nuevo nombre del paciente: ");
  scanf("%s", citas[posicion - 1].nombre);

  printf("Ingrese la nueva fecha de la cita (DD/MM/YYYY): ");
  scanf("%s", citas[posicion - 1].fecha);

  guardarCitas(citas, numCitas);
  printf("Cita modificada con éxito.\n");
}

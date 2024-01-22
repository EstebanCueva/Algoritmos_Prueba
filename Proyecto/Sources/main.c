#include "Agenda.h"
#include <stdio.h>

int main() {
  struct Cita citas[MAX_CITAS];
  int numCitas = 0;
  int opcion;
  int posicion;

  cargarCitas(citas, &numCitas);

  do {
    printf("\nMenú:\n");
    printf("1. Agendar cita\n");
    printf("2. Mostrar citas agendadas\n");
    printf("3. Buscar citas por mes\n");
    printf("4. Eliminar cita\n");
    printf("5. Modificar cita\n");
    printf("6. Salir\n");
    printf("Seleccione una opción: ");
    scanf("%d", &opcion);

    switch (opcion) {
    case 1:
      agregarCita(citas, &numCitas);
      break;
    case 2:
      mostrarCitas(citas, numCitas);
      break;
    case 3:
      buscarCitasPorMes(citas, numCitas);
      break;
    case 4:
      printf("Ingrese la posición de la cita a eliminar: ");
      scanf("%d", &posicion);
      eliminarCita(citas, &numCitas, posicion);
      break;
    case 5:
      printf("Ingrese la posición de la cita a modificar: ");
      scanf("%d", &posicion);
      modificarCita(citas, numCitas, posicion);
      break;
    case 6:
      printf("Saliendo del programa.\n");
      break;
    default:
      printf("Opción no válida. Por favor, seleccione una opción válida.\n");
    }
  } while (opcion != 6);

  return 0;
}

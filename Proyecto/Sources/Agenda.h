#define MAX_CITAS 10
#define MAX_NOMBRE 50
#define MAX_FECHA 20
#define NOMBRE_ARCHIVO "citas.txt"

struct Cita {
  char nombre[MAX_NOMBRE];
  char fecha[MAX_FECHA];
};

void guardarCitas(struct Cita citas[], int numCitas);
void cargarCitas(struct Cita citas[], int *numCitas);
void agregarCita(struct Cita citas[], int *numCitas);
void mostrarCitas(struct Cita citas[], int numCitas);
void buscarCitasPorMes(struct Cita citas[], int numCitas);
void eliminarCita(struct Cita citas[], int *numCitas, int posicion);
void modificarCita(struct Cita citas[], int numCitas, int posicion);

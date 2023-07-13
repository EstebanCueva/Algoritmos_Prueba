#include <stdio.h>
#include <string.h>

#define MAX_INTENTOS 3
#define MAX_MESA2 30
#define MAX_MESA4 25
#define MAX_MESA6 20

int main() {
    char usuario1[] = "Admin";
    char contrasena1[] = "Admin";

    char usuario2[] = "usuario2";
    char contrasena2[] = "contrasena2";

    char usuario3[] = "usuario3";
    char contrasena3[] = "contrasena3";

    int intentos_restantes = MAX_INTENTOS;
    int usuario_valido = 0;

    while (!usuario_valido && intentos_restantes > 0) {
        char usuario[20];
        char contrasena[20];

        printf("Ingrese el usuario: ");
        scanf("%s", usuario);

        printf("Ingrese la contrasena: ");
        scanf("%s", contrasena);

        if (strcmp(usuario, usuario1) == 0 && strcmp(contrasena, contrasena1) == 0) {
            usuario_valido = 1;
        } 
        
        if (!usuario_valido) {
            printf("Usuario o contrasena incorrecto (Intento %d)\n", MAX_INTENTOS - intentos_restantes + 1);
            intentos_restantes--;
        }
    }

    if (usuario_valido) {
        printf("Inicio de sesion exitoso\n");
    } else {
        printf("Ha excedido el numero maximo de intentos\n");
        return 0;
    }

    int opcion,opcion2;
    int opcion3;
    int mesa;
    int tipomesa,TotaldeMesas2=0,TotaldeComensales=0,TotaldeMesas4=0,TotaldeMesas6=0;
    int Cmesa2=0,Cmesa4=0,Cmesa6=0;
    
    do
    {
        printf("MENU\n");
        printf("1. Reserva de Mesas\n");
        printf("2. Estadísticas de Reservas\n");
        printf("3. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ha seleccionado la opcion: Reserva de Mesas\n");
                do
                {
                    printf("----- MENU -----\n");
                    printf("1. Mesa para 2\n");
                    printf("2. Mesa para 4\n");
                    printf("3. Mesa para 6\n");
                    printf("4. Salir\n");
                    printf("Ingrese una opción: ");
                    scanf("%d", &opcion2);
                    switch (opcion2)
                    {
                    case 1:
                        int opcion4;

                        if (Cmesa2>=30)
                        {
                            printf("Se ha superado el limite de mesas\n");
                            break;
                        }
                          
                        do {
                        printf("Ingrese el numero de mesas ha reservar: ");
                        scanf("%d", &tipomesa);
                        if (tipomesa <= 0)
                        {
                            printf("Ha selecionado un valor invalido");
                            break;
                        }
                        
                        if (tipomesa > MAX_MESA2) {
                            printf("Error: El numero de mesas excede el maximo permitido.\n");
                            break;
                        }
                        printf("Mesas reservadas con exito!\n");
                        
                        if (tipomesa<=1 && tipomesa == 0 )
                        {
                            TotaldeMesas2=tipomesa;
                        }
                        else{
                            TotaldeMesas2=tipomesa+tipomesa;
                        }
                        
                        Cmesa2=Cmesa2+tipomesa;
                        if (Cmesa2>=30)
                        {
                            TotaldeMesas2=30;
                            printf("Error: El numero de mesas excede el maximo permitido.\n");
                            break;
                        }

                        printf("Si desdea continuar reservando seleccione 1 y 2 para Salir\n");
                        scanf("%d", &opcion4);

                        } while (opcion4 !=2);
                        

                        break;
                    case 2:

                        int opcion5;
                        if (Cmesa4>=25)
                        {
                            printf("Se ha superado el limite de mesas\n");
                            break;
                        }
                          
                        do {
                        printf("Ingrese el numero de mesas ha reservar: ");
                        scanf("%d", &tipomesa);
                        if (tipomesa <= 0)
                        {
                            printf("Ha selecionado un valor invalido");
                            break;
                        }
                        if (tipomesa > MAX_MESA4) {
                            printf("Error: El numero de mesas excede el maximo permitido.\n");
                            break;
                        }
                        printf("Mesas reservadas con exito!\n");
                        Cmesa4=Cmesa4+tipomesa;
                        if (Cmesa4>=25)
                        {
                            printf("Error: El numero de mesas excede el maximo permitido.\n");
                            TotaldeMesas4=25;
                            break;
                        }
                        if (tipomesa<=1 && tipomesa == 0 )
                        {
                            TotaldeMesas4=tipomesa;
                        }
                        else{
                            TotaldeMesas4=tipomesa+tipomesa;
                        }
                        
                        printf("Si desdea continuar reservando seleccione 1 y 2 para Salir\n");
                        scanf("%d", &opcion5);

                        } while (opcion5 !=2);
                        

                        
                        break;
                    case 3:
                        
                        int opcion6;
                        if (Cmesa6>=20)
                        {
                            printf("Se ha superado el limite de mesas\n");
                            break;
                        }
                          
                        do {
                        printf("Ingrese el número de mesas ha reservar: ");
                        scanf("%d", &tipomesa);
                        if (tipomesa <= 0)
                        {
                            printf("Ha selecionado un valor invalido");
                            break;
                        }
                        
                        if (tipomesa > MAX_MESA6) {
                            printf("Error: El numero de mesas excede el maximo permitido.\n");
                            break;
                        }
                        printf("Mesas reservadas con exito!\n");
                        Cmesa6=Cmesa6+tipomesa;

                        if (Cmesa4>=20)
                        {
                            printf("Error: El numero de mesas excede el maximo permitido.\n");
                            TotaldeMesas6=20;
                            break;
                        }

                        if (tipomesa<=1 && tipomesa == 0 )
                        {
                            TotaldeMesas6=tipomesa;
                        }
                        else{
                            TotaldeMesas6=tipomesa+tipomesa;
                        }
                        
                        printf("Si desdea continuar reservando seleccione 1 y 2 para Salir\n");
                        scanf("%d", &opcion6);

                        } while (opcion6 !=2);
                        

                        break;
                
                    default:

                        printf("Opcion Invalida Intentelo denuevo");
                        break;
                    }
                 
                } while (opcion2 !=4);
            
                            
                break;
            case 2:
                printf("Ha seleccionado la opcion: Estadisticas de Ventas\n");
                
                printf("Total de mesas para 2 reservadas:%d \n",TotaldeMesas2);
                printf("Total de mesas para 4 reservadas:%d \n",TotaldeMesas4);
                printf("Total de mesas para 6 reservadas:%d \n",TotaldeMesas6);

                if (TotaldeMesas2==0)
                {
                    TotaldeMesas2 == 0;
                }
                if (TotaldeMesas4==0)
                {
                    TotaldeMesas4 == 0;
                }
                if (TotaldeMesas6==0)
                {
                    TotaldeMesas6 == 0;
                }

                TotaldeComensales=((TotaldeMesas2*2)+(TotaldeMesas4*4)+(TotaldeMesas6*6));
                printf("Total de Comensales ha asistir :%d \n",TotaldeComensales);
                break;
            
            case 3:

                printf("Ha seleccionado la opcion: Salir\n");
                return 0;
            default:
                printf("Opcion Invalida\n");
                break;
        }

    } while (opcion !=3);


    
}

    
    



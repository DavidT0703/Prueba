#include <iostream> 
using namespace std;

// Programa para resolver el problema de las carreras

int main()
{
    // Primero hay que definir las variables de entrada, las de salida
    // y las auxiliares
    // Las variables de entrada son el nÃºmero de carreras, la distancia de la primera y cuanto crece la distancia
    // Definir carreras como entero
    // Definir distancia_inicial, crecimiento como reales
    // La variable de salida es la distancia total recorrida
    // Definir distancia_recorrida como real
    // Necesitamos un par de variables auxiliares: una para controlar el ciclo y otra para ir actualizando la distancia de cada carrera
    // Definir x como entero
    // Definir distancia como real

    int carreras, x;
    float distancia_inicial, crecimiento, distancia_recorrida, distancia;
    carreras = 0;

    // Lo primero que hay que hacer es pedirle al usuario las variables de entrada
    // Del pseudocÃ³digo cambiamos los escribir por cout y los leer por cin porque estamos usando pantalla y teclado
    while (carreras<=0){
        cout << "Cuantas carreras se recorrieron?";
        cin >> carreras;
    }
    cout << "Cual fue su distancia inicial?";
    cin >> distancia_inicial;
    if(carreras != 1){
        cout << "Cuanto va a crecer?";
        cin >> crecimiento;
    }
    // Se debe verificar si es una carrera o son varias
    // Del pseudocÃ³digo cambiamos el Si por if
    if (carreras==1)
    {
        // Si solamente es una carrera no hay razÃ³n para ciclarse
        distancia_recorrida=distancia_inicial;
    }
    else  // Del pseudocÃ³digo cambiamos el sino por else
    {
        // Si son varias carreras entonces si tenemos que acumular la distancia de cada una
        // Por lo que hay que inicializar la distancia recorrida y la variable que indica la distancia de cada carrera
        distancia_recorrida=0;
        distancia=distancia_inicial;

        // Del pseudocÃ³digo cambiamos el Para por for
        // Para todas las carreras, se avanza de uno en uno
        for (x=1; x <= carreras; x=x+1) 
        {
            // Se acumula la distancia de cada carrera
            distancia_recorrida = distancia_recorrida + distancia;
            // Se actualiza la distancia a recorrer para la siguiente carrera
            distancia=distancia*crecimiento;
        }       
    }
    // Se despliega la variable de salida
    cout << "La distancia final recorrida es:" << distancia_recorrida;

}
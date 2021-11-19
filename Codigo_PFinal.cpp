#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*Una tienda departamental quiere calcular las ventas totales que tiene al mes,
para esto debe saber cuanto han vendido cada uno de sus empleados, además debe 
pagarles su comision a cada uno de los empleados, su comision siempre es el 15% de sus ventas
pero si sus ventas fueron mayores(o iguales) a 1000 reciben 100 extras, y si fueron mayores(o iguales) a 2000
reciben 250, el que haya tenido más ventas se lleva 500 extra. Para administrar más facil la informacion
los empleados tienen un id unico que se guarda en un arreglo junto a sus ventas y comision, en EXCEL.
No sabemos la canitdad de empleados.*/

int main(){
    string nombre;
    double ventas;
    double mayor_venta;
    string mayor_vendedor;
    double ventas_totales; //acumulador
    double comision;
    int id;
    int i; //contador
    double comision_total; //acumulador
    double subtotal;
    double ganancias_finales;
    string usuario; //validación de datos
    string clave; //validacion de datos
    int num_empleados;

    cout<<"INICIO DE SESION\n";
    cout<<"-----------------------\n";
    cout<<"Usuario:          ";
    cin>>usuario;
    cout<<"\n";
    cout<<"Clave:       ";
    cin>>clave;
    cout<<"\n";
    cout<<"Cuantos empleados tiene?\n";
    cin>>num_empleados;
    string arr[num_empleados][4]; //vectores

    cout<<"REGISTRO DE EMPLEADOS Y COMISIONES\n";
    cout<<"----------------------\n";
    ventas_totales = 0;
    comision_total = 0;
    mayor_venta = 0;
    mayor_vendedor = "";

    for (i=1; i<=num_empleados; i++){
        cout<<"Escriba su nombre\n";
        cin>>nombre;
        id = i-1; //inicia en 0 termina en num_empleados-1
        arr[id][0] = nombre;
        arr[id][1] = to_string(id);
        cout<<"Cuanto vendio en el mes?\n";
        cin>>ventas;
        ventas_totales = ventas_totales + ventas;
        arr[id][2] = to_string(ventas);
        if (ventas > mayor_venta){
            mayor_venta = ventas;
            mayor_vendedor = nombre;
        }
        if (ventas >= 2000){
            comision = ventas * 0.15 + 250;
            comision_total = comision_total + comision;
        }
        else{
            if (ventas >= 1000){
                comision = ventas * 0.15 + 100;
                comision_total = comision_total + comision;
            }
            else{
                comision = ventas * 0.15;
                comision_total = comision_total + comision;
            }
        }
        arr[id][3] = to_string(comision);
        cout<<"La comision de " + nombre + " es de " + to_string(comision) + " pesos.\n";
        cout<<"--------------------------------------\n";
    }
    cout<<"En total se han vendido " + to_string(ventas_totales) + " pesos.\n";
    cout<<"El empleado con mas ventas fue " + mayor_vendedor + ". el recibe 500 pesos extras.\n";
    cout<<"--------------------------------------------------\n";
    std::ofstream file("database.csv", std::ofstream::out);
    for(int filas=0; filas<=id; filas++){
        for(int columnas=0; columnas<=3; columnas++){
            if (columnas !=0){
                file<<",";
            }
            file<<arr[filas][columnas];
        }
        file<<"\n";
    }
    file.close();

    /*El dueño de la tienda quiere saber cuales serán sus ingresos tomando en cuenta el total de comisiones
    que debe pagar y el impuesto que debe pagar al gobierno, suponiendo que el impuesto es un 30% de las ventas
    cuales son las ganancias finales? IMPORTANTE: Solo el administrador/jefe debe verlo.*/
    
    if(clave == "SoyElJefe123"){
        if(usuario == "Jefazo"){
            cout<<"Acceso Permitido\n";
            cout<<"------------------------------------------\n";
            cout<<"GANANCIAS FINALES\n";
            subtotal = ventas_totales - comision_total - 500;
            cout<<"Subtotal:          " + to_string(subtotal) + ".\n";
            cout<<"Impuesto:          " + to_string(ventas_totales*0.3) + ".\n";
            ganancias_finales = subtotal - ventas_totales*0.3;
            cout<<"TOTAL:             " + to_string(ganancias_finales) + ".\n";
        }
        else{
            cout<<"Acceso denegado, información clasificada.\n";
        }
    }
    else{
        cout<<"Acceso denegado, informacion clasificada.\n";
    }
}

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

struct Cliente { //estructura que será usada para ingresar a los clientes nuevos 
    string nombre; //y asi poder usar varios datos
    string telefono;
    string correo;
};

// ===== FUNCIONES =====
void menu();
void registrarUsuario();
bool inicio();

void registrarVenta();      // 1
void gestionarInventario(); // 2

vector<string> nombreproducto;
vector<float> precioproducto;
vector<int> existenciaproducto;
int opcion;

do{
	cout<<"\n--- GESTION DE INVENTARIOS ---\n";
	cout<<"1. Agregar productos\n";
	cout<<"2. Actualizar productos\n";
	cout<<"3. Consultar inventario\n";
	cout<<"4. Regresar al menu\n";
	cout<<"Elija una opcion:";
	cin>>opcion;
	cin.ignore();

	switch (opcion)
		case 1:{
			cout<<"\n--- AGREGAR PRODUCTO ---\n";
			do{
			cout<<"1. Nuevo producto.\n";
			cout<<"2. Regresar al menu anterior.\n";
			switch (opcion){
				case 1:{
					string nombre
					float precio
					int existencia
				
					cout<<"Ingrese el nombre del producto\n";
					getline(cin, nombre);
					for (char &c:nombre){
						c=tolower(c);
					}
					
					cout<<"Ingrese el precio del producto\n";
					cin>>precio;
					
					cout<<"Ingrese la cantidad en existencia\n";
					cin>>existencia;
					cin.ignore();

					nombreproducto.push_back(nombre);
					precioproducto.push_back(precio);
					existenciaproducto.push_back(existencia);

					cout<<"\n--- PRODUCTO AGREGADO ---\n";
					break;
				}
				case 2:
					cout<<"\nRegresando...\n";
					break;
				default:
					cout<<"Opcion invalida.\n";
					break;
			}
		} while (opcion!=2);
		break;
	}
		case 2:{
			if (nombreproducto.empty()){
				cout<<"No hay productos registrados.\n";
				break;
			}
			do {
				cout<<"1. Actualizar producto.\n";
				cout<<"2. Regresar al menu anterior.\n";
				switch (opcion){
					case 1:{
						string buscarprod
						cout<<"\n--- ACTUALIZAR PRODUCTOS ---\n";
						cout<<"Ingrese el nombre del producto a buscar.\n";
						cin>>buscarprod;
						for (char &c:nombre){
							c=tolower(c);
							}
						bool encontrar=false;
						for (size_t i=0; i<nombreproducto.size();i++){
							if (nombreproducto[i]==buscarprod){
								encontrar=true;
							}
						}
							
						}
					}
				}
				
			}
			}

void gestionarClientes() {  // 4
	int opcion;
    Cliente cliente; //se usa la estructura creada
    fstream archivo; // para leer y escribir el archivo de clientes

    do { //bucle while para las opciones de clientes
        cout << "\n--- MENU CLIENTES FRECUENTES ---\n";
        cout << "1. Registrar nuevo cliente\n";
        cout << "2. Mostrar lista de clientes\n";
        cout << "3. Regresar al menu\n"; //se muestran las opciones disponibles
        cout << "Elija una opcion: ";
        cin >> opcion;
        cin.ignore(); // limpia el buffer de entrada

        switch (opcion) { //se elige la opción en base a la opcion elegida
        case 1: {
            // Abrir archivo en modo agregar
            archivo.open("clientes.txt", ios::app); //se usa ios::app para poder agregar la informacion al final
            if (!archivo) { //se verifica que el archivo se pueda abrir
                cout << "Error al abrir el archivo.\n";
                break;
            }
			//se piden los datos y se guardan en la estructura
            cout << "\n--- Registro de nuevo cliente ---\n";
            cout << "Ingrese el nombre: ";
            getline(cin, cliente.nombre);
            cout << "Ingrese el telefono: ";
            getline(cin, cliente.telefono);
            cout << "Ingrese el correo electronico: ";
            getline(cin, cliente.correo);

            // Guardar en el archivo los datos obtenidos
            archivo << cliente.nombre << "|" << cliente.telefono << "|" << cliente.correo << endl;
            archivo.close();

            cout << "Cliente registrado correctamente.\n";
            break;
        }

        case 2: {
            archivo.open("clientes.txt", ios::in); //se abre el archivo en modo lectura
            if (!archivo) { //verificar que el archivo sea válido
                cout << "No hay clientes registrados o no se pudo abrir el archivo.\n";
                break;
            }

            cout << "\n--- Lista de clientes ---\n";
            string linea;
            while (getline(archivo, linea)) {
                // Cada línea tiene formato: nombre|telefono|correo
                size_t p1 = linea.find("|"); //se usa size_t para poder encontrar la posición del separador
                size_t p2 = linea.find("|", p1 + 1);

                string nombre = linea.substr(0, p1); //se usa substr para poder sacar solo la información de cada dato
                string telefono = linea.substr(p1 + 1, p2 - p1 - 1);
                string correo = linea.substr(p2 + 1);

                cout << "Nombre: " << nombre << endl; //se imprime los datos extraídos anteriormente
                cout << "Telefono: " << telefono << endl;
                cout << "Correo: " << correo << endl;
                cout << "--------------------------\n"; //se hace un separador para cada cliente
            }

            archivo.close(); //se cierra el archivo
            break;
        }

        case 3:
            cout << "Saliendo de la gestion de clientes...\n"; //mensaje de salida
            break;

        default:
            cout << "Opcion no valida.\n"; //si el usuario ingresa una opcón inválida
            break;
        }
    } while (opcion != 3); //se sale del bucle si se selecciona opción 3

};  
void facturar();            // 5
void generarReportes();     // 6
void enviarPromociones();   // 7

// ===== VALIDACION PARA ACCEDER =====
int main() {
    cout << "=== SISTEMA DE PUNTO DE VENTA ===\n";

    if (inicio()) {
        menu();
    } else {
        cout << "Inicio de sesion incorrecto.\n";
    }
    return 0;
}

// ===== Registro de Usuario =====
void registrarUsuario() {
    string usuario, contrasena;
    ofstream archivo("usuarios.txt", ios::app);

    cout << "\n--- REGISTRAR USUARIO ---\n";
    cout << "Usuario: ";
    cin >> usuario;
    cout << "Contrasena: ";
    cin >> contrasena;

    archivo << usuario << " " << contrasena << endl;
    archivo.close();

    cout << "Usuario guardado correctamente.\n";
}

// ===== INICIO DE SESION =====
bool inicio() {
    string usuario, contrasena, u, c;
    ifstream archivo("usuarios.txt");

    if (!archivo.is_open()) {
        cout << "\nNo hay usuarios registrados. Debe crear uno primero.\n";
        registrarUsuario();
        archivo.open("usuarios.txt");
    }

    cout << "\n--- INICIO DE SESION ---\n";
    cout << "Usuario: ";
    cin >> usuario;
    cout << "Contrasena: ";
    cin >> contrasena;

    while (archivo >> u >> c) {
        if (u == usuario && c == contrasena) {
            cout << "\nBienvenido, " << usuario << "!\n";
            archivo.close();
            return true;
        }
    }

    archivo.close();
    return false;
}

// ===== MENU =====
void menu() {
    int opcion;
    do {
        cout << "\n===== MENU PRINCIPAL =====\n";
        cout << "1. Registrar Venta\n";
        cout << "2. Gestionar Inventario\n";
        cout << "3. Registrar Usuario\n";
        cout << "4. Gestionar Clientes\n";
        cout << "5. Facturacion\n";
        cout << "6. Reportes\n";
        cout << "7. Promociones\n";
        cout << "8. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: registrarVenta(); break;
            case 2: gestionarInventario(); break;
            case 3: registrarUsuario(); break;
            case 4: gestionarClientes(); break;
            case 5: facturar(); break;
            case 6: generarReportes(); break;
            case 7: enviarPromociones(); break;
            case 8: cout << "Saliendo del sistema...\n"; break;
            default: cout << "Opcion no valida.\n"; break;
        }
    } while (opcion != 8);
}

// ===== FUNCIONES PENDIENTES A IMPLEMENTAR=====
void registrarVenta() {
    cout << "Funcion  pendiente por implementar";
}

void gestionarInventario() {
    cout << "Funcion  pendiente por implementar";
}

void gestionarClientes() {
    cout << "Funcion  pendiente por implementar";
}

void facturar() {
    cout << "Funcion  pendiente por implementar";
}

void generarReportes() {
    cout << "Funcion  pendiente por implementar";
}

void enviarPromociones() {
    cout << "Funcion  pendiente por implementar";
}

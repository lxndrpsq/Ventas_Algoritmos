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

void gestionarInventario(); 
void agregarProducto(vector<string>&, vector<float>&, vector<int>&);
void actualizarProducto(vector<string>&, vector<float>&, vector<int>&);
void consultarInventario(const vector<string>&, const vector<float>&, const vector<int>&);
void registrarVenta();

vector<string> nombreproducto; //Vector para guardar productos
vector<float> precioproducto; //Vector para guardar los precios
vector<int> existenciaproducto; //Vector para guardar las existencias

void gestionarInventario(){
int opcion;
do {
        cout << "\n--- GESTION DE INVENTARIOS ---\n";
        cout << "1. Agregar productos\n";
        cout << "2. Actualizar productos\n";
        cout << "3. Consultar inventario\n";
        cout << "4. Regresar al menu\n";
        cin >> opcion;
        cin.ignore(); //Limpiar buffer de entrada

        switch (opcion) {
            case 1: //AGREGAR PRODUCTOS
                 agregarProducto(nombreProducto, precioProducto, existenciaProducto);
				break;

        	case 2: //ACTUALIZAR PRODUCTOS
                actualizarProducto(nombreProducto, precioProducto, existenciaProducto);
				break;
			
            case 3: //CONSULTAR INVENTARIO
                consultarInventario(nombreProducto, precioProducto, existenciaProducto);
				break;

            case 4: //REGRESAR AL MENU
                cout << "\n--- REGRESANDO AL MENU PRINCIPAL ---\n";
                break;

            default: //Si se ingresa una opcion que no esta disponible
                cout << "\nOpcion invalida.\n";
                break;
        }
    } while (opcion != 4); //Repetir el ciclo hasta que el usuario lo detenga
}
				
void agregarProducto(vector<string>& nombres, vector<float>& precios, vector<int>& existencias) {
				int subopcion; //Variable temporal para registrar las opciones en agregar productos
                do {
                    cout << "\n--- AGREGAR PRODUCTO ---\n";
                    cout << "1. Nuevo producto.\n";
                    cout << "2. Regresar al menu anterior.\n";
                    cout << "Elija una opcion: ";
                    cin >> subopcion;
                    cin.ignore();

                    switch (subopcion) {
                        case 1: { //NUEVO PRODUCTO
                            string nombre; //Variable que registrara el nombre ingresado
                            float precio; //Variable que registrara el precio ingresado
                            int existencia; //Variable que registrara la existencia ingresada

                            cout << "Ingrese el nombre del producto: ";
                            getline(cin, nombre); //Obtiene la linea completa ingresada
                            for (char &c : nombre) c = tolower(c); //Convierte los caracteres ingresados en minusculas

                            cout << "Ingrese el precio del producto: ";
                            cin >> precio;
                            cout << "Ingrese la cantidad en existencia: ";
                            cin >> existencia;
                            cin.ignore();

               				nombres.push_back(nombre);
               				precios.push_back(precio);
                            existencias.push_back(existencia); //Agrega los datos ingresados al final del vector

                            cout << "\n--- PRODUCTO AGREGADO ---\n";
                            break;
                        }
                        case 2: //REGRESAR AL MENU ANTERIOR
                            cout << "\n--- REGRESANDO ---\n";
                            break;
                        default: //Si la opcion ingresada no esta disponible
                            cout << "Opcion invalida.\n";
                            break;
                    }
                } while (subopcion != 2); //Repetir el ciclo hasta que el usuario lo detenga
            }

void actualizarProducto(vector<string>& nombres, vector<float>& precios, vector<int>& existencias) {
				if (nombres.empty()) { //Si no hay ningun dato en el vector
                    cout << "No hay productos registrados.\n";
                    break;
                }

                int subopcion;
                do {
                    cout << "\n--- ACTUALIZAR PRODUCTOS ---\n";
                    cout << "1. Actualizar producto.\n";
                    cout << "2. Regresar al menu anterior.\n";
                    cout << "Elija una opcion: ";
                    cin >> subopcion;
                    cin.ignore();

                    switch (subopcion) {
                        case 1: { //ACTUALIZAR PRODUCTO
                            string buscarprod; //Variable que guardara el producto a buscar
                            cout << "Ingrese el nombre del producto a buscar: ";
                            getline(cin, buscarprod); //Registra la linea completa ingresada
                            for (char &c : buscarprod) c = tolower(c); //Convierte los caracteres ingresados a minusculas

                            bool encontrado = false; //Variable que verifica si el dato ingresado existe en el vector
                            for (size_t i = 0; i < nombres.size(); i++) { //Iteracion que buscara si el producto ingresado esta en el vector
                                if (nombres[i] == buscarprod) { //El producto ingresado es igual al producto existente en el vector
                                    encontrado = true; //Si se cumple, la variable sera verdadera

                                    cout << "\nProducto encontrado:\n";
                                    cout << "Producto: " << nombres[i] //Muestra el nombre del producto encontrado
                                         << "\nPrecio actual: " << precios[i] //Muestra el precio actual del producto
                                         << "\nExistencia actual: " << existencias[i] << endl; //Muestra la existencia actual del producto

                                    cout << "\n--- ACTUALIZAR ---\n";
                                    cout << "1. Precio\n";
                                    cout << "2. Existencia\n";
                                    cout << "3. Ambos\n";
                                    cin >> opcion;

                                    switch (opcion) {
                                        case 1: //ACTUALIZAR PRECIO
                                            cout << "Ingrese el nuevo precio: ";
                                            cin >> precios[i];
                                            cout << "Precio actualizado correctamente.\n";
                                            break;
                                        case 2: //ACTUALIZAR EXISTENCIA
                                            cout << "Ingrese la nueva cantidad en existencia: ";
                                            cin >> existencias[i];
                                            cout << "Existencia actualizada correctamente.\n";
                                            break;
                                        case 3: //ACTUALIZAR PRECIO Y EXISTENCIA
                                            cout << "Ingrese el nuevo precio: ";
                                            cin >> precios[i];
                                            cout << "Ingrese la nueva cantidad en existencia: ";
                                            cin >> existencias[i];
                                            cout << "Precio y existencia actualizados correctamente.\n";
                                            break;
                                        default: //Si se ingresa una opcion que no esta disponible
                                            cout << "Opcion invalida.\n";
                                            break;
                                    }
                                    break;
                                }
                            }

                            if (!encontrado) { //Si el producto ingresado no esta en el vector
                                cout << "\nProducto no encontrado.\n";
                            }
                            cin.ignore();
                            break;
                        }
                        case 2: //REGRESAR AL MENU ANTERIOR
                            cout << "\n--- REGRESANDO ---\n";
                            break;
                        default: //Si se ingresa una opcion que no esta disponible
                            cout << "Opcion invalida.\n";
                            break;
                    }
                } while (subopcion != 2); //Repetir el ciclo hasta que el usuario lo detenga
            }

void consultarInventario(const vector<string>& nombres, const vector<float>& precios, const vector<int>& existencias) {
				if (nombres.empty()) { //Si no hay datos en el vector
                    cout << "\n--- NO HAY PRODUCTOS EN EL INVENTARIO. ---\n";
                    break;
                }
                cout << "\n--- INVENTARIO ACTUAL ---\n";
                for (size_t i = 0; i < nombres.size(); i++) { //Iteracion que devuelve todos los datos registrados en el vector
                    cout << i + 1 << ". " << nombres[i]
                         << "Precio: Q" << precios[i]
                         << "Existencia: " << existencias[i] << endl;
                }
            }

void registrarVenta(){
	do{
    cout << "\nUsuario: ";
    getline(cin, usuario);
    cout << "Contraseña: ";
    getline(cin, contrasena);
		
		if (registrarUsuario(usuario, contrasena)){
			cout<<"\n--- BIENVENIDO ---\n';
				break;
		} else{
		cout<<"\n--- USUARIO/CONTRASENA INVALIDA ---\n";
	}
} while (true);
	vector<string> productoAVender;
    vector<int> unidadesAVender;
    vector<float> precioTotal;

    int opcion;
    string buscarProd;
    float total = 0.0;
    int unidades;

    cout << "\n--- REGISTRAR VENTA ---\n";

    while (true) {
        cout << "\n1. Agregar producto a la venta\n";
        cout << "2. Finalizar venta y mostrar total\n";
        cout << "3. Cancelar\n";
        cout << "Elija una opcion: ";
        cin >> opcion;
        cin.ignore();

        if (opcion == 1) {
            cout << "\nIngrese el nombre del producto: ";
            getline(cin, buscarProd);
            for (char &c : buscarProd) c = tolower(c);

            bool encontrado = false;
            for (size_t i = 0; i < nombreProducto.size(); i++) {
                if (nombreProducto[i] == buscarProd) {
                    encontrado = true;
                    cout << "Producto encontrado: " << nombreProducto[i]
                         << "\nPrecio: Q" << precioProducto[i]
                         << "\nExistencia: " << existenciaProducto[i] << endl;

                    cout << "Ingrese las unidades a vender: ";
                    cin >> unidades;
                    cin.ignore();

                    if (unidades > existenciaProducto[i]) {
                        cout << "\nNo hay suficientes unidades en inventario.\n";
                    } else {
                        existenciaProducto[i] -= unidades;
                        float subtotal = unidades * precioProducto[i];
                        total += subtotal;

                        productoAVender.push_back(nombreProducto[i]);
                        unidadesAVender.push_back(unidades);
                        precioTotal.push_back(subtotal);

                        cout << "Producto agregado a la venta.\n";
                    }
                    break;
                }
            }
            if (!encontrado) {
                cout << "\nProducto no encontrado.\n";
            }
        }
        else if (opcion == 2) {
            cout << "\n--- DETALLE DE VENTA ---\n";
            for (size_t i = 0; i < productoAVender.size(); i++) {
                cout << i + 1 << ". " << productoAVender[i]
                     << " | Unidades: " << unidadesAVender[i]
                     << " | Subtotal: Q" << precioTotal[i] << endl;
            }
            cout << "\nTOTAL A PAGAR: Q" << total << endl;
            cout << "\nInventario actualizado correctamente.\n";
            break;
        }
        else if (opcion == 3) {
            cout << "\nVenta cancelada.\n";
            break;
        }
        else {
            cout << "\nOpcion invalida.\n";
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

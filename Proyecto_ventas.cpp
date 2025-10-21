#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// ===== FUNCIONES =====
void menu();
void registrarUsuario();
bool inicio();

void registrarVenta();      // 1
void gestionarInventario(); // 2
void gestionarClientes();   // 4
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

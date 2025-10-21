#include <iostream>
#include "clases.h"
#include <limits>


// prototipos
void menu();

int main() {

    MatrizBase<int>* matrizA = nullptr;
    MatrizBase<int>* matrizB = nullptr;

    bool continuarEjecucion = true;

    int matricesCreadas = 0;

    int opcion;

    do{

        menu();

        std::cin >> opcion;

        if(std::cin.good()){

            switch (opcion)
            {
            case 1:

                if(matricesCreadas >= 2){
                    std::cout << "\n--- Error: Ya tienes definidas dos matrices. ---" << std::endl;
                }else{
                    if(matricesCreadas == 0) {
                        matrizA = new MatrizDinamica<int>();
                        matrizA->cargarValores();
                        std::cout << "\n--- Matriz A dinámica creada exitosamente ---" << std::endl;
                        matrizA->imprimir();
                    } else {
                        matrizB = new MatrizDinamica<int>();
                        matrizB->cargarValores();
                        std::cout << "\n--- Matriz B dinámica creada exitosamente ---" << std::endl;
                        matrizB->imprimir();
                    }
                    matricesCreadas++;
                }
                break;

            case 2:

                if(matricesCreadas >= 2){
                    std::cout << "\n--- Error: Ya tienes definidas dos matrices. ---" << std::endl;
                }else{
                    if(matricesCreadas == 0) {
                        matrizA = new MatrizEstatica<int, 5, 5>();
                        matrizA->cargarValores();
                        std::cout << "\n--- Matriz A estática creada exitosamente ---" << std::endl;
                        matrizA->imprimir();
                    } else {
                        matrizB = new MatrizEstatica<int, 5, 5>();
                        matrizB->cargarValores();
                        std::cout << "\n--- Matriz B estática creada exitosamente ---" << std::endl;
                        matrizB->imprimir();
                    }
                    matricesCreadas++;
                }
                break;

            case 3:

                if(matricesCreadas < 2){
                    std::cout << "\n--- Error: No tienes la cantidad suficiente de matrices para realizar la operación, tienes definidas: " << matricesCreadas << std::endl;
                } else {
                    std::cout << "\n--- Realizando suma de matrices ---" << std::endl;
                    MatrizBase<int>* resultado = matrizA->sumar(*matrizB);
                    std::cout << "\n--- Resultado de la suma ---" << std::endl;
                    resultado->imprimir();
                    delete resultado;
                }
                break;

            case 4:
                std::cout << "\n--- Gracias por utilizar este programa, desarrollado por Mauricio Rodríguez Manzur ---" << std::endl;
                continuarEjecucion = false;
                break;

            default:
                std::cout << "\n--- Error: Ingrese una opción válida ---" << std::endl;
                break;
            }

        }
        else{

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "\n--- Error: Ingrese una opción válida ---" << std::endl;

        }


    }while(continuarEjecucion);

    // Liberar memoria
    if(matrizA != nullptr) {
        delete matrizA;
    }
    if(matrizB != nullptr) {
        delete matrizB;
    }

    return 0;
}

void menu(){

    std::cout << "\n---- Bienvenido a MathSoft ----"<< std::endl;
    std::cout << "[1] Crear Matriz Dinamica"        << std::endl;
    std::cout << "[2] Crear Matriz Estatica"        << std::endl;
    std::cout << "[3] Suma de Matrices"             << std::endl;
    std::cout << "[4] Salir de la Aplicación\n\n"   << std::endl;

}
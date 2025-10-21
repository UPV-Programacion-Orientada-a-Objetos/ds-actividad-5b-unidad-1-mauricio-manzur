#include <iostream>

template <typename T>
class MatrizBase {

protected:
    int _filas;
    int _columnas;

public:
    // Constructor
    MatrizBase() : _filas(5), _columnas(5) {}
    
    // Método para obtener elemento (necesario para suma)
    virtual T obtenerElemento(int i, int j) const = 0;
    
    virtual void cargarValores() = 0;
    virtual MatrizBase<T>* sumar(const MatrizBase<T>& otra) const = 0;
    virtual void imprimir() const = 0;
    
    // Destructor virtual
    virtual ~MatrizBase() = default;
};

template <typename T>
class MatrizDinamica : public MatrizBase<T> {

private:
    T **_datos;

public:
    // Constructor
    MatrizDinamica() {
        this->_filas = 5;
        this->_columnas = 5;
        _datos = nullptr;
    }

    // Método para obtener elemento
    T obtenerElemento(int i, int j) const override {
        return _datos[i][j];
    }

    // sobreescribo los valores de la clase MatrizBase: cargarValores.
    void cargarValores() override {
        _datos = new T*[this->_filas];
        
        int contador = 1; // este valor solamente representa la cantidad que se le asignara a la posicion [i][j]
        
        for(int i = 0; i < this->_filas; i++){
            _datos[i] = new T[this->_columnas];
        }

        for(int i = 0; i < this->_filas; i++){
            for(int j = 0; j < this->_columnas; j++){
                _datos[i][j] = contador*2;
                contador++;
            }
        }
    }

    // sobreescribo los valores de la clase MatrizBase: imprimir.
    void imprimir() const override {
        std::cout << "******** Matriz Dinamica *********" << std::endl;
        for(int i = 0; i < this->_filas; i++){
            for(int j = 0; j < this->_columnas; j++){
                std::cout << _datos[i][j] << " | "; 
            }
            std::cout << std::endl;
        }
    }

    // sobreescribo los valores de la clase MatrizBase: suma
    MatrizBase<T>* sumar(const MatrizBase<T>& otra) const override {
        MatrizDinamica<T>* matrizResultante = new MatrizDinamica<T>();
        matrizResultante->cargarValores();
        
        for(int i = 0; i < this->_filas; i++){
            for(int j = 0; j < this->_columnas; j++){
                matrizResultante->_datos[i][j] = _datos[i][j] + otra.obtenerElemento(i, j);
            }
        }
        
        return matrizResultante;
    }

    // este es el destructor de la matriz dinamica.
    ~MatrizDinamica(){
        std::cout << "Eliminando Matriz Dinamica..." << std::endl;
        
        if(_datos != nullptr) {
            for(int i = 0; i < this->_filas; i++){
                delete[] _datos[i];
            }
            delete[] _datos;
        }
    }
};

template <typename T, int M, int N>
class MatrizEstatica : public MatrizBase<T> {

private:
    T _datos[M][N];

public:
    // Constructor
    MatrizEstatica() {
        this->_filas = M;
        this->_columnas = N;
    }

    // Método para obtener elemento
    T obtenerElemento(int i, int j) const override {
        return _datos[i][j];
    }

    void imprimir() const override {
        std::cout << "********* MATRIZ ESTATICA ********" << std::endl;
        for(int i = 0; i < this->_filas; i++){
            for(int j = 0; j< this->_columnas; j++){
                std::cout << _datos[i][j] << " | ";
            }
            std::cout << std::endl;
        }
    }

    MatrizBase<T>* sumar(const MatrizBase<T>& otra) const override {
        MatrizEstatica<T, M, N>* matrizResultante = new MatrizEstatica<T, M, N>();
        
        for(int i = 0; i < this->_filas; i++){
            for(int j = 0; j < this->_columnas; j++){
                matrizResultante->_datos[i][j] = _datos[i][j] + otra.obtenerElemento(i, j);
            }   
        }
        
        return matrizResultante;
    }

    void cargarValores() override {
        int contador = 1;
        
        for(int i = 0; i < this->_filas; i++){
            for(int j = 0; j < this->_columnas; j++){
                _datos[i][j] = contador * 2;
                contador++;
            }
        }
    }
};

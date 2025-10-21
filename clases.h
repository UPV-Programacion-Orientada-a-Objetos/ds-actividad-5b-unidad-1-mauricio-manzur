
template <typename T>
class MatrizBase {
protected:
    int _filas;
    int _columnas;

public:
    virtual void cargarValores() = 0;
    virtual MatrizBase<T>* sumar(const MatrizBase<T>& otra) const = 0;
    virtual void imprimir() const = 0;
};

template <typename T>
class MatrizDinamica : public MatrizBase<T> {


    T **_datos;

    // sobreescribo los valores de la clase MatrizBase: cargarValores.
    void cargarValores() override{

        

    }

    // sobreescribo los valores de la clase MatrizBase: imprimir.
    void imprimir() override{

        for(int i = 0; i < _filas; i++){

            for(int j = 0; j < _columnas; j++){

                std::cout << "******** Matriz Dinamica *********" << std::endl;
                std::cout << _datos[i][j] << " | "; 

            }

            std::cout << std::endl;

        }

    }

    // sobreescribo los valores de la clase MatrizBase: suma
    MatrizBase<T>* sumar(const MatrizBase<T>& otra) override{

        MatrizBase<T>* matrizResultante = new MatrizBase<T>[_filas][_columnas];

        for(int i = 0; i < _filas; i++){

            for(int j = 0; j< _columnas; j++){

                matrizResultante[i][j] = _datos[i][j] + otra[i][j];

            }

        }

        return matrizResultante;


    }


    // este es el destructor de la matriz dinamica.
    ~MatrizBase{

        for(int i = 0; i < _filas; i++){

            delete[] _datos[i];

        }

        delete[] _datos;

    }

};

template <typename T, int M, int N>
class MatrizEstatica : public MatrizBase<T> {

    T _datos[M][N];

    void imprimir() override{

        for(int i = 0; i < _filas; i++){

            for(int j = 0; j<_columnas; j++){

                std::cout << "********* MATRIZ ESTATICA ********" << std::endl;
                std::cout << _datos[i][j] << " | ";

            }

            std::cout << std::endl;

        }

    }

    MatrizBase<T>* sumar(const MatrizBase<T>& otra) override{

        MatrizBase<T> matrizResultante = new MatrizBase<T>[_filas][_columnas];

        for(int i = 0; i < _filas; i++){

            for(int j = 0; j < _columnas; j++){

                matrizResultante[i][j] = _datos[i][j] + otra[i][j];

            }   

        }

        return matrizResultante;

    }

    void cargarValores() override{

        

    }



};
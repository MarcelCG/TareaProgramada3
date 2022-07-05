#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>

using namespace std;

class Producto
{

    int idProducto;          // 4
    int existenciasProducto; // 4
    string nombreProducto; // 12 = 4 + 4 + 12 = 20

public:
    Producto(int idProducto, int existenciasProducto, string nombreProducto);
    Producto();

    int getIdProducto();
    int getExistenciasProducto();
    string getNombreProducto();

    bool VerificaNombreProductoMenorA20(Producto *nuevoProducto);

    void setExistenciasProducto(int existenciasProducto);
    void setNombreProducto(string nombreProducto);


    friend ostream &operator<<(ostream &o, const Producto *producto);
};

#endif
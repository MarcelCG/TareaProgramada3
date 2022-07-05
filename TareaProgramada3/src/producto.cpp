#include "producto.h"
#include <iostream>
#include <stdio.h>
#include <string.h>

Producto::Producto(int idProducto, int existenciasProducto, string nombreProducto)
{
    this->idProducto = idProducto;
    this->existenciasProducto = existenciasProducto;
    this->nombreProducto = nombreProducto;
}

Producto::Producto()
{
    this->idProducto = 0;
    this->existenciasProducto = 0;
    this->nombreProducto, "";
}

bool Producto::VerificaNombreProductoMenorA20(Producto *nuevoProducto)
{
        bool resultado = false;
        if (nuevoProducto->getNombreProducto().size() <= 20)
        {
              resultado = true;
        }
        return resultado;
}

int Producto::getIdProducto()
{
    return idProducto;
}
int Producto::getExistenciasProducto()
{
    return existenciasProducto;
}
string Producto::getNombreProducto()
{
    return nombreProducto;
}

void Producto::setExistenciasProducto(int existenciasProducto)
{
    this->existenciasProducto = existenciasProducto;
}
void Producto::setNombreProducto(string nombreProducto)
{
    this->nombreProducto = nombreProducto;
}

ostream &operator<<(ostream &o, const Producto *producto)
{
    o << "[" << producto->idProducto << "] - " << producto->existenciasProducto << " " << producto->nombreProducto;
    return o;
}
#include "tienda.h"
#include "producto.h"

#include <vector>
#include <iostream>
#include <stdio.h>
#include <string.h>

Tienda::Tienda(string nombreTienda, string direccionInternet, string direccionFisica, string telefono)
{
    this->nombreTienda = nombreTienda;
    this->direccionInternet = direccionInternet;
    this->direccionFisica = direccionFisica;
    this->telefono = telefono;
}

Tienda::Tienda()
{
    this->nombreTienda, "";
    this->direccionInternet, "";
    this->direccionFisica, "";
    this->telefono, "";
}

Tienda::~Tienda()
{
    for (Producto *producto : this->productos)
    {
        delete producto;
    }
}

void Tienda::AgregarProducto(Producto *nuevoProducto)
{
    this->productos.push_back(nuevoProducto);
}

void Tienda::EliminarProducto(Producto *productoEliminar)

{
    int contador = 0;
    for (Producto *producto : this->productos)
    {
        if (producto->getIdProducto() == productoEliminar->getIdProducto())
        {
            productos.erase(productos.begin() + contador);
            return;
        }
        contador++;
    }
}

vector<Producto *> Tienda::ConsultarProductos()
{
    return productos;
}

void Tienda::ModificarProducto(Producto *productoModificar)
{
    for (Producto *producto : this->productos)
    {
        if (producto->getIdProducto() == productoModificar->getIdProducto())
        {
            producto->setExistenciasProducto(productoModificar->getExistenciasProducto());
            producto->setNombreProducto(productoModificar->getNombreProducto());
            return;
        }
    }
}

bool Tienda::VerificaNombreTiendaMenor15(Tienda *nuevaTienda)
{
    bool resultado = false;
    if (nuevaTienda->getNombreTienda().size() <= 15)
    {
        resultado = true;
    }
    return resultado;
}
bool Tienda::VerificaDireccionInternetMenor24(Tienda *nuevaTienda)
{
    bool resultado = false;
    if (nuevaTienda->getDireccionInternet().size() <= 24)
    {
        resultado = true;
    }
    return resultado;
}
bool Tienda::VerificaDireccionFisicaMenor24(Tienda *nuevaTienda)
{
    bool resultado = false;
    if (nuevaTienda->getDireccionFisica().size() <= 24)
    {
        resultado = true;
    }
    return resultado;
}
bool Tienda::VerificaTelefonoMenor8(Tienda *nuevaTienda)
{
    bool resultado = false;
    if (nuevaTienda->getTelefono().size() <= 8)
    {
        resultado = true;
    }
    return resultado;
}
string Tienda::getNombreTienda()
{
    return nombreTienda;
}
string Tienda::getDireccionInternet()
{
    return direccionInternet;
}
string Tienda::getDireccionFisica()
{
    return direccionFisica;
}
string Tienda::getTelefono()
{
    return telefono;
}

void Tienda::GuardarEnStreamBinario(ostream *streamSalida)
{
    for (Producto *producto : this->productos)
    {
        streamSalida->write((char *)producto, sizeof(Producto));
    }
}

void Tienda::CargarProductoPorPosicionDesdeStreamBinario(istream *streamEntrada, int posicionProducto)
{
    streamEntrada->seekg(sizeof(Producto) * posicionProducto);

    Producto *producto = new Producto();
    streamEntrada->read((char *)producto, sizeof(Producto));

    this->AgregarProducto(producto);
}

void Tienda::CargarDesdeStreamBinario(istream *streamEntrada)
{
    // Calcule cantidad de registros
    streamEntrada->seekg(0, std::ios::end);
    int cantidadBytesEnArchivo = streamEntrada->tellg();
    int cantidadProductos = cantidadBytesEnArchivo / sizeof(Producto);

    // Leer cada empleado
    streamEntrada->seekg(0, std::ios::beg); // Empezar desde el principio del archivo
    for (int indice = 0; indice < cantidadProductos; indice++)
    {
        Producto *producto = new Producto();
        streamEntrada->read((char *)producto, sizeof(Producto)); // variable para guardar y cuántos bytes leo

        this->AgregarProducto(producto);
    }
}

ostream &operator<<(ostream &o, const Tienda *tienda)
{
    o << "Tienda: " << std::endl;

    for (Producto *producto : tienda->productos)
    {
        o << producto << endl;
    }

    return o;
}
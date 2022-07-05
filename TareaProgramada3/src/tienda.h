#ifndef TIENDA_H
#define TIENDA_H

#include <vector>
#include "producto.h"
#include <iostream>

using namespace std;

class Tienda
{
  string nombreTienda;
  string direccionInternet;
  string direccionFisica;
  string telefono;

  vector<Producto *> productos;

public:
  Tienda(string nombreTienda, string direccionInternet, string direccionFisica, string telefono);
  Tienda();
  ~Tienda();

  void AgregarProducto(Producto *nuevoProducto);
  void EliminarProducto(Producto *idProductoEliminar);
  vector<Producto *> ConsultarProductos();
  void ModificarProducto(Producto *productoModificar);

  bool VerificaNombreTiendaMenor15(Tienda *nuevaTienda);
  bool VerificaDireccionInternetMenor24(Tienda *nuevaTienda);
  bool VerificaDireccionFisicaMenor24(Tienda *nuevaTienda);
  bool VerificaTelefonoMenor8(Tienda *nuevaTienda);

  string getNombreTienda();
  string getDireccionInternet();
  string getDireccionFisica();
  string getTelefono();

  void GuardarEnStreamBinario(ostream *streamSalida);
  void CargarDesdeStreamBinario(istream *streamEntrada);
  void CargarProductoPorPosicionDesdeStreamBinario(istream *streamEntrada, int posicionProducto);

  friend ostream &operator<<(ostream &o, const Tienda *tienda);
};

#endif
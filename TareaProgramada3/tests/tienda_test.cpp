#include <gtest/gtest.h>
#include <string>
#include <fstream>
#include <sstream>

#include "./../src/tienda.h"
#include "./../src/producto.h"

using namespace std;

namespace
{
    TEST(Tienda_Test, Escribir_Leer_Archivo_Binario_Test)
    {
        /// AAA

        // Arrange - configurar el escenario
        Tienda *tiendaEsperada = new Tienda();

        Producto *producto1 = new Producto(8, 70, "Perfumes");
        tiendaEsperada->AgregarProducto(producto1);

        // Act - ejecute la operación
        // Escribir un archivo de prueba
        ofstream archivoSalida;
        archivoSalida.open("tienda_tests.dat", ios::out | ios::binary);
        if (!archivoSalida.is_open())
        {
            cerr << "No se pudo abrir archivo tienda_test.dat para escribir los datos";
            FAIL();
        }

        tiendaEsperada->GuardarEnStreamBinario(&archivoSalida);

        archivoSalida.close();

        // Leer el archivo de prueba
        ifstream archivoEntrada;
        archivoEntrada.open("tienda_tests.dat", ios::in | ios::binary);

        if (!archivoEntrada.is_open())
        {
            cerr << "No se pudo abrir archivo tienda_tests.dat para leer los datos";
            FAIL();
        }

        Tienda *tiendaLeida = new Tienda();
        tiendaLeida->CargarDesdeStreamBinario(&archivoEntrada);

        ostringstream streamSalidaTiendaLeida;
        streamSalidaTiendaLeida << tiendaLeida;

        ostringstream streamSalidaTiendaEsperada;
        streamSalidaTiendaEsperada << tiendaEsperada;

        // delete tiendaLeida;
        // delete tiendaEsperada;

        string esperado = "Tienda: \n[8] - 70 Perfumes\n";

        // Primero, validar la salida de la tienda esperada sea correcta
        EXPECT_EQ(esperado, streamSalidaTiendaEsperada.str());

        EXPECT_EQ(esperado, streamSalidaTiendaLeida.str());
    }

    TEST(Tienda_Test, Test_Verifica_Nombre_Producto_Menor_O_Igual_A_20_Caracteres)
    {
        bool esperado = true;
        bool resultado = false;
        Producto *producto1 = new Producto(4, 20, "Camisas");

        resultado = producto1->VerificaNombreProductoMenorA20(producto1);
        // Assert - valide los resultados
        EXPECT_EQ(esperado, resultado);
    }
    TEST(Tienda_Test, Test_Verifica_Nombre_Tienda_Menor_O_Igual_A_15_Caracteres)
    {
        bool esperado = true;
        bool resultado = false;
        Tienda *nuevaTienda = new Tienda("Tienda1", "Tienda1.com", "San Jose", "89024891");

        resultado = nuevaTienda->VerificaNombreTiendaMenor15(nuevaTienda);

        // Assert - valide los resultados
        EXPECT_EQ(esperado, resultado);
    }
    TEST(Tienda_Test, Test_Verifica_Direccion_Internet_Menor_O_Igual_A_24_Caracteres)
    {
        bool esperado = true;
        bool resultado = false;
        Tienda *nuevaTienda = new Tienda("Tienda1", "Tienda1.com", "San Jose", "89024891");

        resultado = nuevaTienda->VerificaDireccionInternetMenor24(nuevaTienda);

        // Assert - valide los resultados
        EXPECT_EQ(esperado, resultado);
    }
    TEST(Tienda_Test, Test_Verifica_Direccion_Fisica_Menor_O_Igual_A_24_Caracteres)
    {
        bool esperado = true;
        bool resultado = false;
        Tienda *nuevaTienda = new Tienda("Tienda1", "Tienda1.com", "San Jose", "89024891");

        resultado = nuevaTienda->VerificaDireccionFisicaMenor24(nuevaTienda);

        // Assert - valide los resultados
        EXPECT_EQ(esperado, resultado);
    }
    TEST(Tienda_Test, Test_Verifica_Telefono_Menor_O_Igual_A_8_Caracteres)
    {
        bool esperado = true;
        bool resultado = false;
        Tienda *nuevaTienda = new Tienda("Tienda1", "Tienda1.com", "San Jose", "89024891");

        resultado = nuevaTienda->VerificaTelefonoMenor8(nuevaTienda);

        // Assert - valide los resultados
        EXPECT_EQ(esperado, resultado);
    }
    TEST(Tienda_Test, Test_Eliminar_Producto)
    {
        /// AAA

        // Arrange - configurar el escenario
        Tienda *tiendaEsperada = new Tienda();

        Producto *producto1 = new Producto(4, 20, "Camisas");
        tiendaEsperada->AgregarProducto(producto1);
        tiendaEsperada->EliminarProducto(producto1);
        ostringstream streamTiendaActualizada;
        streamTiendaActualizada << tiendaEsperada;

        string esperado = "Tienda: \n";

        // Assert - valide los resultados
        EXPECT_EQ(esperado, streamTiendaActualizada.str());
    }
    TEST(Tienda_Test, Test_Modificar_Producto)
    {
        /// AAA

        // Arrange - configurar el escenario
        Tienda *tiendaEsperada = new Tienda();

        Producto *producto1 = new Producto(4, 20, "Camisas");
        Producto *producto2 = new Producto(4, 30, "Pantalones");

        tiendaEsperada->AgregarProducto(producto1);
        cout << producto1 << endl;
        tiendaEsperada->ModificarProducto(producto2);
        ostringstream streamTiendaActualizada;
        streamTiendaActualizada << tiendaEsperada;

        string esperado = "Tienda: \n[4] - 30 Pantalones\n";

        // Assert - valide los resultados
        EXPECT_EQ(esperado, streamTiendaActualizada.str());
    }
    TEST(Tienda_Test, Test_Consultar_Productos)
    {
        /// AAA

        // Arrange - configurar el escenario
        Tienda *nuevaTienda = new Tienda();

        Producto *producto1 = new Producto(4, 20, "Camisas");
        Producto *producto2 = new Producto(6, 15, "Blusas");

        nuevaTienda->AgregarProducto(producto1);
        nuevaTienda->AgregarProducto(producto2);
        nuevaTienda->ConsultarProductos();
        ostringstream streamTiendaActual;
        streamTiendaActual << nuevaTienda;

        string esperado = "Tienda: \n[4] - 20 Camisas\n[6] - 15 Blusas\n";

        // Assert - valide los resultados
        EXPECT_EQ(esperado, streamTiendaActual.str());
    }
}
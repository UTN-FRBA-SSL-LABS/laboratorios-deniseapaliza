#include <stdio.h>
#include "carrito.h"

int main(void) {
    Carrito c; // creamos un struct Carrito en donde la cantidad es los productos actuales
    carrito_init(&c); // lo iniicializamos es decir ponemos su cantidad en 0 
    // defino 3 productos de los cuales
    Producto leche = {"Leche",   350, 2}; // 2 Cantidad de leche 
    Producto pan   = {"Pan",     200, 3}; // 3 cant de pan
    Producto queso = {"Queso", 1500, 1}; // 1 cant queso
// Excede la cantidad max de items, hay 6 

    carrito_agregar(&c, leche);// llamamos la fucnion y le pasamos el carrito y la leche
    carrito_agregar(&c, pan);
    carrito_agregar(&c, queso);

    printf("=== Carrito de compras ===\n\n");

    for (int i = 0; i < carrito_contar(&c); i++) {
        printf("  %-10s  x%d  $%d\n",
               c.items[i].nombre,
               c.items[i].cantidad,
               c.items[i].precio * c.items[i].cantidad);
    }

    printf("\n");
    printf("Total:             $%d\n", carrito_total(&c));
    printf("Con 10%% descuento: $%d\n", carrito_descuento(carrito_total(&c), 10));

    return 0;
}

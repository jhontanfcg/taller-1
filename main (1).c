#include <stdio.h>
#include <string.h>

int tieneDescuento(char *codigoProducto) {
    char *productosDescuento[] = {"8949899430", "7653512593", "9383867373", "88392904209"};
    int numProductos = sizeof(productosDescuento) / sizeof(productosDescuento[0]);

    for (int i = 0; i < numProductos; i++) {
        if (strcmp(codigoProducto, productosDescuento[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int puedeParticiparEnRifa(char *codigoProducto, char *codigoAlmacen) {
    char *codigosRifa[] = {"894985943020763", "165331255320221", "248386737320130", "183923092220561"};
    int numCodigos = sizeof(codigosRifa) / sizeof(codigosRifa[0]);

    char codigoConcatenado[20];
    strcpy(codigoConcatenado, codigoProducto);
    strcat(codigoConcatenado, codigoAlmacen);

    for (int i = 0; i < numCodigos; i++) {
        if (strcmp(codigoConcatenado, codigosRifa[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    char codigoProducto[11];
    char codigoAlmacen[6];

    printf("Ingrese el código de producto (10 dígitos alfanuméricos): ");
    scanf("%s", codigoProducto);

    printf("Ingrese el código de almacén (5 dígitos alfanuméricos, debe comenzar con '20'): ");
    scanf("%s", codigoAlmacen);

    if (strlen(codigoProducto) != 10 || strlen(codigoAlmacen) != 5 || strncmp(codigoAlmacen, "20", 2) != 0) {
        printf("Error: Códigos no válidos. Asegúrese de ingresar un código de producto de 10 dígitos y un código de almacén de 5 dígitos que comience con '20'.\n");
        return 1;
    }

    if (tieneDescuento(codigoProducto)) {
        printf("Su producto tiene un descuento del 20 por ciento.\n");
    } else {
        printf("Su producto no tiene descuento.\n");
    }

    if (puedeParticiparEnRifa(codigoProducto, codigoAlmacen)) {
        printf("¡Felicidades! Puede participar en la rifa del vehículo.\n");
    } else {
        printf("Lo sentimos, su producto no puede participar en la rifa del vehículo.\n");
    }

    return 0;
}

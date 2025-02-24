# 📌 Retroalimentación del Código

El código proporcionado por el estudiante es funcional y cumple con los requisitos del enunciado.  Imprime correctamente tres triángulos rectángulos basándose en la entrada del usuario. Sin embargo, hay algunas mejoras que se pueden implementar:

**Puntos Positivos:**

* **Funcionalidad correcta:** El código produce el resultado esperado.
* **Uso de funciones:** La función `imprimirTriangulo` promueve la modularidad y la reutilización del código.
* **Claridad y legibilidad:** El código es fácil de entender y seguir.


**Sugerencias de mejora:**

* **Validación de entrada:**  El enunciado especifica "enteros positivos". El código actual no valida si la entrada del usuario cumple con esta restricción.  Se debería agregar validación para asegurar que las alturas ingresadas sean mayores que cero.  Si no lo son, se debería mostrar un mensaje de error y posiblemente solicitar de nuevo la entrada.

* **Manejo de errores más robusto:**  Considerar qué sucede si la entrada no es un número.  El programa podría comportarse de manera inesperada.  Investigar sobre cómo manejar entradas inválidas (e.g., usando `cin.fail()` y `cin.clear()`) sería beneficioso.

* **Evitar `using namespace std;`:** Aunque simplifica el código al no requerir `std::` antes de elementos del espacio de nombres estándar, se considera una mala práctica, especialmente en proyectos más grandes, ya que puede llevar a colisiones de nombres.  Es preferible usar `std::cout`, `std::cin`, `std::endl`, etc. explícitamente.

* **Considerar un bucle para la entrada:** En lugar de pedir las tres alturas por separado, se podría usar un bucle para solicitar las alturas y simplificar el código en `main()`.


**Código mejorado:**

```cpp
#include <iostream>
#include <limits> // Para numeric_limits

void imprimirTriangulo(int altura) {
    for (int i = 1; i <= altura; i++) {
        for (int j = 1; j <= i; j++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}

int main() {
    int alturas[3];

    for (int i = 0; i < 3; ++i) {
        std::cout << "Ingrese la altura del triángulo " << i + 1 << ": ";
        std::cin >> alturas[i];

        while (std::cin.fail() || alturas[i] <= 0) {
            std::cout << "Entrada inválida. Ingrese un entero positivo: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> alturas[i];
        }
    }

    for (int altura : alturas) {
        imprimirTriangulo(altura);
    }

    return 0;
}
```

Este código mejorado incluye validación de entrada, maneja errores de entrada no numérica y utiliza un bucle para simplificar la solicitud de las alturas.  También evita `using namespace std;` para una mejor práctica.  Estos cambios hacen que el código sea más robusto y mantenible.

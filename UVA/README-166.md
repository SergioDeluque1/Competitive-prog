**UVa 166 -- Making Change**\
Lenguaje

- C++ (C++11)

- Compilación estándar con `g++` u otro compilador compatible.\
  \
  **Cómo correr el programa**

1.  Compilar:\
    \
    `g++ -std=c++11 -O2 -o making_change making_change.cpp`

<!-- -->

2.  Ejecutar:\
    \
    `./making_change`

<!-- -->

3.  **Formato de entrada**:

- Se ingresan **6 números enteros**, indicando la cantidad de monedas
  disponibles de cada denominación: `5, 10, 20, 50, 100, 200` centavos.

- Luego se ingresa la **cantidad objetivo** en formato `X.Y`
  (dólares.céntimos).

- Para terminar la entrada, ingresar **6 ceros** consecutivos.\
  **Ejemplo:**\
  \
  `1 2 3 4 1 0`\
  `3.75`\
  `0 0 0 0 0 0`\
  \
  **Descripción del algoritmo**

<!-- -->

- Se trata de un **problema de cambio de monedas con límite de cantidad
  por denominación**.

- Objetivo: **minimizar el número de monedas** para alcanzar un monto
  objetivo.\
  **Estrategia usada:**

1.  Se convierte la cantidad objetivo a **céntimos**.

2.  Se usa **programación dinámica (DP)** tipo knapsack acotado con
    **descomposición binaria**:

    - Cada cantidad de monedas se descompone en potencias de 2 para
      procesarlas eficientemente.

    - Para cada batch, se aplica la transición típica de **0/1
      knapsack**.

<!-- -->

1.  La respuesta final está en `dp[value]`:

    - Si sigue siendo infinito, imprimir `"impossible"`.

    - De lo contrario, imprimir el mínimo número de monedas.\
      **Mecanismo recursivo (DP)**

- Variable que determina el tamaño del problema: `v` = monto restante en
  centavos.

- **Caso trivial**: `dp[0] = 0` → 0 monedas para 0 centavos.

- **Relación de recurrencia**:\
  dp\[v\]=min(dp\[v\],dp\[v−k⋅ci \]+k)

<!-- -->

- `c_i` = valor de la moneda, `k` = número de monedas en el batch.

- La iteración se hace en orden decreciente para no reutilizar el mismo
  batch.\
  \
  **Calidad del código**

<!-- -->

- No se usan variables globales.

- **Cálculos constantes fuera de los bucles**.

- **Nombres de variables claros**: `avail`, `dp`, `value`.

- **Eficiencia** garantizada con descomposición binaria en DP.

- Entrada y salida optimizadas con `ios::sync_with_stdio(false)` y
  `cin.tie(nullptr)`.\

**UVa 990 -- Diving for Gold (C++ Program)**\
Descripción General\
Este programa resuelve el problema **UVa 990 -- Diving for Gold**. Un
buzo tiene un tiempo limitado `t` y un conjunto de tesoros bajo el agua,
cada uno con una **profundidad** y una **cantidad de oro**. El objetivo
es **maximizar la cantidad de oro** recolectada sin exceder el tiempo
disponible.\
El problema se modela como una variante del **0/1 Knapsack**, donde el
\"peso\" de cada ítem es el tiempo que toma recogerlo, calculado como:\
\
`tiempoNecesario = 3 * w * profundidad`\
\
**Lenguaje**

- C++

- Dependencias: `<iostream>`, `<vector>`, `<algorithm>`, `<cstring>`

- Compilación sugerida:\
  \
  `g++ -std=c++17 -O2 -o diving_for_gold diving_for_gold.cpp`\
  \
  **Cómo correrlo**

1.  Guardar el archivo como `diving_for_gold.cpp`.

2.  Compilar:\
    \
    `g++ -std=c++17 -O2 -o diving_for_gold diving_for_gold.cpp`

<!-- -->

3.  Ejecutar con entrada estándar o desde archivo:\
    \
    `./diving_for_gold < input.txt`

- Formato de entrada (como UVa 990):\
  \
  `t w`\
  `n`\
  `profundidad1 oro1`\
  `profundidad2 oro2`\
  `...`

<!-- -->

- Salida:

  - Oro máximo recolectado.

  - Cantidad de tesoros seleccionados.

  - Lista de tesoros seleccionados (profundidad y oro).\
    \
    **Descripción del Algoritmo**\
    Se utiliza **programación dinámica con memoización**:

1.  **Subproblema**: `resolver(idx, tiempoRestante)` → oro máximo
    recolectado considerando los tesoros desde `idx` hasta el final con
    `tiempoRestante`.

2.  **Decisión**:

- **Tomar el tesoro** actual (si el tiempo lo permite)

- **No tomarlo**

3.  **Relación de recurrencia**:\
    \
    `dp[idx][tiempoRestante] = max(`\
    `    resolver(idx + 1, tiempoRestante), // No tomar`\
    `    oro[idx] + resolver(idx + 1, tiempoRestante - tiempoNecesario) // Tomar`\
    `);`

<!-- -->

4.  **Caso base**:\
    \
    `if (idx == n || tiempoRestante <= 0) return 0;`

- No quedan tesoros o no queda tiempo.

5.  **Reconstrucción de la solución**: Se mantiene un arreglo
    `tomado[idx][tiempoRestante]` para saber si se tomó cada tesoro en
    la solución óptima.\
    \
    **Calidad del Código**

- Variables claras y semánticas (`resolver`, `tomado`,
  `reconstruirSolucion`).

- Evita cálculos repetidos dentro de ciclos.

- Uso mínimo de variables globales; solo DP y entradas.

- Memoización asegura eficiencia (`n <= 30, t <= 1000` según
  restricciones de UVa).\
  \
  **Mejoras Posibles**

<!-- -->

- Transformar la recursión en **DP iterativa** para evitar la pila de
  llamadas.

- Simplificar `calcularTiempo` a `3 * w * profundidad`.

- Usar `vector<vector<int>>` en lugar de arrays estáticos para mayor
  flexibilidad.

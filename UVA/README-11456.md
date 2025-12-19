**Solución al problema UVa 11456 -- Train Sorting**\
Este programa implementa una solución eficiente al problema **UVa 11456
-- Train Sorting**, que consiste en determinar la longitud máxima de un
ordenamiento posible de vagones en forma bitónica: primero creciente y
luego decreciente en términos del peso de los vagones.\
Por Sergio Delúquez y Emily Cardona\
\
**Compilación y ejecución**\
Requisitos

- Compilador C++11 o superior.\
  **Compilación**\
  \
  `g++ -std=gnu++17 -O2 -Wall main.cpp -o trainsorting`\
  **Ejecución**\
  \
  `./trainsorting`\
  **Formato de entrada (según UVa 11456)**\
  \
  `T                 # n``ú``mero de casos`\
  `N                 # n``ú``mero de vagones`\
  `w1 w2 ... wN      # pesos de los vagones en orden`\
  **Salida**\
  Para cada caso, una línea con la longitud máxima alcanzable mediante
  una secuencia primero creciente y luego decreciente.\
  \
  **Descripción del algoritmo**\
  El problema exige encontrar la **longest bitonic subsequence (LBS)**
  en el orden dado de los vagones. La solución se basa en combinar:

1.  **LIS comenzando en cada índice** (creciente hacia adelante).

2.  **LIS terminando en cada índice** (creciente hacia atrás), que
    equivale a la **LDS** en el arreglo original.\
    El resultado para cada posición `i` se define como:\
    \
    `LBS(i) = LIS_end[i] + LIS_start[i] - 1`\
    La respuesta es el máximo sobre todos los índices.\
    **1. Cálculo de LIS comenzando en `i` (O(N²))**\
    Se procesa el arreglo desde el final hacia el inicio. Relación:\
    \
    `LIS_start[i] = 1 + max( LIS_start[j] ) para j > i y a[j] > a[i]`\
    **2. Cálculo de LIS terminando en `i` mediante el arreglo invertido
    (O(N log N))**\
    Se invierte el arreglo y se aplica un LIS clásico usando *patience
    sorting*. Esto simula el comportamiento decreciente en el arreglo
    original.\
    \
    **Fundamento del método**\
    Una subsecuencia bitónica puede descomponerse siempre en:

- una subsecuencia creciente que llega a un punto pico `i`, y

- una subsecuencia decreciente que parte de ese mismo punto.\
  El algoritmo calcula ambas componentes de forma independiente y luego
  combina los resultados. Esto garantiza corrección, y la complejidad
  total es **O(N² + N log N)** por caso (dominado por el cálculo O(N²)),
  adecuado para los límites de UVa.\
  \
  **Detalles del diseño y calidad del código**

<!-- -->

- No se utilizan variables globales.

- No se repiten cálculos innecesarios dentro de bucles.

- Las variables y funciones tienen nombres descriptivos y coherentes con
  su propósito.

- El código está modularizado en dos funciones específicas:

  - `compute_LIS_start`

  - `compute_LIS_end`\
    Esto favorece claridad, mantenibilidad y alineación con buenas
    prácticas.\
    \
    Si deseas, puedo generar una explicación teórica más profunda,
    agregar ejemplos específicos del problema UVa 11456 o incluir
    diagramas del proceso.

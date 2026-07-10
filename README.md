_Este proyecto ha sido creado como parte del currículo de 42 por `jzaquina y marcaram`._


# Descripción

**push_swap** es un proyecto de desarrollo de algoritmos del currículo de la Escuela 42 cuyo objetivo es ordenar una pila de datos numéricos utilizando un conjunto limitado de operaciones mecánicas y un stack auxiliar.

A diferencia de las soluciones convencionales, este repositorio implementa un **enfoque adaptativo inteligente**. El programa analiza en tiempo de ejecución tanto el volumen de elementos como el **grado de desorden matemático** (`disorder`) de la entrada. Usando esta métrica, selecciona dinámicamente la estrategia de ordenamiento más eficiente (`simple`, `medium` o `complex`), minimizando la cantidad total de instrucciones generadas.

# Instrucciones

## Compilacion

Colocado en la carpeta del proyecto ( en el directorio donde esta el makefile )
```bash
make  # Compilar push_swap

make clean  # Eliminar archivos objeto

make fclean  # Eliminar archivos objeto y ejecutables

make re  # Reconstruir completamente el proyecto
```
## Ejecucion

El programa push_swap calcula y muestra por salida estándar la lista de instrucciones necesarias para ordenar la pila. Puede utilizarse bajo tres modalidades principales:

1. Pasar una lista de números o un string de números
Puedes pasar los enteros como argumentos separados o agrupados dentro de una cadena de texto entre comillas:

Argumentos separados:

```bash
./push_swap 2 1 3 6 5 8
```
String de números:

```bash
./push_swap "2 1 3 6 5 8"
```
2. Ejecución con una estrategia concreta (Adaptive por defecto)
El algoritmo utiliza por defecto un enfoque adaptive, seleccionando dinámicamente el mejor método de ordenación según el volumen del stack. Si deseas forzar o especificar una estrategia particular para pruebas de rendimiento, puedes usar la bandera --strategy:

```bash
./push_swap --adaptive 4 67 3 87 23 12
```
3. Ejecución con el módulo de Benchmark (bench)
Para evaluar la eficiencia exacta, la cantidad total de operaciones generadas y contrastar métricas, puedes invocar el modo integrado de benchmark mediante el parámetro --bench:
```bash
./push_swap --bench 4 67 3 87 23 12
```

## Comprobacion
Para verificar que las instrucciones generadas por push_swap ordenan correctamente la pila, puedes redirigir la salida hacia el programa verificador oficial (checker):

```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_OS $ARG
```
Si la secuencia de comandos es correcta y la pila queda perfectamente ordenada, el validador devolverá OK. De lo contrario, mostrará KO.

# Recursos

| Resource                                                                      | Description                                                                                                         |
| :---------------------------------------------------------------------------- | :------------------------------------------------------------------------------------------------------------------ |
| [Entender las operaciones](https://vscza.itch.io/push-swap)                   | Un minijuego interactivo que te permite familiarizarte con las operaciones lógicas de los stacks (sa, pb, ra, etc.) |
| [visualizar el comportamiento](https://push-swap-visualizer.vercel.app/)      | Aplicación web interactiva que muestra visualmente en tiempo real cómo se ordena una lista animada.                 |
| [Explicacion del Big O notation](https://www.youtube.com/watch?v=aR3UX2DjDXQ) | Recurso audiovisual detallado que explica qué es la notación Big O y cómo medir la eficiencia temporal y espacial.  |

# Algoritmos y Desiciones Tecnicas
El programa pre-procesa la entrada asignando índices simplificados (ft_assign_index) y calculando un coeficiente flotante de desorden (disorder). La estrategia adaptive evalúa estos parámetros usando la siguiente lógica:

```bash
if (total_numbers <= 5)
    *strat = 1; // Estrategia Simple
else if (disorder < 0.2)
    *strat = 1; // Estrategia Simple (Casi ordenado)
else if (disorder < 0.5)
    *strat = 2; // Estrategia Medium (Desorden moderado)
else
    *strat = 3; // Estrategia Complex (Desorden alto)
```

## Justificacion de Valores Limite ( umbrales )

- $total\_numbers \le 5$ o $disorder < 0.2$: Se asigna la Estrategia Simple. Si la lista es diminuta o se encuentra estructuralmente "casi ordenada", los algoritmos pesados generan operaciones redundantes. Un enfoque directo basado en búsquedas de mínimos ahorra movimientos.

- $disorder < 0.5$: Se asigna la Estrategia Medium. Para un desorden intermedio, se aplica un algoritmo estructurado por ventanas numéricas fijas que pre-ordena por proximidad lógica en el Stack B antes de retornar al A.

- $disorder \ge 0.5$: Se asigna la Estrategia Complex. Cuando los datos son masivos y caóticos, se delega el control a un método bit a bit determinista capaz de gestionar altas entropías sin disparar el peor caso.

## Técnicas Internas de cada caso
### Estrategia Simple (sort_simple.c)
- **Si el tamaño es 2**: Aplica un intercambio inmediato (sa).

- **Si el tamaño es 3**: Llama a una función dedicada de decisión directa (ft_sort_three).

- **Si es mayor (hasta 5 o con bajo desorden):** Busca mecánicamente el valor más bajo en el Stack A, calcula si es más rápido desplazarlo mediante rotaciones directas (ra) o inversas (rra) según su posición respecto a la mitad del tamaño total (size / 2), lo envía al Stack B y repite el bucle hasta dejar 3 elementos. Finalmente, devuelve ordenadamente todo al Stack A con pushes sucesivos (pa).

### Estrategia Medium (sort_medium.c)
- **Fase de empuje por Chunks:** Vacía el Stack A en el B dividiendo los elementos bajo un concepto de ventanas deslizantes indexadas. Si el elemento actual cumple con un umbral dinámico (pushed + 15), se envía a B y se rota (rb) para estructurar de manera óptima las secciones del stack.

- **Fase de retorno:** Busca recursivamente el elemento con el índice más alto en el Stack B. Usando una estrategia de coste de distancia (pos <= size / 2), rota el stack de forma eficiente con rb o rrb hasta posicionarlo en el tope y devolverlo a A ya ordenado.

### Estrategia Complex (sort_complex.c)
- Implementa un ordenamiento Radix basado en la representación binaria de los índices.

- Primero calcula la cantidad máxima de dígitos binarios necesarios (ft_get_max_bits).

- Ejecuta un ciclo externo bit por bit. En cada iteración, analiza mediante operaciones a nivel de bits (>> y & 1) si el bit evaluado del elemento en el tope de A es un 1 (en cuyo caso realiza un ra manteniéndolo en A) o un 0 (lo envía temporalmente a B mediante pb). Tras procesar la pila completa, vacía secuencialmente B de regreso a A para pasar al siguiente bit.

## Breve analisis de Complejidad

[Gráfico de Complejidad Algoritmica](https://www.desmos.com/calculator/cztxhv7gu7)

- Complejidad Espacial: $\mathcal{O}(N)$. La memoria asignada de forma dinámica crece linealmente en relación directa al número de elementos enteros $N$ introducidos en los Stacks.

- Complejidad Temporal:
  - Estrategia Simple (Extraccion del minimo): $\mathcal{O}(N^2)$ en el peor de los casos debido al bucle anidado de búsqueda de mínimos, pero altamente eficiente en instrucciones reales para colecciones pequeñas.

  - Estrategia Medium (Algoritmo de la Ventana Deslizante): $\mathcal{O}(N\sqrt{N})$ al usar ventanas de chunks dinamicas.

  - Estrategia Complex ( Radix Sort Canónico en Binario): $\mathcal{O}(N log N)$: el algortimo Radix, tradicionalmente es de complejidad $\mathcal{O}(N \odot K)$ siendo $K$ la cantidad de bits significativos del número más grande.

    Pero dado que  se indexo el stack, los índices van estrictamente de 0 a n - 1, el valor de max_bits depende única y exclusivamente del tamaño del stack (n).Dado que max_bits $\mathcal{O}(log N)$, el total de operaciones del código sigue la función: $\mathcal{O}(n\cdot \log _{2}n)$


## Contribuciones Jzaquina
- Implementación y optimización de las operaciones lógicas de rotación completa: ra, rb, rr.

- Implementación y optimización de las operaciones de rotación inversa: rra, rrb, rrr.

- Testing y búsqueda  de fugas de memoria o errores de segmentación.

- Documentación técnica y confección del presente archivo README.md.

## Contribuciones Marcaram
- Implementación de las operaciones básicas de intercambio: sa, sb, ss.

- Implementación de las operaciones de transferencia entre pilas: pa, pb.

- Arquitectura principal y lógica central de todos los demás archivos fuente del proyecto (manejo de memoria, parseo de argumentos y algoritmos de ordenación).

- Corrección global de errores lógicos, depuración avanzada y refactorización del código hacia estándares de la Norma de 42.


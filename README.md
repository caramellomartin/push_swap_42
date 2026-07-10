*Este proyecto ha sido creado como parte del currículo de 42 por marcaram y jzaquina*

## Descripción

El objetivo de este proyecto es ordenar datos en un stack, utilizando un conjunto limitado de instrucciones y con el menor número posible de acciones. El programa `push_swap` calcula y muestra la secuencia de operaciones necesarias para ordenar una lista de valores enteros en orden ascendente.

Este proyecto implementa un motor adaptativo que analiza el nivel de caos/desorden de la entrada para seleccionar dinámicamente la estrategia matemática más eficiente.

**Contribuciones del equipo:**
* **marcaram:**
* **jzaquina:**

## Instrucciones de Compilación y Uso
El proyecto incluye un `Makefile` que compila el código fuente a la salida requerida con las flags `-Wall`, `-Werror` y `-Wextra`.

Para compilar el ejecutable, simplemente ejecutá:
`make`

Para ejecutar el programa, pasale el stack 'a' como argumentos separados o como un único string:
`./push_swap 4 67 3 87 23`
`./push_swap "4 67 3 87 23"`

**Modo Benchmark y Selectores:**
El programa acepta la flag `--bench` para mostrar las métricas de rendimiento en la salida de errores (stderr). También admite selectores manuales de estrategia:
* `--simple`
* `--medium`
* `--complex`
* `--adaptive` (por defecto)

## Justificación y Análisis de Algoritmos
En este proyecto, la complejidad se mide estrictamente en función del número de operaciones de Push_swap producidas, y no en la complejidad teórica tradicional sobre arrays.

Antes de ordenar, calculamos el **Índice de Desorden** (un número entre 0 y 1). En base a este índice, nuestra estrategia adaptativa selecciona el método más adecuado:

**1. Algoritmo Simple (Complejidad O(n^2))**
* **Uso:** Índice de desorden < 0.2 o listas minúsculas (<= 5 elementos).
* **Justificación:** Al estar la lista casi ordenada, las rotaciones son mínimas. Las operaciones impresas escalan de forma lineal, cumpliendo el objetivo del régimen de bajo desorden.

**2. Algoritmo Intermedio (Complejidad O(n√n))**
* **Uso:** Índice de desorden entre 0.2 y 0.5.
* **Justificación:** Para un caos moderado y listas de tamaño medio, agrupar elementos en la pila B por rangos (Chunks Sort) reduce drásticamente el costo de búsqueda al devolverlos, manteniendo un excelente rendimiento.

**3. Algoritmo Complejo (Complejidad O(n log n))**
* **Uso:** Índice de desorden >= 0.5
* **Justificación:** Proporciona una complejidad temporal estable (Radix en base binaria). Sin importar qué tan aleatoria o invertida esté la entrada, el costo siempre se mantendrá consistente y predecible.

## Recursos e Inteligencia Artificial
**Uso de IA:**
Se utilizaron herramientas de Inteligencia Artificial como apoyo metodológico para:
* Revisar la lógica del parser de entrada para asegurar una correcta gestión de memoria.
* Identificar y corregir errores de formato para cumplir con las normas de la escuela.
* Se utilizó para generar pruebas y encontrar bugs críticos.

**Referencias:**
* Documentación oficial: `man malloc`, `man free`, `man write`.

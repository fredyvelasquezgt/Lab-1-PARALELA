# Laboratorio 1

## Autores

- Alejandro Gomez (Alecraft)
- Diego Perdomo (Momi)
- Fredy Velasquez (Fredo)


## Instrucciones de Compilación y Ejecución 🛠️

A continuación, se detallan las instrucciones para compilar y ejecutar programas secuenciales y paralelos con OpenMP.

**Compilación y Ejecución de Programas Secuenciales**

Para compilar y ejecutar un programa secuencial:

1. Abre una terminal en la ubicación de los archivos.
2. Compila el programa secuencial con el siguiente comando:

```
gcc -o nombre_del_ejecutable_sequential nombre_del_archivo_sequential.c -lm
```


3. Una vez compilado, ejecuta el programa con:

```
./nombre_del_ejecutable_sequential
```


**Compilación y Ejecución de Programas Paralelos con OpenMP**

Para compilar y ejecutar un programa paralelo utilizando OpenMP:

1. Abre una terminal en la ubicación de los archivos.
2. Compila el programa paralelo con el siguiente comando:

```
gcc -o nombre_del_ejecutable_parallel nombre_del_archivo_parallel.c -fopenmp -lm
```


3. Una vez compilado, ejecuta el programa paralelo con:

```
./nombre_del_ejecutable_parallel
```


Recuerda asegurarte de tener instalado el compilador GCC y las bibliotecas OpenMP para compilar y ejecutar los programas paralelos correctamente.

Si deseas eliminar los archivos compilados, puedes usar:

```
make clean
```


¡Disfruta experimentando con la compilación y ejecución secuencial y paralela en tus programas! 🚀

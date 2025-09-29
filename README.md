# CPU Scheduling Algorithms

Este proyecto implementa algoritmos clásicos de planificación de CPU en C++:

- **FCFS (First Come, First Served)**
- **SJF (Shortest Job First)**
- **RR (Round Robin)**
- **STCF (Shortest Time to Completion First)**

---

## Contenido del repositorio

- Archivos fuente en C++ (`.cpp` y `.h`)
- Archivos de entrada:
  - `entrada1.txt`
  - `entrada2.txt`
  - `entrada3.txt`
- Archivo `Dockerfile`
- Este `README.md`

---

## Construcción de la imagen

Para compilar el proyecto y crear la imagen de Docker:

```bash
docker build -t cpu-schedulers .
```

## Ejecución del simulador
1. Crear y ejecutar el contenedor

```bash
docker run --name cpu-sched-run cpu-schedulers
```

Esto compilará y ejecutará el simulador, generando archivos de salida dentro del contenedor:

- `salida_fcfs.txt`
- `salida_sjf.txt`
- `salida_rr.txt`
- `salida_stcf.txt`

2. Copiar resultados
   
```bash
docker cp cpu-sched-run:/home/japeto/app/salida_fcfs.txt ./salida_fcfs.txt
docker cp cpu-sched-run:/home/japeto/app/salida_sjf.txt ./salida_sjf.txt
docker cp cpu-sched-run:/home/japeto/app/salida_rr.txt ./salida_rr.txt
docker cp cpu-sched-run:/home/japeto/app/salida_stcf.txt ./salida_stcf.txt
```
3. Eliminar el contenedor

```bash
docker rm cpu-sched-run
```

## Notas

- El contenedor se basa en la imagen japeto/so-tools:v64





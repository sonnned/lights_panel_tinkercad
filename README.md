# Información
## Tres ramas
1. main (SOLO ENVIAR CAMBIOS CUANDO TODOS ACEPTEN LOS **MERGE**)
2. informe (SOLO USAR PARA MODIFICAR EL INFORME)
3. tinkercad (SOLO USAR PARA MODIFICAR LAS **SIMULACIONES TINKERCAD**)

## Ver ramas
Lista todas las ramas
```bash
git branch -a
```
## Cambiar rama
```bash
git checkout <nombre_rama>
```
## Traer cambios de otra rama
```bash
git pull origin <rama_actual>
```
## Pasos para guardar/subir cambios
```bash
git status # ver cambios
git add <cambio> # stage cambio
git commit -m "mensaje" # commit cambio
git push origin <rama> # push cambio
```
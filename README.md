[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/gQNOY0_7)
# :slot_machine: Casino de Gon$ino | Polimorfismo :slot_machine:
> Ejercicio de un casino en el que se practican conocimientos relacionados con herencia, sobreescritura, polimorfismo y calidad de código.

El casino de Gon$ino es un casino en el que las personas pueden jugar diferentes juegos de azar. 
:moneybag: La moneda de este casino son los Gonzos.  **$10 000 pesos** equivalen a **100** gonzos. 

Cada jugador tienen una identificación, un nombre y saldo en Gonzos.
Un casino tiene **jugadores** y **juegos disponibles**.

****************

# ▶️ Contenidos
1. [Funcionalidades Principales](#principales)
    1. [Ingresar al Casino](#p1)
    2. [Jugar](#p2)
    3. [Convertir Pesos a Gonzos](#p3)
    4. [Otras Funcionalidades](#p4)
2. [Juegos Existentes](#juegos)
    1. [El Mayor de 13](#13)
    2. [Dos Colores](#colores)
3. [Requerimientos No Funcionales](#reqnofun)
4. [Ejercicio](#parcial)
    1. [Preguntas teóricas](#teoria)
    2. [Ajustes](#ajus)


****************

# 🤑 FUNCIONALIDADES PRINCIPALES <a name="principales"></a>

### ♠️  1. Ingresar al Casino <a name="p1"></a> 
Cuando entra al casino un usuario, el sistema debe preguntar el nombre, el identificador y el dinero en pesos. El sistema valida que el dinero en pesos sea mayor a 0. 
El sistema agrega el jugador al casino y calcula automáticamente la cantidad de Gonzos a los que equivale el dinero del usuario. 

### ♦️  2. Jugar  <a name="p2"></a> 
1.	Antes de iniciar a jugar el sistema le pregunta al jugador su identificación. El jugador debe existir en el sistema, sino existe le muestra un error al usuario.
2.	El sistema debe preguntar cuántos Gonzos desea apostar el usuario. El sistema debe validar que el jugador tenga la cantidad suficiente de Gonzos para apostar, si no los tiene, entonces el sistema debe avisar al usuario que debe ajustar el valor de su apuesta. 
3.	El sistema debe preguntar al usuario cuál de los juegos desea jugar.
4.	El usuario selecciona el juego y el sistema verifica que el juego exista. 
5.	Si el juego existe el sistema inicia el juego. Si no, el sistema muestra un error que indica que no existe. 
6.	Una vez que el usuario termina de jugar, el sistema debe mostrar si el jugador ganó o perdió, cuánto Gonzos ganó o perdió y a cuánto dinero equivalen esos Gonzos. Además, el sistema le debe preguntar al usuario si desea jugar de nuevo. Si el usuario desea jugar entonces el sistema continúa con el paso 2. 
7.	El sistema debe llevar la cuenta de cuántas veces ha jugado el jugador. Se cuenta por cada vez que juega, es decir, si por ejemplo tiró el dado 3 veces en el juego 2, entonces jugó 3 veces.

### ♣️  3. Convertir Pesos a Gonzos <a name="p3"></a> 
* El casino calcula a cuantos Gonzos equivale cierta cantidad de pesos y también es capaz de calcular a cuántos pesos equivalen cierta cantidad de Gonzos. 

### ♥️  4. Otras Funcionalidades <a name="p4"></a> 
#### Ver Información del Usuario
* El sistema pregunta el id del jugador a consultar.
*	Si el jugador existe el sistema presenta el identificador, nombre y cantidad de Gonzos que tiene disponibles el jugador. 
	> Si el jugador **no existe**, el sistema presenta un mensaje de error.

#### Vender Gonzos
*	El sistema pregunta el id del jugador que quiere recargar.
*	Si el jugador existe el sistema solicita el dinero a recargar.
*	El sistema valida que el valor a recargar sea mayor a 0. 
*	El sistema actualiza los Gonzos del jugador. 
	> Si el jugador **no existe**, el sistema presenta un mensaje de error.

#### Retirar Usuario
*	El sistema pregunta que usuario desea retirar.
*	El sistema recibe el id del usuario.
*	El sistema valida si el usuario existe.
*	El sistema muestra la información del usuario a retirar. 
	> **Si existe** elimina al jugador del casino. Si el jugador **no existe** el sistema muestra un error.

#  💸 JUEGOS EXISTENTES <a name="juegos"></a> 
### :game_die: JUEGO 1 | El Mayor de 13  <a name="13"></a> 
#### •	Mecánica de Juego
El sistema genera un número aleatorio para el usuario entre 1 y 13.
Ahí el usuario debe tener 2 opciones para continuar, la primera: darse por perdido antes de que se genere el número que le corresponde a casino (en este caso perderá la mitad del dinero apostado). La segunda: jugar, es decir, que se genere el número aleatorio del casino. 
#### •	Calcular Resultado
En caso de que el usuario saque un número menor o igual que el casino, perderá todo lo apostado. 
En otro caso, el usuario ganará el doble de lo apostado (es decir, apostado x 2). 


### :game_die: JUEGO 2 | Dos Colores <a name="colores"></a> 
#### •	Mecánica de Juego
El usuario tira un dedo (de 6 caras) y escoge entre 2 colores (Blanco o Negro), la idea es coincidir con el valor del dado y el color que luego le saldrá al casino. 
El sistema le pregunta al usuario el color a elegir (Blanco o Negro) y el valor apostado, luego generará un color y un número aleatorio para el casino.
#### •	Calcular Resultado
Si coincide tanto el valor del dado como el color, el usuario ganará 4 veces lo apostado. Si el usuario coincide sólo con el valor del dado ganará 0.5 veces lo apostado, si el usuario coincide sólo con el color elegido no gana ni pierde nada, si el usuario no coincide en nada, pierde todo el dinero apostado.


# :mag: REQUERIMIENTOS NO FUNCIONALES <a name="reqnofun"></a> 
*	Su programa debe ajustar y extender el diseño definido por el arquitecto. A fin de acelerar el desarrollo, el arquitecto provee el repositorio con los archivos ya definidos y algunas funcionalidades implementadas. [UML](https://drive.google.com/file/d/15hwoTeDrSQd6U0UEy-JJwW1JUS7qQf9D/view?usp=sharing)

 
 *****
#  <a name="parcial"></a> 
> Este ejecicio evalúa conceptos relacionados con programación orientada a objetos 
> Las preguntas prácticas las debe hacer en el código fuente. 
> A este código fuente debe hacerle commit y push a su repositorio de github para que quede entregado. 
> La fecha máxima de entrega es al terminar la clase del día haciendo push al repositorio 


## :chart_with_upwards_trend: PREGUNTAS TEÓRICAS - 15 puntos <a name="teoria"></a> 
> Conteste las preguntas en un archivo llamado su código.md. Suba este archivo a su repositorio 

* CLASES ABSTRACTAS (6 pts)
La clase Juego es una clase abstracta. 
	* Explique qué cosas del código fuente indican que la clase es una clase abstracta 
	* ¿Qué implicaciones tiene esa decisión de diseño para este programa?. Explique


## :chart_with_upwards_trend: AJUSTES <a name="ajus"></a> 
### :gear: Ajustes a Realizar en el Código | Obligatorios en el parcial - 35 puntos
* **FEATURE**- Agregue a cada juego un método en el que muestre las reglas básicas del juego. Llame a este metodo mostrarReglas. Diseñe este cambio para que todos los juegos que se creen en el futuro y los juegos actuales deban tener este método implementado. (16pts)
* **NEW**: Agregue al casino un nuevo juego - y haga todo lo que necesite su código para probar que es posible jugar su nuevo juego en el casino ( 19 pts)

### :gear: Ajustes a Realizar en el Código | Bonus
> Desde 2 puntos extras. Sirven para practicar un poco más
* **MOD**: Las condiciones del casino cambiaron. Debido a esos cambios para poder jugar un nuevo juego los jugadores deben tener en su saldo al menos el doble de los gonzos a apostar. Ajuste el código fuente para que este comportamiento exista. Verifique el código que ya existe y actualicelo según necesite. 
* **FIX**: Refactorice el codigo para que no tenga segmentos repetidos que validan si el dinero es mayor a cero.
* **FEATURE**- Agregue un método en casino para mostrar todos los jugadores disponibles
* **FEATURE**- Agregue un método para mostrar todos los juegos disponibles en el casino. A fin de identificar cada juego agréguele un nombre y haga los cambios que requiera el diagrama de clases y el código fuente.

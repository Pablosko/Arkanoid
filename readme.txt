Arkanoid version final

orientacion para correcion:

-El script de gameScene tiene la gran mayoria del codigo del juego.
-Los ficheros XMl no han sido implementados a tiempo, esta la clase pero la he tenido que quitar, los bricks
se generan aleatoriamente.
-Los bricks aveces reciben mas de una instancia de daño a la vez y parece que se rompan siempre de una, pero
no es asi. Se les ha puesto una invencibilidad de 0.1 segundos pero aun asi no funciona
(por si recibe multiples hits antes de salir de la colision)
-Los power Ups tienen la imagen de la plataforma pero estan los 3 funcionando correctamente.
-Me equivoque y implemente el pausa con la P tanto para ponerlo como quitarlo
-Si se presiona el esq en el pausa el juego vuelve al menu pero salta un error de audio,
 si se quita el audio funciona
-Cada vez que se abre una escena salta una nueva ventana de SDL, no he sabido el porque
-La pestaña de ranking no funciona, lleva directamente al game
-Hay algunas cosas que no estan como me gustarian, como las collisiones que son gestionadas desde
el gameScene en lugar de un script dedicado, o la generacion d epower ups que se ejecuta en gamescene
en lugar de en el prorio brick cuando muere etc..

-Por ultimo y como easter egg hay que saber que, entendi que tenian que haber 2 pelotas la primera vez que lo lei 
pero lo cambie cuando lo volvi a leer a como sale en el documento, se ha mantenido
el modo 2 pelotas si se presiona la tecla 2(si juegas solo es imposible disfrutarlo porque se acaba el game muy rapido).


Muchas Gracias y espero que te guste!


GITHUB -> NO NOS DEJA SUBIRLO PORQUE PONE +100 FILES y archivos +25MB

Arkanoid versión final

Grupo: Humberto Scorza, Pablo Fernandez y Nahuel Aparicio.

Orientación para corrección:

- El script de gameScene tiene la gran mayoría del código del juego.

- Los power Ups tienen la imagen de la plataforma pero están los 3 funcionando correctamente.

- Nos equivocamos e implementamos la pausa con la P tanto para ponerlo como quitarlo.

- Al volver a otras escenas nos salta un error de audio que no hemos sabido arreglar. Hemos preferido dejar el audio,
ya que el juego es funcional. Al quitar el audio no peta el cambio de escenas.

- Cada vez que se abre una escena salta una nueva ventana de SDL, no hemos descubierto por qué.

- No hemos conseguido que el ranking cambie los valores del xml.

- Los bricks a veces reciben mas de una instancia de daño a la vez y parece que se rompan siempre de un golpe, pero
no es asi. Se les ha puesto una invencibilidad de 0.1 segundos pero aun asi no funciona
(por si recibe multiples hits antes de salir de la colision)

- Hay algunas cosas que no están como nos gustaría, las colisiones (son gestionadas desde
el gameScene en lugar de un script dedicado), la generación de power ups (se ejecuta en gamescene
en lugar de en el propio brick), cuando muere etc..

EASTER EGG:

- Por último y, como easter egg, hay que saber que, entendimos que tenía que haber 2 pelotas la primera vez que lo leímos, pero lo cambiamos cuando lo volvimos a leer a como sale en el documento, se ha mantenido.
El modo 2 pelotas si se presiona la tecla 2 (si juegas solo es imposible disfrutarlo porque se acaba el game muy rápido).





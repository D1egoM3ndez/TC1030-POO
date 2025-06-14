# TC1030-POO

## Contexto

Un juego RPG (Role-Playing Gme por sus siglas en inglés) es una rama de los videojuegos donde se le propone al jugador el tomar el rol de algún personaje de la aventura presentada del mundo ficticio. "Los RPGs suelen presentar sistemas de evolución y progresión de personajes, una narrativa rica y elaborada, y mecánicas de juego que fomentan la toma de decisiones y la interacción con otros personajes o elementos del mundo virtual."(Quevedo,2024).

## Funcionamiento principal del programa
En este programa se simula como es un videojuego de alta gama como es el presentado en una especie básica de juego. El jugador puede escoger entre tres opciones al inicio de su aventura para formar a su equipo. El nombre o apodo que escoja es indiferente en este punto, por lo que se aceptan todos los símbolos posibles, es decir, aquí no hay restricciones para lo que el usuario pueda escribir. Después de eso, el nombre de los pokemon se deben de escribir tal cual viene presentado en la pantalla. Se recomienda verificar el nombre antes de dar la selección completa. Luego solo se aceptan variables numéricas referentes a lo que pase dentro del juego. El juego termina cuando el jugador combate contra los tres entrenadores y gana, esto sucederá cuando gane 2 de 3 batallas, si en algún punto pierde se saldrá del juego completamente.

En este programa esta supuesto a que si el nombre o la entrada que el usuario esta introduciendo es incorrecta saldrá una frase de "Entrada inválida" para que hasta que el usuario introduzca una entrada correcta pueda seguir el programa, sin embargo, el programa en ningún momento se tiene que detener a menos que el usuario quiera salir del juego.

## Descripción UML
El UML presentado representa a las clases que se estan utilizando en el programa, se tienen 2 tipos de personajes que el usuario puede personalizar en un momento, tanto el nombre de entrenador que quiere como su equipo, es por eso que al tener ambos atributos similares deben de compartir alguna clase mayor para heredar, de ahí que exista la clase personaje, tomando en cuenta que también tienen sus atributos propios. Ahora también debemos de considerar las clases ataque y tipo, comenzando por la clase tipo que es curiosa, podemos observar que existen los 18 tipos elementales que hay en la franquicia, cada uno tiene sus propias listas donde guardan sus ventajes/desventajas elementales para seguir con la dinámica de RPG, de ahí se pueden agregar a las clases ataques y Pokemon, en este caso lo puse como agregación dado que en cierto momento de incluir la evolución pueda existir los casos en que cambien de tipo los Pokemon, por lo que es factible pensar en que se le puede quitar y poner tipos, en la clase ataque también sucederá el caso en que el ataque pueda cambiar de tipo por alguna habilidad.

Para la relación entre la clase ataque y Pokemon decidí que fuera también agregación dado que dentro de la franquicia los ataques que los Pokemon puedan aprender mediante Maquinas Ocultas (Mo's conocidas dentro de los juegos), por lo que también se tarta de un quitar y poner ataques sin que estos se terminen de eliminar del todo.

Posteriormente, se crea una base de contención para datos guardados tanto de Pokemon como de Entrenadores pasados de la historia del juego, todo esto por medio de polimorfismo en la clase Pokedex.

## Bibliografía
Quevedo, C. (2024, 4 junio). ¿Qué es RPG? PcComponentes. https://www.pccomponentes.com/que-es-un-rpg?srsltid=AfmBOoqyzW0yGn2E7u9Fr-xLzsg46MaZm5PaFl7EIw-XDpgcK3GDuzNS

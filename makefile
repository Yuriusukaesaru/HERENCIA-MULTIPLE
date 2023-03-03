# Tu proyecto ahora utiliza la carpeta src/ para los archivos fuente y bin/ para los ejecutables.
# src/ no representa ningún problema porque dicha carpeta se encontrará ahora en el repositorio.
# bin/ sin embargo no debe ser parte del repo. es más, debe ser agregada a.gitignore: no es cool
# que ande viajando una carpeta de compilación vacía en los repositorios. Para ello, vamos a crearla
# como parte de la receta con el comando
#
# 	mkdir -p bin
#
# mkdir es el comando de Unix/Linux y adoptado en Poweshell para crear una carpeta. El flag -p nos
# asegura que solo la vaya a crear si no existe.

win: src/main.cpp
	mkdir -p bin
	g++ src/main.cpp -Wall -Wextra -Wpedantic -Werror -o bin/heritage.exe

nix: src/main.cpp
	mkdir -p bin
	g++ src/main.cpp -Wall -Wextra -Wpedantic -Werror -o bin/heritage

# M1 Projet Informatique Graphique

## TODO:
- [ ] Bezier curves
    - [ ] Discritization
        - [x] From a given number of line segments
        - [ ] From a given length of line segment
    - [x] Visualization
- [ ] Bezier surfaces
    - [ ] Discritization
        - [x] Position
        - [x] Normals
        - [ ] (u, v) coordinates
    - [ ] Visualization
        - [?] Lambertian reflectance
        - [x] Surface normals visualization with lines
        - [?] Surface normals visualization with colors
        - [?] Parameter space
- [ ] Real-time rendering
    - [ ] BRDF Implementation
    - [ ] Texture support
    - [?] Three-point lighting
- [ ] BONUS
    - [ ] Interactive Bezier curve manipulation
    - [ ] Skybox


## Dépendances

-   [GLFW](https://www.glfw.org/)
-   [GLM](https://glm.g-truc.net/0.9.9/index.html)

```shell
    $ sudo apt install libglfw3-dev libglew-dev libglm-dev libassimp-dev
```

- fichier defines.h comprends la majorité des bibliothèques nécessaires si certaines manquent

## Description

### building project:
```shell
    $ cmake -S . -B build/
    $ cmake --build build/
```

### running project:

#### Bezier curves
```shell
    $ build/main -b
```
#### Bezier curves control polygon
```shell
    $ build/main -p
```
#### Bezier surface
```shell
    $ build/main -s -u 20 -v 20 
```
- u,v parametrable, 20 par défaut avec juste -s

#### Normals
```shell
    $ build/main -n 
```

#### ParametricSpace
```shell
    $ build/main -t 
```
- vraiment pas sur que ça soit ça

#### Normals with Surface
```shell
    $ build/main -ns
```
- Depuis dernière version, normals semblent apparaitre et disparaitre suivant l'angle de la caméra
### how to use:
-   `Z` to move up
-   `S` to move down
-   `Q` to move left
-   `D` to move right
-   `Arrow key up` to look up
-   `Arrow key down` to look down
-   `Arrow key left` to look left
-   `Arrow key right` to look right
-   `Scroll up` to zoom in
-   `Scroll down` to zoom out
-   `Escape` to quit




# LIFAP4 - Bomberman

## TO-DO LIST
- [ ] Problème chrono Bombe explosion + limitation de pose de Bombe
- [ ] Bonus sur le terrain
- [X] Problème deuxième joueur affichage
- [ ] Condition de victoire 
- [ ] Commenter les fonctions

### Étudiants :
Kévin CUZIN (p1909458 - kevin.cuzin@etu.univ-lyon1.fr)  
Anh-Kiet VO (p1907921 - anh-kiet.vo@etu.univ-lyon1.fr)  
Cécilia NGUYEN (p1908025 - cecilia.nguyen@etu.univ-lyon1.fr)

### Diagramme des classes

[Lien vers le diagramme](https://nsm09.casimages.com/img/2021/03/23//21032309592517252817329920.png)

-----------------

### Le Bomberman : 

Ce projet est un [Bomberman](https://fr.wikipedia.org/wiki/Bomberman) réalisé en C++ dans le cadre de l'UE Conception Et Développement D'Applications (LIFAP4).
Le Bomberman est disponible en version console (TXT) mais elle est aussi disponible avec un affichage graphique (SDL2).

Organisation de l'archive :  
* /bin : Fichiers executable
* /data : Assets (Images, sons, fonts...)
* /doc : Documentation, présentation PowerPoint, diagramme des classes UML, diagramme de Gantt, cahier des charges...
* /obj : Fichiers .o
* /src : Fichiers contenant le code du Bomberman
* /src/sdl2 : FIchier contenant le code du Bomberman en SDL2
* /src/txt : Fichier content le code du Bomberman en TXT


-----------------

### Compilation :

Afin de pouvoir compiler le programme, il faut utiliser le Makefile :

```
make
```


-----------------

### Exécution :

Pour éxecuter le Bomberman en version TXT :

```
./bin/mainTXT
```

Pour éxecuter le Bomberman en version SDL :

```
./bin/mainSDL
```
-----------------

### Documentation :

La documentation a été générée automatiquement via [Doxygen](https://www.doxygen.nl/index.html)  

Pour pouvoir accéder à la documentation :  
```
doxygen doc/image.doxy
```

Puis pour afficher la documentation :
```
[nom_de_votre_navigateur] doc/html/index.html
```

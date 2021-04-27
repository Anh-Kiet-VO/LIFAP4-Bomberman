# LIFAP4 - Bomberman

## TO-DO LIST
- [ ] Problème chrono Bombe explosion + limitation de pose de Bombe
- [ ] Bonus sur le terrain
- [X] Problème deuxième joueur affichage
- [ ] Condition de victoire 
- [X] Commenter les fonctions

## 🎓 Étudiants :
Kévin CUZIN (p1909458 - kevin.cuzin@etu.univ-lyon1.fr)  
Anh-Kiet VO (p1907921 - anh-kiet.vo@etu.univ-lyon1.fr)  
Cécilia NGUYEN (p1908025 - cecilia.nguyen@etu.univ-lyon1.fr)

## Diagramme des classes

[Lien vers le diagramme](https://nsm09.casimages.com/img/2021/03/23//21032309592517252817329920.png)

-----------------

## 💣 Le Bomberman : 

Ce projet est un [Bomberman](https://fr.wikipedia.org/wiki/Bomberman) réalisé en C++ dans le cadre de l'UE Conception Et Développement D'Applications (LIFAP4).
Le Bomberman est disponible en version console (TXT) mais elle est aussi disponible avec un affichage graphique (SDL2).

Sur un terrain rempli de briques, vous incarnez un personnage qui peut poser des bombes. Votre but est simple : Frayez-vous un chemin en utilisant vos bombes afin de tuer les joueurs adverses. Mais attention à ne pas se faire toucher par une bombe !
Sous TXT, les briques sont représenté par un ``.`` et les murs par des ``#``. Tandis que sous SDL2, les objets sont représenté par des images.

### 🕹️ Utilisation :
Que ce soit en mode TXT ou SDL2, les touches sont les mêmes, la seule différence est bien-sûr l'affichage. Le jeu est fait pour être utilisé sur un clavier AZERTY.
```
+---------------------------+----------------------------+
|   Touches du Joueur 1     |     Touches du Joueur 2    |
+---------------------------+----------------------------+
| O 👉 Se déplacer en haut  | ↑ 👉 Se déplacer en haut  |
| K 👉 Se déplacer à gauche | ← 👉 Se déplacer à gauche |
| L 👉 Se déplacer en bas   | ↓ 👉 Se déplacer en bas   |
| M 👉 Se déplacer à droite | → 👉 Se déplacer à droite |
| P 👉 Poser une bombe      | ENTER 👉 Poser une bombe  |
+---------------------------+----------------------------+
```


### 🔖 Organisation de l'archive :  
```
bin/
├─ Fichiers éxecutable
data/
├─ Assets (Images, sons, fonts...)
doc/
├─ Documentation généré par doxyfile (Diagramme UML/Gantt, cahier des charges...)
obj/
├─ Fichiers *.o
src/
├─ core/
│  ├─ *.cpp et *.h du Bomberman
├─ sdl2/
│  ├─ *.cpp et *.h du Bomberman en version SDL2
├─ txt/
│  ├─ *.cpp et *.h du Bomberman en version TXT
├─ Test.cpp pour effectuer les tests de régression
README
```
-----------------

## 🛠️ Compilation :

Afin de pouvoir compiler le programme, il faut utiliser le Makefile :

```
make
```


-----------------

## ⚒️ Exécution :

Pour éxecuter le Bomberman en version TXT :

```
./bin/mainTXT
```

Pour éxecuter le Bomberman en version SDL :

```
./bin/mainSDL
```
-----------------

## 📚 Documentation :

La documentation a été générée automatiquement via [Doxygen](https://www.doxygen.nl/index.html)  

Pour pouvoir accéder à la documentation :  
```
doxygen doc/image.doxy
```

Puis pour afficher la documentation :
```
[nom_de_votre_navigateur] doc/html/index.html
```

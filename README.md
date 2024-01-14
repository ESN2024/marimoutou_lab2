# marimoutou_lab2
## Introduction
Pour ce 2éme labo on se propose d'utiliser un bloc pérsonnalisée avec nos bloc IP déja présents sous QSYS. 
On utilisera ici les afficheurs 7 segments présents sur la carte ainsi qu'un timer qui générera des interruptions de façon périodique. 

## Architecture du système
![lab2](https://github.com/ESN2024/marimoutou_lab2/assets/97475510/bac169a6-82a6-4ea6-b407-e101e92f97ed)

Le système est composé de l'architecture basique vu en cours dans laquelle on retrouve :

* Un processeur Nios II
* Une mémoire RAM
* Une clock
* Un port JTAG

A cela on ajoute :

* Un PIO 4 bits pour le premier afficheur 7 segments.
* Un PIO 4 bits pour le deuxième afficheur 7 segments.
* Un PIO 4 bits pour le troisième afficheur 7 segments.
* Un Timer 32 bits.

## Platform Designer
L'architecture sous Platform Designer (**QSYS**) est donc la suivante :
![qsys_lab2](https://github.com/ESN2024/marimoutou_lab2/assets/97475510/6376c0ee-8510-4b8c-8e7f-541f386db8b3)

### Quartus
Sur quartus on vient d'abord décrire notre composant *BCD7SEG.vhd* qui permet d'afficher un mot de 4 bit sur un afficheur 7 segments et ensuite rédigé notre fichier *toplevel.vhd* qui nous permet de relier notre composants créer sous qsys à notre bloc **BCD7SEG** à l'aide de signaux. On réaliser ensuite le pin assignements dans le pin planner ou en modifiant le fichier *.qsf* . 
On réalise ensuite la compilation compléte de notre design et si il n'y a aucune erreur nous pouvons flasher l'archihtecture sur notre carte.

### Nios2 Flow
A partir du terminal Nios2 on vient alors créer notre **Makefile** et générer notre **bsp**.
Une fois cela fait, nous pouvons écrire nos scripts C, les compiler et les téléverser sur notre carte.

## Travail effectué

## Conclusion

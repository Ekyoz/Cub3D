# Cub3D

Un moteur de rendu 3D basé sur le raycasting, inspiré du légendaire Wolfenstein 3D.

## 📋 Description

Cub3D est un projet de l'école 42 qui consiste à créer un moteur de rendu 3D en utilisant la technique du raycasting. Le joueur se déplace dans un labyrinthe en vue à la première personne, avec des murs texturés, des sols et des plafonds colorés.

## ✨ Fonctionnalités

### Fonctionnalités Obligatoires
- 🎮 Navigation en vue à la première personne dans un environnement 3D
- 🧱 Rendu de murs avec différentes textures selon l'orientation (Nord, Sud, Est, Ouest)
- 🎨 Couleurs personnalisables pour le sol et le plafond
- ⌨️ Contrôles au clavier pour se déplacer et tourner
- 🗺️ Parsing de fichiers de configuration `.cub`
- ❌ Gestion d'erreurs robuste pour les fichiers de carte invalides

### Fonctionnalités Bonus
- 🗺️ Minimap en temps réel
- 🖱️ Contrôle de la caméra à la souris
- 🚪 Portes interactives
- 🎨 Effets visuels supplémentaires

## 🔧 Prérequis

- **OS**: Linux ou macOS
- **Compilateur**: gcc ou clang
- **Bibliothèques**:
  - MLX (MinilibX) - pour le rendu graphique
  - X11 et Xext (Linux uniquement)
  - Math library

## 📦 Installation

### 1. Cloner le repository
```bash
git clone https://github.com/Ekyoz/Cub3D.git
cd Cub3D
```

### 2. Compiler le projet

**Version obligatoire**:
```bash
make
```

**Version bonus**:
```bash
make bonus
```

### 3. Autres commandes
```bash
make clean    # Nettoie les fichiers objets
make fclean   # Nettoie tout (objets + exécutables)
make re       # Recompile complètement le projet
make norm     # Vérifie la norme 42
```

## 🚀 Utilisation

### Lancer le jeu
```bash
./cub3d maps/map.cub
```

ou pour la version bonus:
```bash
./cub3d_bonus maps/map_bonus.cub
```

## 🎮 Contrôles

### Clavier
- **W / ↑** : Avancer
- **S / ↓** : Reculer
- **A** : Déplacement latéral gauche
- **D** : Déplacement latéral droit
- **← →** : Rotation de la caméra
- **ESC** : Quitter le jeu

### Souris (Bonus)
- **Mouvement** : Contrôle de la caméra
- **Clic** : Interactions avec l'environnement

## 🗺️ Format de Fichier de Carte

### Structure du fichier `.cub`

```
NO ./assets/walls/wood.xpm
SO ./assets/walls/red_brick.xpm
WE ./assets/walls/blue_bricks.xpm
EA ./assets/walls/grey_brick.xpm

F 34,34,34
C 170,170,255

        1111111111111111111111111
        1000000000110000000000001
        1011000001110000000000001
        10010000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010000W01
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
1100000111010101111101111000111
11110111 1110101 101111010001
11111111 1111111 111111111111
```

### Éléments de configuration

**Textures** (chemin vers fichier .xpm):
- `NO` : Texture du mur Nord
- `SO` : Texture du mur Sud
- `WE` : Texture du mur Ouest
- `EA` : Texture du mur Est

**Couleurs** (format RGB: R,G,B):
- `F` : Couleur du sol (Floor)
- `C` : Couleur du plafond (Ceiling)

**Caractères de la carte**:
- `0` : Espace vide (praticable)
- `1` : Mur
- `N/S/E/W` : Position de départ du joueur et orientation
- ` ` (espace) : Zone hors carte

### Règles de validation
- La carte doit être fermée/entourée de murs (1)
- Un seul joueur doit être présent
- Position de départ valide: N, S, E ou W

## 📁 Structure du Projet

```
Cub3D/
├── include/              # Fichiers d'en-tête
│   ├── cub3d.h          # Header principal
│   ├── structs.h        # Structures de données
│   ├── define.h         # Définitions et constantes
│   ├── error_messages.h # Messages d'erreur
│   ├── GNL/             # Get Next Line
│   ├── LibFT/           # Bibliothèque LibFT
│   ├── mlx-linux/       # MLX pour Linux
│   └── mlx-mac/         # MLX pour macOS
├── srcs/
│   ├── mandatory/       # Code obligatoire
│   │   ├── parser/      # Parsing de la carte
│   │   ├── raycasting/  # Algorithme de raycasting
│   │   ├── render/      # Rendu graphique
│   │   ├── player/      # Gestion du joueur
│   │   ├── textures/    # Gestion des textures
│   │   └── hooks/       # Gestion des événements
│   └── bonus/           # Code bonus
│       └── render/      # Minimap, etc.
├── maps/                # Fichiers de cartes
│   ├── map.cub
│   └── map_bonus.cub
├── assets/              # Ressources graphiques
│   └── walls/           # Textures des murs
├── Makefile
└── README.md
```

## 🔍 Fonctionnement Technique

### Raycasting
Le projet utilise l'algorithme DDA (Digital Differential Analysis) pour le raycasting:
1. Pour chaque colonne de pixels à l'écran, un rayon est lancé
2. Le rayon avance jusqu'à toucher un mur
3. La distance est calculée pour déterminer la hauteur du mur à afficher
4. La texture appropriée est appliquée selon l'orientation du mur

### Paramètres configurables (define.h)
- **Résolution** : 1440x900
- **FOV** : 66°
- **Vitesse de déplacement** : 2
- **Vitesse de rotation** : 0.045 rad

## 👥 Auteurs

- **atresall** - [42Lyon]
- **bastpoy** - [42]

## 📝 Licence

Ce projet fait partie du cursus de l'école 42.

## 🙏 Remerciements

- L'équipe pédagogique de 42
- La communauté 42 pour le partage de connaissances
- Les créateurs de Wolfenstein 3D pour l'inspiration
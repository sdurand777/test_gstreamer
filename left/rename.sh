#!/bin/bash

# Initialisation du compteur
i=0

# Trouve les fichiers JPG, les trie et les renomme
for file in $(ls *.JPG | sort); do
    mv "$file" "image_$i.JPG"
    i=$((i + 1))
done

#!/bin/bash

echo "==== Compilation Metaphone3 SO pour Python (hors demo & test) ===="

INCLUDE="-Iinclude"
SRC_FILES=$(find src -type f -name '*.c' ! -path "*/test/*" ! -path "*/demo/*")
FILE_COUNT=$(echo "$SRC_FILES" | wc -l)
echo "Nombre de fichiers sources à compiler : $FILE_COUNT"

SO_NAME="libmetaphone3.so"
CMD="gcc -shared -fPIC -o $SO_NAME $SRC_FILES $INCLUDE"
echo
echo ">> Compilation en cours..."
eval $CMD

if [ -f $SO_NAME ]; then
    echo
    echo "SO Linux compilé ! Fichier : $SO_NAME"
else
    echo
    echo "Échec de la compilation de la SO Linux."
fi

echo
echo "==== Build terminé ===="

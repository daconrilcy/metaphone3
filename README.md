# Metaphone3 C Library

## Présentation

**Metaphone 3** (version C) est une implémentation fidèle de l’algorithme Metaphone3, développé par Lawrence Philips.

> Metaphone 3 est conçu pour fournir une clé phonétique approximative (et une clé phonétique alternative quand c’est pertinent) qui doit être identique pour les mots anglais et la plupart des noms courants aux États-Unis qui se prononcent de façon similaire. La valeur de cette clé n’a pas vocation à être une représentation phonétique ou phonémique exacte du mot. Ce choix est volontaire, car un certain degré de « flou » s’avère utile pour compenser les variations de prononciation ainsi que les erreurs d’audition.

**Licence et copyright :**

```text
Copyright 2010, Lawrence Philips
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are
met:

    * Redistributions of source code must retain the above copyright
notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
copyright notice, this list of conditions and the following disclaimer
in the documentation and/or other materials provided with the
distribution.
    * Neither the name of Google Inc. nor the names of its
contributors may be used to endorse or promote products derived from
this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
```

Voir l’en-tête des sources pour la licence complète.

---

## Compilation sous Windows (.dll)

1. **Prérequis :**

   - [MinGW-w64](http://mingw-w64.org) installé (`gcc` accessible dans le PATH)
   - Powershell disponible

2. **Script automatique :**
   - Utilise le script fourni : `build-api-python-win.ps1`
   - Il compile une DLL utilisable avec Python (`ctypes`) en excluant les dossiers `test` et `demo`.
   - Exemple :
     ```powershell
     ./build-api-python-win.ps1
     ```
   - Le fichier généré sera : `libmetaphone3.dll`

---

## Compilation sous Linux (.so)

1. **Prérequis :**

   - gcc disponible (Ubuntu, WSL, etc.)

2. **Script automatique :**
   - Utilise le script fourni : `build-metaphone3-py.sh`
   - Il compile une librairie partagée (`libmetaphone3.so`) en excluant `test` et `demo`.
   - Exemple :
     ```bash
     bash build-metaphone3-py.sh
     ```
   - Le fichier généré sera : `libmetaphone3.so`

---

## Utilisation avec Python (ctypes)

Exemple minimal d’utilisation pour encoder une liste de mots :

```python
import ctypes

# Windows
lib = ctypes.CDLL('metaphone3_py.dll')
# Linux
# lib = ctypes.CDLL('./libmetaphone3.so')

# Prototypage
lib.metaphone3_encode_multi_str.restype = ctypes.c_char_p
lib.metaphone3_encode_multi_str.argtypes = [ctypes.c_char_p, ctypes.c_char, ctypes.c_int, ctypes.c_int, ctypes.c_int]
lib.free_result_str.restype = None
lib.free_result_str.argtypes = [ctypes.c_char_p]

input_words = "London|Edinburgh|Paris"
sep = b'|'
encode_vowels = 0
encode_exact = 0
metaph_length = 16

result = lib.metaphone3_encode_multi_str(input_words.encode('utf-8'), sep[0], encode_vowels, encode_exact, metaph_length)
if result:
    csv = ctypes.string_at(result).decode('utf-8')
    print(csv)
    lib.free_result_str(result)
```

Le résultat est une chaîne CSV contenant une ligne par mot : `mot,primary,secondary`.

---

## Dossiers et scripts fournis

- `src/` : code source principal
- `include/` : headers
- `demo/`, `test/` : non inclus dans les builds de la lib
- `api/` : wrappers pour utilisation multi-langages (dont Python)
- `build-api-python-win.ps1` : build pour Windows (.dll)
- `build-metaphone3-py.sh` : build pour Linux (.so)

---

## Pour toute modification

Merci de respecter la licence d’origine, de bien commenter et signer vos modifications.

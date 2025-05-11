# Zadania Rekrutacyjne 2025 – Filip Rak
Repozytorium zawiera rozwiązania zadań rekrutacyjnych wraz z pełnym kodem źródłowym, testami jednostkowymi oraz CMake'iem.

## Spis treści

- [Struktura projektu](#struktura-projektu)
- [Wymagania](#wymagania)
- [Budowanie projektu](#budowanie-projektu)
- [Opis zadań](#opis-zadań)
- [Testy](#testowanie)

## Struktura projektu

```
├── build/                # Pusty katalog dla plików wynikowych CMake
│   └── bin/              # Pusty katalog na pliki na wygenerowane pliki wykonywalne (main/test)
│
├── CMakeLists.txt        # Główny plik konfiguracyjny CMake
│
├── exercises/            # Katalog główny z trzema ćwiczeniami
│
│   ├── exercise1/        # Ćwiczenie 1: wyszukiwarka z Trie
│   │   ├── CMakeLists.txt
│   │   ├── main.cpp         # Program główny
│   │   ├── test_trie.cpp    # Testy jednostkowe
│   │   ├── trie.cpp/.h      # Implementacja Trie
│
│   ├── exercise2/        # Ćwiczenie 2: kolizje trójkątów z SFML
│   │   ├── CMakeLists.txt    
|   ├── include
|   │   ├── triangle.h         # Nagłówki współdzielone
|   │   └── visualization.h  
|   ├── src                    # Implementacja programu
|   │   ├── main.cpp
|   │   ├── triangle.cpp
|   │   └── visualization.cpp
|   └── tests                  # Testy kolizji
|       └── test_collision.cpp
│
│   └── exercise3/        # Ćwiczenie 3: funkcja calculate z konceptami
│       ├── CMakeLists.txt
│       ├── main.cpp            # Główny plik testowy
│       ├── calculate.h         # Implementacja funkcji (header-only)
│       └── test_calculate.cpp  # Testy funkcji calculate
│
└── README.md            # Ten plik
```

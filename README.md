# Zadania Rekrutacyjne 2025 – Filip Rak
Repozytorium zawiera rozwiązania zadań rekrutacyjnych wraz z pełnym kodem źródłowym, testami jednostkowymi oraz CMake'iem.

## Spis treści

- [Struktura projektu](#struktura-projektu)
- [Wymagania](#wymagania)
- [Budowanie projektu](#budowanie-projektu)
- [Opis zadań](#opis-zadań)

## Struktura projektu

```
├── build/                # Pusty katalog dla plików wynikowych CMake
│   └── bin/              # Pusty katalog dla wygenerowanych plików wykonywalnych (main/test)
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

## Wymagania
- **CMake** w wersji co najmniej **3.16**.
- Kompilator C++ z pełną obsługą **C++20**.
- Kompilator musi być kompatybilny z systemem **CMake**.
- Połączenie z Internetem przy pierwszym uruchomieniu w celu pobrania zależności (SFML, Catch2).

> W przypadku kompilacji na systemach linux, wymagana może być instalacja następujących bibliotek systemowych dla SFML:
  `sudo apt install libx11-dev libxrandr-dev libfreetype6-dev libglew-dev libopenal-dev libudev-dev libflac-dev libvorbis-dev libgl1-mesa-dev libxcursor-dev`.

## Budowanie projektu
- W repozytorium znajduje się pusty katalog `build`, w którym CMake zbuduje projekt.
- Przejdź do katalogu `build` i uruchom polecenia: `cmake .. && cmake --build .`
- Utworzone pliki wykonywalne będa znajdować się w katalogu: `build/bin`.
- Testy jednostkowe mogą zostać uruchomione poleceniem `ctest`.
- W razie problemów proszę o kontakt mailowy lub telefoniczny.

## Opis zadań
### Zadanie 1 – Wyszukiwarka (szukajka.pl)
- **Opis**: Moduł sugestii oparty na strukturze Trie, wspierający wyszukiwanie po prefiksie.
- **Wejście**:
  - `add: [zapytanie]` - dodaje zapytanie do bazy.
  - `ask: [prefiks]` - wyszukuje pasujące zapytania.
- **Wyjście**:
  - Każdy wynik po `ask` jest wypisywany jako:
    ```
    result: [pasujące zapytanie]
    ```
- **Uwagi**:
  - Białe znaki po dwukropku są ignorowane.
  - Wyszukiwanie jest **case-insensitive**, ale wyniki zachowują oryginalną wielkość liter.

### Zadanie 2 – Kolizja trójkątów (SAT + SFML)
- **Opis**: Detekcja kolizji dwóch trójkątów przy pomocy algorytmu Separating Axis Theorem (SAT) oraz wizualizacja w SFML.
- **Wejście**: Użytkownik porusza trójkątami:
  - Trójkąt 1: klawisze **WASD** + **Shift** (przyspieszenie).
  - Trójkąt 2: **strzałki** + **Ctrl**.
- **Wyjście**: 
  - Kolizja trójkątów powoduje zmianę koloru (np. na czerwony).
- **Uwagi**:
  - Ruch ograniczony do granic okna.
  - Prędkość ruchu jest skalowana względem czasu trwania poprzedniej klatki (delta).

### Zadanie 3 – Operacja binarna (calculate)
- **Opis**: Szablonowa funkcja `calculate(n, value, op)`, która wykonuje operację binarną `n` razy, zaczynając od elementu neutralnego (`identity()`).
- **Wejście**:
  - `n` – liczba powtórzeń.
  - `value` – wartość wejściowa.
  - `op` – operacja binarna, np. dodawanie, mnożenie, konkatenacja.
- **Wyjście**:
  - Wynik `op(...op(identity(), value), value)...` powtórzony `n` razy.
- **Uwagi**:
  - Brak interfejsu wejścia/wyjścia — całość testowana jednostkowo.
  - Plik `main.cpp` służy jedynie jako punkt startowy w razie potrzeby testów manualnych.

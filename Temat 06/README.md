# Tutaj umieszczać pliki związane z tematem 6
## Zad.1
Napisać funkcję, która jako argumenty przyjmie: 
- Tablicę struktur
- Rozmiar tablicy
- Tablicę wartości `double`

Tablica struktur jest to tablica wypełniona punktami w układzie współrzędnych. Każde kolejne trzy tworzą trójkąt. Wypełnić tablicę wartości `double` polami powstałych trójkątów. Jeżeli z podanych punktów nie da się utworzyć trójkąta umieścić w tablicy wartość `-1`  
Wzór Herona:
```C++
sqrt(p*(p-a)*(p-b)*(p-c))
```
gdzie p to połowa obwodu a a,b,c to długości boków.
## Zad.2
Dana jest tablica dwuwymiarową struktur. 
```C++
struct punkt
{
    int x;
    int y;
};
```
Znaleźć parę punktów najbardziej od siebie oddalonych w układzie współrzędnych.
## Zad.3
Stworzyć tablicę dwuwymiarową, a następnie wypełnić ją kolejnymi liczbami na kształt "ślimaka"
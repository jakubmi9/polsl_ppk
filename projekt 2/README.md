# Tutaj umieszczać projekt 2

## Zadanie 2. Program biblioteka.  
Dana jest baza danych o książkach oraz baza danych użytkowników. 
Dla każdej książki są podane następujące informacje: imię i nazwisko autora, tytuł książki, rodzaj książki (powieść, fantastyka, poezja itp.) oraz liczba egzemplarzy w bibliotece. 
Dla użytkownika podany jest numer karty bibliotecznej, imię i nazwisko oraz książki które aktualnie ma wypożyczone. 
Program powinien umożliwić wyświetlenie książek według autora (np. tylko książki Mickiewicza), rodzaju książki (np. same powieści), wszystkie książki posortowane według nazwiska autora lub według tytułu oraz umożliwić wypożyczenie danej książki jeżeli aktualnie jest ona w bibliotece, wyświetlenie książek, których termin zwrotu upłynął, wyświetlenie użytkowników, którzy nie zwrócili książek w terminie. 
Powinien być ograniczony limit wypożyczeń dla danego użytkownika (np. maksymalnie 10). 
Użytkownik wypożycza książkę na określony czas a w przypadku przekroczenia terminu zwrotu nie może wypożyczyć następnej książki niezależnie od tego ile książek ma aktualnie wypożyczonych. 
Program powinien umożliwić modyfikowanie bazy danych o książkach i użytkownikach. 
Dobrać strukturę danych zapewniającą optymalne wykonywanie operacji wyszukiwania.

## Specyfikacja  
```
projekt 02.exe  
libXpress Library Management System alpha  
Licensed under GNU GPLv3  

libxpress$ _
```
##### Możliwe komendy
 - `exit` - opuszcza program
 - `status` - wypisuje obecny stan działania programu
 - `load <plik>` - wczytuje z *pliku* bazę danych i ładuje ją do pamięci
 - `flush` - zapisuje obecny stan bazy danych do pliku i usuwa ją z pamięci
 - `list users [--unreturned]` - wypisuje na ekran listę wszystkich użytkowników [użytkowników którzy mają nieoddane książki]
 - `list books [--byauthor | --bytitle]` - wypisuje na ekran listę wszystkich książek [opcjonalnie posortowaną względem autora | tytułu]
 - `list books [--author | --genre] <kryterium>` - wypisuje na ekran tylko książki koknretnego [autora | gatunku]
 - `borrow <tytuł> <nr karty użytkownika>` - wypożycza *książkę* *użytkownikowi*
 - `return <tytuł> <nr karty użytkownika>` - zwraca *książkę* *użytkownika*
 - `[add | edit | delete] [user | book]` - pozwala na edycję wpisów w bazie danych
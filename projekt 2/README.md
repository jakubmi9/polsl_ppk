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
library.exe status||list||add||edit||delete||borrow [...]  

library status  
library list books all -sortByAuthor ***OR*** -sortByTitle ***OR*** -sortByGenre  
library list books author=*nazwisko,imie* -sortByAuthor ***OR*** -sortByTitle ***OR*** -sortByGenre  
library list books overdue -sortByAuthor ***OR*** -sortByTitle ***OR*** -sortByGenre  
library list users overdue -sortByAuthor ***OR*** -sortByTitle ***OR*** -sortByGenre  
library add ***OR*** edit ***OR*** delete user -name=*nazwisko,imie*  
library add ***OR*** edit ***OR*** delete book -name=*tytuł*  
library borrow book=*tytuł* user=*nazwisko,imie*
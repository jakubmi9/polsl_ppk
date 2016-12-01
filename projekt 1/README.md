# Tutaj umieszczać projekt 1
## Zadanie 13.
Napisać program do szyfrowania i deszyfrowania plików tekstowych. Program powinien umożliwić tworzenie systemów
kodowych, które potem wykorzystuje do szyfrowania i deszyfrowania. Tworzenie systemu kodowego polega na
przyporządkowaniu znakowi ASCII innego znaku ASCII. System kodowy powinien być jednoznaczny.  
## Specyfikacja  
```crypt.exe -generate||-encode||-decode||-help -src="sciezka wejscia" -o="sciezka wyjscia"```

crypt encryption utility  
usage:  
crypt -generate					generates new random codetable  
crypt -encode -src="" -o=""		encodes 'src' with a codetable and writes it to 'o'  
crypt -decode -src="" -o=""		decodes 'src' with a codetable and writes it to 'o'  
crypt -help						displays this help message  
#Embedded Event Logger
Lukas Persson 
Algoritmer, datastrukturer och design patterns

Denna uppgift är en enkel firmware-lik simulator och skriven i c++ som visar eventdriven kod med kö, sortering, sökning och logg. Programmet körs i terminalen.

Projektstruktur:
EmbeddedEventLogger/
├── include/
│ ├── Event.h
│ ├── EventLog.h
│ ├── EventQueue.h
│ └── SortStrategy.h
│
├── src/
│ ├── EventLog.cpp
│ ├── EventQueue.cpp
│ ├── SortInsertion.cpp
│ └── SortSelection.cpp
│
├── main.cpp
├── README.md
└── report.md


Kompilera:
powershell:
g++ -std=c++17 main.cpp src\*.cpp -Iinclude -o eventlogger.exe

körning:
.\eventlogger.exe


tick <n> - skapar och processar n events via kön
print - skriver ut alla events i loggen
sort insertion - sorterar loggen med insertion sort
sort selection - sorterar loggen med selection sort
find <sensorId> - skriver ut alla events i loggen med angivet sensorid
help - visar tillgängliga kommandon
exit - avslutar programmet


Exempel:
tick 10
print
sort insertion
print
find 2
exit

Sortering är implementerad med ett förenklat strategy-pattern där sorteringsalgoritm väljs dynamiskt via funktionspekare baserat på vad användaren väljer.

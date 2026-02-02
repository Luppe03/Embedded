Rapport - Embedded Event Logger
https://github.com/Luppe03/Embedded.git 

Programmet är uppbyggt som ett enkelt event-drivet system. Lösningen består av följande moduler och ADT:er:
Event - Datastruktur som representerar ett event med timestamp, sensorid, typ och värde
EventQueue - Kö implementerad som en ringbuffer med fast kapacitet. Tar emot inkommande events.
EventLog - Dynamisk logg som lagrar events som har bearbetats.
EventLoop - Ansvarar för producer & consumer logiken.
SortStrategy - Hanterar val av sorteringsalgoritm.
Eventflodet i systemet ser ut såhär:
Producer -> EventQueue -> EventLoop -> EventLog

När man kör kommandot tick <n> i terminalen skapas events av producenten och läggs i EventQueue. EventLoop försöker sedan ta ett event från kön och lägga det i EventLog.

Design pattern - Strategy
För sortering av eventloggen används ett enkelt strategy mönster. Flera sorteringsalgoritmer har samma funktionssignatur och kan väljas dynamiskt i terminalen. Exempel:
sort insertion
sort selection

Tidskomplexitet
Insertion sort
Bästa fall: O(n)
Värsta fall: O(n²)
Selection sort
Alltid O(n²)
Sökning
Linjär sökning genom hela loggen
Tidskomplexitet: O(n)

Minneshantering
Dynamiskt minne används i programmets ADT:er:
EventLog - Allkoerar dynamiskt minne vid log_create. Minnet frigörs korrekt i log_destroy
EventQueue - Allkorerar minne för ringbufferent vid queue_create. Minnet frigörs i queue_destroy.
Varje ADT ansvarar för sitt eget minne, och allt dynamiskt minne frigörs när programmet avslutas. Minskar risken för minnesläckor samt gör minneshanteringen tydlig och kontrollerad.

# Steam Hours Counter
Simple program which downloads the info about hours spended in games in last 2 weeks from Steam Site and creates raports.

### Technologies
It it written in **C++** and [CURL](https://github.com/curl/curl").

### What it needs to work?
There is a list of players in **players.txt** which looks like:
```
<id> <name> <steam profile's link>
```
This is everything what program needs to work. 

### What raport is look like?
Program creates raport about every user in **player.txt**, sorts them out descending to hours in last two weeks and writes it into console. Single raport looks like this:
```
**<rank> <name>**
wynik: <hours>h [średnio <average daily hours> dzienie] 
od ostatniego pomiaru: <increment from last measurement>h / <percentage>%
do kolejnego miejsca: <hours to next place>h / <percentage>%
```

It is in polish language and can be translated into: 
```
**<rank> <name>**
score: <hours>h [average <average daily hours> daily] 
from last measurement: <increment from last measurement>h / <percentage>%
to next place: <hours to next place>h / <percentage>%
```

### What are **raports.txt** and **dates.txt** for?
In **raports.txt** are infos about previous raports, and in **dates.txt** are dates of previous measurements. They are generated automatically and they don't disturb program's work.





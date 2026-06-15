# CLI TCP Port Scanner în C++

Un utilitar în linie de comandă (CLI) dezvoltat în C++ pentru scanarea și verificarea stării porturilor TCP pe o adresă IP specificată. Proiectul utilizează socket-uri POSIX native pentru a determina dacă un port acceptă conexiuni active.

## Funcționalități și Specificații Tehnice

* **Scanare TCP:** Încearcă deschiderea unei conexiuni complete pe porturile țintă utilizând protocolul TCP.
* **Socket-uri POSIX:** Folosește API-ul nativ de rețea din sistemele de operare bazate pe Unix (`<sys/socket.h>`).
* **Fără dependențe externe:** Utilizează exclusiv biblioteca standard C++ (STL) și headerele de sistem.

## Arhitectura Codului

Programul funcționează pe baza unui model secvențial. Pentru fiecare port din listă, se execută următorii pași:

| Componentă / Funcție | Fișier Header | Rol / Explicație |
| :--- | :--- | :--- |
| `socket()` | `<sys/socket.h>` | Inițializează un socket IPv4 (`AF_INET`) bazat pe flux de date (`SOCK_STREAM` -> TCP). |
| `inet_pton()` | `<arpa/inet.h>` | Convertește adresa IP din format text în format binar de rețea. |
| `connect()` | `<sys/socket.h>` | Inițializează protocolul TCP 3-way handshake. Returnarea valorii `0` indică un port deschis. |
| `close()` | `<unistd.h>` | Eliberează descriptorul de fișier asociat socket-ului. |

## Compilare și Rulare

### Cerințe
* Sistem de operare: Linux / macOS (sau Windows prin WSL)
* Compilator: `g++`

### Compilare
```bash
g++ -O2 port_scanner.cpp -o port_scanner

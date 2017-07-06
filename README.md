# capi

This repository contains all code samples described in the C API for kdb+ whitepaper.

Code samples are intended to assist the beginner with the following concepts

* Making a connection with a listening q process
* Launching queries
* Handling errors and memory management
* Creating and extracting data from K objects including lists, dictionaries and tables
* Loading external libraries into kdb+
* Creating sample subscriber and publisher processes

This repository includes copies of some external dependencies. If experiencing any issues, please fetch latest version of corresponding files:
[k.h](https://github.com/KxSystems/kdb/tree/master/c/c)
[l32/c.o](https://github.com/KxSystems/kdb/tree/master/l32)
[l64/c.o](https://github.com/KxSystems/kdb/tree/master/l64)
[kdb+tick](https://github.com/KxSystems/kdb-tick)

To start test tickerplant 
```
q tick.q trade
```
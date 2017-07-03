# Makefile assumes the following \
(1) k.h header file is located in current folder \
(2) kdb+ version >= 3.0 on 64-bit linux (l64) with gcc   \
(3) Q version is 32bit (If not change QVER below to 64   

# Set CFLAG depending on Q version
QVER := 32
ifeq ($(QVER),64)
   CFLAG=-m64
else
   CFLAG=-m32
endif

# Set location of c.o object file to use 
LBITS := $(shell getconf LONG_BIT)
ifeq ($(LBITS),64)
   OBJHOME=64bit
else
   OBJHOME=32bit
endif


all : schema mixedList portopen alivecheck error length lists dict table refcount refcountk subscriber singleRow multiRow rowswithtime guid mathLib cryptoLib
CC=gcc
OPTS=-D KXVER=3 -Wall -Wno-strict-aliasing -Wno-parentheses
LDOPTS=-lpthread
CRYPTOPTS=-lcrypto -lssl
OBJ=$(OBJHOME)/c.o

length:
	$(CC) $(OPTS) -o length length.c $(OBJ) $(LDOPTS)
error:
	$(CC) $(OPTS) -o error error.c $(OBJ) $(LDOPTS)
alivecheck:
	$(CC) $(OPTS) -o alivecheck alivecheck.c $(OBJ) $(LDOPTS)
portopen:
	$(CC) $(OPTS) -o portopen portopen.c $(OBJ) $(LDOPTS)
mixedList:
	$(CC) $(OPTS) -o mixedList mixedList.c $(OBJ) $(LDOPTS)
schema:
	$(CC) $(OPTS) -o schema schema.c $(OBJ) $(LDOPTS)
lists:
	$(CC) $(OPTS) -o lists lists.c $(OBJ) $(LDOPTS)
dict:
	$(CC) $(OPTS) -o dict dict.c $(OBJ) $(LDOPTS)
table:
	$(CC) $(OPTS) -o table table.c $(OBJ) $(LDOPTS)
refcount:
	$(CC) $(OPTS) -o refcount refcount.c $(OBJ) $(LDOPTS)
refcountk:
	$(CC) $(OPTS) -o refcountk refcountk.c $(OBJ) $(LDOPTS)
subscriber:
	$(CC) -D KXVER=3 -Wno-unused-variable -o subscriber subscriber.c $(OBJ) $(LDOPTS)
singleRow:
	$(CC) $(OPTS) -o singleRow singleRow.c $(OBJ) $(LDOPTS)
multiRow:
	$(CC) $(OPTS) -o multiRow multiRow.c $(OBJ) $(LDOPTS)
rowswithtime:
	$(CC) $(OPTS) -o rowswithtime rowswithtime.c $(OBJ) $(LDOPTS)
guid:
	$(CC) $(OPTS) -o guid guid.c $(OBJ) $(LDOPTS)
mathLib:
	$(CC) $(CFLAG) $(OPTS) -c -fpic mathLib.c $(LDOPTS)
	$(CC) $(CFLAG) $(OPTS) -shared -o mathLib.so mathLib.o $(LDOPTS)

cryptoLib:
	$(CC) $(CFLAG) $(OPTS) -c -fpic cryptoLib.c $(LDOPTS) $(CRYPTOPTS)
	$(CC) $(CFLAG) $(OPTS) -shared -o cryptoLib.so cryptoLib.o $(LDOPTS) $(CRYPTOPTS)

clean:
	rm schema mixedList portopen alivecheck error length lists dict table refcount refcountk subscriber singleRow multiRow rowswithtime guid mathLib.o mathLib.so cryptoLib.o cryptoLib.so

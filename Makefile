LBITS := $(shell getconf LONG_BIT)
ifeq ($(LBITS),64)
   M=-m64
else
   M=-m32
endif

all : schema mixedList portopen alivecheck error length lists dict table refcount refcountk subscriber singleRow multiRow rowswithtime guid mathLib cryptoLib
CC=gcc
OPTS=-D KXVER=3 -Wall -Wno-strict-aliasing -Wno-parentheses
LDOPTS=-lpthread
CRYPTOPTS=-lcrypto -lssl
OBJ=c.o

length:
	$(CC) $(M) $(OPTS) -o length length.c $(OBJ) $(LDOPTS)
error:
	$(CC) $(M) $(OPTS) -o error error.c $(OBJ) $(LDOPTS)
alivecheck:
	$(CC) $(M) $(OPTS) -o alivecheck alivecheck.c $(OBJ) $(LDOPTS)
portopen:
	$(CC) $(M) $(OPTS) -o portopen portopen.c $(OBJ) $(LDOPTS)
mixedList:
	$(CC) $(M) $(OPTS) -o mixedList mixedList.c $(OBJ) $(LDOPTS)
schema:
	$(CC) $(M) $(OPTS) -o schema schema.c $(OBJ) $(LDOPTS)
lists:
	$(CC) $(M) $(OPTS) -o lists lists.c $(OBJ) $(LDOPTS)
dict:
	$(CC) $(M) $(OPTS) -o dict dict.c $(OBJ) $(LDOPTS)
table:
	$(CC) $(M) $(OPTS) -o table table.c $(OBJ) $(LDOPTS)
refcount:
	$(CC) $(M) $(OPTS) -o refcount refcount.c $(OBJ) $(LDOPTS)
refcountk:
	$(CC) $(M) $(OPTS) -o refcountk refcountk.c $(OBJ) $(LDOPTS)
subscriber:
	$(CC) $(M) $(OPTS) -Wno-unused-variable -o subscriber subscriber.c $(OBJ) $(LDOPTS)
singleRow:
	$(CC) $(M) $(OPTS) -o singleRow singleRow.c $(OBJ) $(LDOPTS)
multiRow:
	$(CC) $(M) $(OPTS) -o multiRow multiRow.c $(OBJ) $(LDOPTS)
rowswithtime:
	$(CC) $(M) $(OPTS) -o rowswithtime rowswithtime.c $(OBJ) $(LDOPTS)
guid:
	$(CC) $(M) $(OPTS) -o guid guid.c $(OBJ) $(LDOPTS)
mathLib:
	$(CC) $(M) $(OPTS) -c -fpic mathLib.c $(LDOPTS)
	$(CC) $(M) $(OPTS) -shared -o mathLib.so mathLib.o $(LDOPTS)

cryptoLib:
	$(CC) $(M) $(OPTS) -c -fpic cryptoLib.c $(LDOPTS) $(CRYPTOPTS)
	$(CC) $(M) $(OPTS) -shared -o cryptoLib.so cryptoLib.o $(LDOPTS) $(CRYPTOOPTS)

clean:
	rm schema mixedList portopen alivecheck error length lists dict table refcount refcountk subscriber singleRow multiRow rowswithtime guid mathLib.o mathLib.so cryptoLib.o cryptoLib.so

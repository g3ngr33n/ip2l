all : IP2Location IP2Loc_DBInterface ip2l end

IP2Location: src/IP2Location.c src/IP2Location.h
	gcc -g -O -c src/IP2Location.c -lm

IP2Loc_DBInterface: src/IP2Loc_DBInterface.c src/IP2Loc_DBInterface.h
	gcc -g -O -c src/IP2Loc_DBInterface.c -lm

ip2l: ip2l.c
	mv src/IP2Loc_DBInterface.h lib/
	mv src/IP2Location.h lib/
	gcc ip2l.c -o ip2l IP2Location.o IP2Loc_DBInterface.o

end:
	mv config.h src/
	mv ip2l.c src/
	rm -f *.o

clean:
	mv src/ip2l.c .
	mv src/config.h .
	mv lib/*.h src/
	rm ip2l

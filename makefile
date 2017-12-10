#Yuval Hoch
#ID: 204468474
#Shay Tzirin
#ID: 315314930

a.out: compileAll
	g++ -o client.out *.o 
	rm -f *.o

compileAll: include/*.h src/*.cpp
	g++ -c src/*.cpp

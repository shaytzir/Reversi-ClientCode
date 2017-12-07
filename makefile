#Yuval Hoch
#ID: 204468474
#Shay Tzirin
#ID: 315314930

a.out: compileAll
	g++ *.o
	rm -f *.o

compileAll: *.h *.cpp
	g++ -c *.cpp

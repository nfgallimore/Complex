install:
	g++ -o Complex.o Complex.cpp -c -std=c++11
	g++ -o complex_main complex_main.cpp Complex.o -std=c++11

clean:
	rm -rf *.o complex_main
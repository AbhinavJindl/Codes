default: out

out: main.o car.o bus.o truck.o 
	g++ main.o car.o bus.o truck.o  -o out
main.o: main.cpp
	g++ -c main.cpp


car.o: car.cpp
	g++ -c car.cpp
bus.o: bus.cpp
	g++ -c bus.cpp 
truck.o: truck.cpp
	g++ -c truck.cpp

 

clean:
	rm -f main.o car.o bus.o truck.o   out
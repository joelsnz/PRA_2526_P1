bin/testListArray: testListArray.cpp ListArray.h List.h
	mkdir -p bin
	g++ -o bin/testListArray testListArray.cpp

bin/testListLinked: testListLinked.cpp ListLinked.h List.h
	mkdir -p bin
	g++ -o bin/testListLinked testListLinked.cpp

bin/testNode: testNode.cpp Node.h
	mkdir -p bin
	g++ -o bin/testNode testNode.cpp Node.h

Point2D.o: Point2D.h Point2D.cpp
	g++ -c Point2D.cpp

bin/testPoint2D: testPoint2D.cpp Point2D.o
	g++ -c testPoint2D.cpp
	mkdir -p bin
	g++ -o bin/testPoint2D testPoint2D.o Point2D.o

Shape.o: Shape.h Shape.cpp
	g++ -c Shape.cpp

Circle.o: Circle.h Circle.cpp
	g++ -c Circle.cpp

clean:
	rm -r *.o *.gch bin

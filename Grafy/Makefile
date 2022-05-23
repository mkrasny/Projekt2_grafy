CXXFLAGS=-Iinc -g -std=c++1z

__start__: grafy
	./grafy

grafy: obj/main.o obj/list_graph.o obj/array_graph.o obj/algorithm.o 
	g++ -std=c++1z -o grafy obj/main.o obj/list_graph.o obj/array_graph.o obj/algorithm.o 

obj/main.o: src/main.cpp inc/graph.hpp inc/list_graph.hpp inc/array_graph.hpp
	g++ -c $(CXXFLAGS) -o obj/main.o src/main.cpp

obj/list_graph.o: src/list_graph.cpp inc/list_graph.hpp inc/graph.hpp
	g++ -c $(CXXFLAGS) -o obj/list_graph.o src/list_graph.cpp

obj/array_graph.o: src/array_graph.cpp inc/array_graph.hpp inc/graph.hpp
	g++ -c $(CXXFLAGS) -o obj/array_graph.o src/array_graph.cpp

obj/algorithm.o: src/algorithm.cpp inc/algorithm.hpp inc/array_graph.hpp inc/list_graph.hpp
	g++ -c $(CXXFLAGS) -o obj/algorithm.o src/algorithm.cpp

clean:
	rm -f obj/*.o grafy

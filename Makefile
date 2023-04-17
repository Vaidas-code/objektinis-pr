CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

allvector: 1.0Vector

1.0Vector: 1.0Vector.o vector.func.o
	$(CXX) $(CXXFLAGS) -o $@ $^

1.0Vector.o: 1.0Vector.cpp Vector.h vector.lib.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

vector.func.o: vector.func.cpp Vector.h vector.lib.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

cleandeque:
	rm -f *.o 1.0Vector

runvector: 1.0Vector
	./1.0Vector

alllist: 1.0list

1.0list: 1.0list.o list.func.o
$(CXX) $(CXXFLAGS) -o $@ $^

1.0list.o: 1.0list.cpp List.h List.lib.h
$(CXX) $(CXXFLAGS) -c $< -o $@

list.func.o: list.func.cpp List.h List.lib.h
$(CXX) $(CXXFLAGS) -c $< -o $@

cleanlist:
rm -f *.o 1.0list

runlist: 1.0list
./1.0list

alldeque: 1.0Deque

1.0Deque: 1.0Deque.o deque.func.o
$(CXX) $(CXXFLAGS) -o $@ $^

1.0Deque.o: 1.0Deque.cpp Deque.h Deque.lib.h
$(CXX) $(CXXFLAGS) -c $< -o $@

deque.func.o: deque.func.cpp Deque.h Deque.lib.h
$(CXX) $(CXXFLAGS) -c $< -o $@

cleandeque:
rm -f *.o 1.0Deque

rundeque: 1.0Deque
./1.0Deque
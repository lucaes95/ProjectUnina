
cc = g++
cflags = -Wall -pedantic -O3 -std=c++20

objects = main.o test.o mytest.o container.o exc1as.o exc1bs.o exc2as.o exc2bs.o exc3s.o

libcon = container/container.hpp container/testable.hpp container/traversable.cpp container/traversable.hpp container/mappable.cpp container/mappable.hpp container/dictionary.cpp container/dictionary.hpp container/linear.cpp container/linear.hpp

libexc = $(libcon) zlasdtest/container/container.hpp zlasdtest/container/testable.hpp zlasdtest/container/traversable.hpp zlasdtest/container/mappable.hpp zlasdtest/container/dictionary.hpp zlasdtest/container/linear.hpp

libexc1a = $(libexc) vector/vector.cpp vector/vector.hpp list/list.cpp list/list.hpp

libexc1b = $(libexc1a) stack/stack.hpp stack/lst/stacklst.cpp stack/lst/stacklst.hpp stack/vec/stackvec.cpp stack/vec/stackvec.hpp queue/queue.hpp queue/lst/queuelst.cpp queue/lst/queuelst.hpp queue/vec/queuevec.cpp queue/vec/queuevec.hpp

libexc2a = $(libexc) iterator/iterator.hpp binarytree/binarytree.cpp binarytree/binarytree.hpp binarytree/lnk/binarytreelnk.cpp binarytree/lnk/binarytreelnk.hpp binarytree/vec/binarytreevec.cpp binarytree/vec/binarytreevec.hpp

libexc2b = $(libexc2a) bst/bst.cpp bst/bst.hpp

libexc3 = $(libexc) hashtable/hashtable.cpp hashtable/hashtable.hpp hashtable/clsadr/htclsadr.cpp hashtable/clsadr/htclsadr.hpp hashtable/opnadr/htopnadr.cpp hashtable/opnadr/htopnadr.hpp

main: $(objects)
	$(cc) $(cflags) $(objects) -o main

clean:
	clear; rm -rfv *.o; rm -fv main

main.o: main.cpp
	$(cc) $(cflags) -c main.cpp

test.o: zlasdtest/test.cpp zlasdtest/test.hpp
	$(cc) $(cflags) -c zlasdtest/test.cpp -o test.o

mytest.o: zmytest/test.cpp zmytest/test.hpp
	$(cc) $(cflags) -c zmytest/test.cpp -o mytest.o

container.o: $(libcon) zlasdtest/container/container.cpp zlasdtest/container/container.hpp
	$(cc) $(cflags) -c zlasdtest/container/container.cpp -o container.o

exc1as.o: $(libexc1a) zlasdtest/exercise1a/simpletest.cpp
	$(cc) $(cflags) -c zlasdtest/exercise1a/simpletest.cpp -o exc1as.o

exc1bs.o: $(libexc1b) zlasdtest/exercise1b/simpletest.cpp
	$(cc) $(cflags) -c zlasdtest/exercise1b/simpletest.cpp -o exc1bs.o

exc2as.o: $(libexc2a) zlasdtest/exercise2a/simpletest.cpp
	$(cc) $(cflags) -c zlasdtest/exercise2a/simpletest.cpp -o exc2as.o

exc2bs.o: $(libexc2b) zlasdtest/exercise2b/simpletest.cpp
	$(cc) $(cflags) -c zlasdtest/exercise2b/simpletest.cpp -o exc2bs.o
exc3s.o: $(libexc3) zlasdtest/exercise3/simpletest.cpp
	$(cc) $(cflags) -c zlasdtest/exercise3/simpletest.cpp -o exc3s.o

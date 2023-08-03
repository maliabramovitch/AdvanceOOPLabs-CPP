CXXFLAGS = -Wall --std=c++1y
LDFLAGS= -std=c++1y
CPP=g++
LD=g++

.SUFFIXES:
.SUFFIXES: .o .cpp

EXEC = fact 

SRCS_fact = Shape.cpp Circle.cpp Rectangle.cpp Triangle.cpp factory_registry.cpp  
OBJS_fact = ${SRCS_fact:.cpp=.o}

all: $(EXEC)

.cpp.o:
	$(CPP) $(CXXFLAGS) -c $<

fact: $(OBJS_fact)
	$(LD) -o $@ $^ $(LDFLAGS) 

clean:
	rm -rf *.o
	rm -rf $(EXEC)

cleanedit:
	rm -rf *~


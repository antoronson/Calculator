CEXE = main
CSRC := $(CEXE).cpp calculator.cpp
COBJ := $(patsubst %.cpp,%.o,$(CSRC))

all:$(CEXE)

$(CEXE):$(COBJ)
	g++ -std=c++11 $(COBJ) -o $@ -lm

main.o:main.cpp
	g++ -std=c++11 -c main.cpp

calculator.o:calculator.cpp
	g++ -std=c++11 -c calculator.cpp

clean:
	rm -f $(CEXE) $(COBJ) 



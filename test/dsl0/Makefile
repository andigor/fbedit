all: run


PRJD:=fbedit/test-dsl-output
STD:=-std=c++1z
PREFIX:=0
DKRI:=gcc #docker image
COMPILER=docker run -v ${PWD}:/usr/src/$(PRJD) -w /usr/src/$(PRJD) $(DKRI) g++ # lazy or second $ like $${PWD} ??

run: $(PREFIX)1.o
	$(COMPILER) $(STD) -o $@ $<

$(PREFIX)1.o: $(PREFIX)1.cpp
	$(COMPILER) $(STD) $< -o $@ -c


.PHONY: clean

clean:
	rm -rf *.o run

all: tinivm

tinivm:
	$(MAKE) -C src

test:
	$(MAKE) -C test

clean:
	rm src/*.o

.PHONY: all tinivm test clean
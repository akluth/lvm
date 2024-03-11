all: lauravm

lauravm:
	$(MAKE) -C src

test:
	$(MAKE) -C test

clean:
	rm src/*.o

.PHONY: all lauravm test clean

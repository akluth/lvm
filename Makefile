all: tinivm

tinivm:
	$(MAKE) -C src

test:
	$(MAKE) -C test

.PHONY: all tinivm test
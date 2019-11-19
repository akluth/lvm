all: tinivm

tinivm:
	$(MAKE) -C src

.PHONY: all tinivm
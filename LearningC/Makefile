.PHONY: all clean

SUBDIRS := bools HeaderFiles HelloWorld Fibonacci

all:
	for dir in $(SUBDIRS); do \
		echo "Building $$dir..."; \
		$(MAKE) -C $$dir; \
	done

clean:
	for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir clean; \
	done
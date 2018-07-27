all: clean build

build:
	gcc uim-status.c -luim -o uim-status

clean:
	rm -f uim-status

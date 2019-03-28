NAME = game

all: install

install:
	gcc  main.c -o $(NAME)
uninstall:
	rm -rf *.o
clean: uninstall
	rm -rf $(NAME)
reinstall: uninstall install

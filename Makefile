NAME = mark

all: install

LIBMX=minilibx_macos/libmlx.a

CC=clang -std=c11 -Wall -Wextra -Werror -Wpedantic

FRAMEWORKS = frameworks/SDL2.framework frameworks/SDL2_mixer.framework

SRC=main drawland keyactions load_levels itoa menu bullet textinitialize init move

SRO=$(addsuffix .o, $(SRC))

install: $(NAME)

$(NAME):
	@mkdir -p $(HOME)/Library/Frameworks
	@cp -rf $(FRAMEWORKS) $(HOME)/Library/Frameworks
	$(CC) -I /usr/local/include \
             -I $(HOME)/Library/Frameworks/SDL2.framework/Headers \
             -I $(HOME)/dlitvinenk/Library/Frameworks/SDL2_mixer.framework/Headers \
             -F $(HOME)/Library/Frameworks \
             -I $(HOME)/Library/Frameworks/SDL2.framework/Headers \
             -I $(HOME)/Library/Frameworks/SDL2_mixer.framework/Headers \
             -F $(HOME)/Library/Frameworks \
                -framework SDL2 \
                -framework SDL2_mixer \
                src/maincode/main.c \
                src/maincode/drawland.c \
                src/maincode/keyactions.c \
                src/maincode/load_levels.c \
                src/funcs/itoa.c \
                src/maincode/menu.c \
                src/maincode/bullet.c \
                src/maincode/textinitialize.c \
                src/maincode/init.c \
                src/maincode/move.c \
                minilibx_macos/libmlx.a \
                -L /usr/local/lib \
                -framework OpenGL \
                -framework Appkit \
                -o $(NAME)

uninstall:
	rm -rf *.o
clean: uninstall
	rm -rf $(NAME)
reinstall: clean install

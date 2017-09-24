OBJS = main.c ArrayList.c Game.c
CC = gcc
INCLUDE_PATHS = -IC:\TDM-GCC-64\include\SDL2
LIBRARY_PATHS = -IC:\TDM-GCC-64\lib\SDL2
COMPILER_FLAGS = -w -Wl,-subsystem,windows
LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2_image -lSDL2
OBJ_NAME = Dama
all : $(OBJS)
	$(CC) $(OBJS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
CXX = g++

OBJS = MuProject.o room.o item.o helper.o parser.o player.o dataHandler.o critter.o graphics.o

SRCS = MuProject.cpp room.cpp item.cpp helper.cpp parser.cpp player.cpp dataHandler.cpp critter.cpp graphics.cpp
HEADERS = room.h item.h helper.h parser.h player.h dataHandler.h critter.h graphics.h


main: ${OBJS} ${HEADERS}
	${CXX} ${OBJS} -o muproject -lncurses

${OBJS}: ${SRCS}
	${CXX} -c $(@:.o=.cpp)
CXX = g++ -std=c++0x -Wall

OBJS = roomDemoV2.o room.o item.o helper.o parser.o player.o 

SRCS = roomDemoV2.cpp room.cpp item.cpp helper.cpp parser.cpp player.cpp
HEADERS = room.h item.h helper.h parser.h player.h


main: ${OBJS} ${HEADERS}
	${CXX} ${OBJS} -o test

${OBJS}: ${SRCS}
	${CXX} -c $(@:.o=.cpp)
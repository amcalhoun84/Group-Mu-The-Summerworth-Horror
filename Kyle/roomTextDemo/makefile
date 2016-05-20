CXX = g++ -std=c++0x

OBJS = tester.o room.o item.o helper.o parser.o player.o 

SRCS = tester.cpp room.cpp item.cpp helper.cpp parser.cpp player.cpp
HEADERS = room.h item.h helper.h parser.h player.h


main: ${OBJS} ${HEADERS}
	${CXX} ${OBJS} -o test

${OBJS}: ${SRCS}
	${CXX} -c $(@:.o=.cpp)
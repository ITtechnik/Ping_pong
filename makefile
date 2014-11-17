CC = g++
SOURCES = ping_pong.cc
FILESPACK = $(SOURCES) Makefile

gcc:
	$(CC) -o ping_ping $(SOURCES)

clang:
	clang++ -o ping_pong $(SOURCES) -std=c++11
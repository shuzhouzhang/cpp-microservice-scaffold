ALL: simple global local
simple: simple.cc
	g++ -o $@ $^ -lgtest

global: global.cc
	g++ -o $@ $^ -lgtest

local: local.cc
	g++ -o $@ $^ -lgtest
clean:
	rm -f simple global local
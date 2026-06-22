serialize:serialize.cc person.pb.cc
	g++ -std=c++17 $^ -o $@ -lprotobuf -lpthread
.PHONY: clean
clean:
	rm -f serialize
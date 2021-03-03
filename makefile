empty:
	g++ task1.cpp -o cam.o -pthread -std=c++11 `pkg-config --cflags --libs opencv` && ./cam.o empty.jpg
traffic:
	g++ task1.cpp -o cam.o -pthread -std=c++11 `pkg-config --cflags --libs opencv` && ./cam.o traffic.jpg
compile:
	g++ task1.cpp -o cam.o -pthread -std=c++11 `pkg-config --cflags --libs opencv` 
clean:
	rm task1

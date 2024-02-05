dependency:
	cd build && cmake .. && make

prepare:
	rm -rf build
	mkdir build

stream:
	clear && make prepare && make dependency
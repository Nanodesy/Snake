build:
	cmake -B build -S .

compile: build
	cmake --build build

run: compile
	./build/bin/Snake

clean:
	rm -rf build

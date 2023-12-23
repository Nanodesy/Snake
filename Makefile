build:
	cmake -B build -S .

compile: build
	cmake --build build

static-analysis:
	cppcheck --std=c++17 src/**/*.cpp include/**/*.hpp

run: compile static-analysis
	./build/bin/Snake

clean:
	rm -rf build

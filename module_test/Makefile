CXX := clang++

CXXFLAGS := -Wall -Wextra

main.ll: my_mod.pcm
	clang++ -std=c++20 test.cpp -fmodule-file=MyModule=my_mod.pcm my_mod.pcm -S -emit-llvm

main: my_mod.pcm
	clang++ -std=c++20 test.cpp -fmodule-file=MyModule=my_mod.pcm my_mod.pcm -o $@

my_mod.pcm:
	clang++ -std=c++20 my_mod.cppm --precompile -o my_mod.pcm
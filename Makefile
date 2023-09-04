hello:
	g++ -I./include/ -I. interface.cpp -L ./out/Release-x64 -lskia -lX11 -ldl -lGL -lglfw

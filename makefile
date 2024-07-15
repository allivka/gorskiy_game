
.PHONY: all clean
links = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
cc = g++
sources = sources/*


all:
	$(cc) $(sources) -o game -Wall $(links)
clean:
	rm -rf game
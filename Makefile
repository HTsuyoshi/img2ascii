img2ascii: ./src/img2ascii.cpp
	g++ `Magick++-config --cxxflags --cppflags` -O2 -o ./bin/img2ascii $^ \
  `Magick++-config --ldflags --libs` 

debug:
	g++ `Magick++-config --cxxflags --cppflags` -g -O2 -o ./bin/img2ascii img2ascii.cpp \
  `Magick++-config --ldflags --libs` 

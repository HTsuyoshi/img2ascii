# syntax=docker/dockerfile:1

FROM gcc:10.4.0

WORKDIR /img2ascii
COPY CMakeLists.txt /img2ascii/
COPY src /img2ascii/src
COPY bin /img2ascii/bin

RUN apt-get update && apt-get install graphicsmagick-libmagick-dev-compat -y

CMD g++ `Magick++-config --cxxflags --cppflags` -g -O2 -o ./bin/img2ascii src/img2ascii.cpp `Magick++-config --ldflags --libs`

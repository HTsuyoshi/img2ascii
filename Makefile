img2ascii: ./src/img2ascii.cpp
	echo 'Building gcc-img2ascii image...'
	@docker build --tag gcc-img2ascii:1.0 .
	echo 'Compiling img2ascii...'
	@docker run --rm -it --user="$$(id -u):$$(id -g)" --net=none -v "$$(pwd):/img2ascii" gcc-img2ascii:1.0

debug:
	g++ \
	-I/usr/include/ImageMagick-7 -fopenmp -DMAGICKCORE_HDRI_ENABLE=1 -DMAGICKCORE_QUANTUM_DEPTH=16 \
	-I/usr/include/ImageMagick-7 -fopenmp -DMAGICKCORE_HDRI_ENABLE=1 -DMAGICKCORE_QUANTUM_DEPTH=16 \
	-g -O2 -o ./bin/img2ascii img2ascii.cpp \
	-lMagick++-7.Q16HDRI -lMagickWand-7.Q16HDRI -lMagickCore-7.Q16HDRI \
	-lMagick++-7.Q16HDRI -lMagickWand-7.Q16HDRI -lMagickCore-7.Q16HDRI




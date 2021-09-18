#include <Magick++.h> 
#include <iostream> 
#include <stdio.h>
#include <cstring>

#include <typeinfo>

using namespace std; 
using namespace Magick; 

#include "braille_data.h"
#include "strings.h"
#include "argh.h"

int main(int argc,char **argv) 
{ 
    Image image;
    try { 
        argh::parser cmdl(argc, argv);

        /* No arguments */
        if (!cmdl(1)) {
            cout << arguments << endl;
            cout << usage << endl;
            return 1;
        }

        bool first_arg = true;
        double average = 0;
        int max_columns, 
            max_rows,
            columns,
            rows,
            scale;

        ColorGray cor;

        /* Iterate over images */
        for (auto& images : cmdl) {

            if (first_arg) {
                first_arg = false;
                continue;
            }

            /* Read a file into image object */
            image.read( images );

            /* Scale image */
            cmdl({"-s", "--scale"}, 100) >> scale;
            image.scale(Geometry(scale, scale));
            max_columns = image.columns();
            max_rows = image.rows();

            /* Get average */
            for(int i=0; i<max_columns; i++) {
                for(int j=0; j<max_rows; j++) {
                    cor = image.pixelColor(i,j);
                    average += cor.shade();
            }}
            average = average / (max_rows * max_columns);

            /* Create ascii art */
            columns = (int)((max_columns/2)+1);
            rows = (int)((max_rows/4)+1);
            string ascii_art[rows][columns];
            for(int i=0; i<max_columns; i+=2) {
                for(int j=0; j<max_rows; j+=4) {

                    int character = 0;
                    for(int r=0; r<4; r++) {
                        for(int c=0; c<2; c++) {
                            cor = image.pixelColor(i + c,j + r);
                            if(cor.shade() > average) {
                                character += 1 << (r*2 + c);
                            }
                    }}

                    ascii_art[(int)(j/4)][(int)(i/2)] = (string) braille_data[character];
            }}

            for(int i=0; i<rows; i++) {
                for(int j=0; j<columns; j++) {
                    cout << ascii_art[i][j];
                }
                cout << endl;
            }
        }
    } 
    catch( Exception &error_ ) 
    { 
        cout << "Caught exception: " << error_.what() << endl; 
        return 1; 
    } 
    return 0; 
} 

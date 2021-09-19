#include <Magick++.h> 
#include <filesystem>
#include <iostream> 
#include <fstream> 
#include <cstring>

using namespace std; 
using namespace Magick; 
using namespace filesystem; 

#include "braille_data.h"
#include "strings.h"
#include "argh.h"

#define waifu_directory "/tmp/waifu/"
#define waifu_file(a) "/tmp/waifu/" + to_string(a)

/* File manipulation */

void print_buff(int file_index) {
    ifstream file;
    file.open(waifu_file(file_index), ios::in);

    if (file.is_open()) {
        string line;
        while(getline(file, line))
            cout << line << endl;
    }
    file.close();
}

int main(int argc,char **argv) { 
    try { 
        argh::parser cmdl(argc, argv);
        Image image;
        ColorGray cor;

        bool first_arg = true;
        double threshold = 0;
        int max_columns, 
            max_rows,
            columns,
            rows,
            scale,
            file_index;

        /* --- Set environment --- */

        /* Create folder to ascii art*/
        path folder{waifu_directory};
        if (!exists(folder))
            create_directory(folder);

        /* --- Errors --- */

        /* No arguments */
        if (!cmdl(1) && !cmdl({"-b","--buffer"})) {
            cout << arguments;
            cout << usage;
            return 1;
        }


        /* --- Options --- */

        /* Print from buffer */
        if (cmdl({"-b","--buffer"})) {
            cmdl({"-b","--buffer"}) >> file_index;
            if (exists(waifu_file(file_index))) {
                print_buff(file_index);
                return 0;
            }
        }

        /* Clear buffer */
        if (cmdl({"-c","--clear"})) {
            for (auto const& file: directory_iterator{folder})
                remove(file);
            cout << cleared;
            return 0;
        }

        /* Set threshold */
        if (cmdl({"-t","--threshold"}))
            cmdl({"-t","--threshold"}) >> threshold;

        /* Scale image */
        cmdl({"-s", "--scale"}, 200) >> scale;

        /* --- Iterate over args --- */

        for (auto& images : cmdl) {

            if (first_arg) {
                first_arg = false;
                continue;
            }

            /* Read a file into image object */
            image.read( images );

            image.scale(Geometry(scale, scale));

            max_columns = image.columns();
            max_rows = image.rows();

            /* Get average */
            if (!cmdl({"-t","--threshold"})) {
                for (int i=0; i<max_columns; i++) {
                    for (int j=0; j<max_rows; j++) {
                        cor = image.pixelColor(i,j);
                        threshold += cor.shade();
                }}
                threshold = threshold / (max_rows * max_columns);
            }

            columns = (int)((max_columns/2)+1);
            rows = (int)((max_rows/4)+1);

            /* Create ascii art */
            string ascii_art[rows][columns];
            for (int i=0; i<max_columns; i+=2) {
                for (int j=0; j<max_rows; j+=4) {

                    int character = 0;
                    for (int r=0; r<4; r++) {
                        for (int c=0; c<2; c++) {
                            cor = image.pixelColor(i + c,j + r);
                            if (cor.shade() > threshold)
                                character += 1 << (r*2 + c);
                    }}

                    ascii_art[(int)(j/4)][(int)(i/2)] = (string) braille_data[character];
            }}

            /* Print the ascii art */
            for (int i=0; i<rows; i++) {
                for (int j=0; j<columns; j++) {
                    cout << ascii_art[i][j];
                }
                cout << endl;
            }

            /* Save in a buffer */
            if (cmdl({"-b","--buffer"})) {
                cmdl({"-b", "--buffer"}, 1) >> file_index;

                if (exists(waifu_file(file_index))) {
                    cout << buff_used;
                    return 1;
                }

                ofstream file;
                file.open(waifu_file(file_index), ios::out);

                for (int i=0; i<rows; i++) {
                    for (int j=0; j<columns; j++) {
                        file << ascii_art[i][j];
                    }
                    file << endl;
                }
                file.close();
        }}
    } catch ( Exception &error_ ) { 
        cout << "Caught exception: " << error_.what() << endl; 
        return 1; 
    } 
    return 0; 
} 

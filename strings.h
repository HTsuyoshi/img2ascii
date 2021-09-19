
string arguments = "Must provide at least 1 file\n";
string example_size = "Usage: img2ascii -s=100\n";
string cleared = "Buffer is clear\n";
string buff_used = "This Buffer is already in use\n";

string usage = "Usage:\n"
"\timg2ascii [options] <files> ...\n"
"\n"
"OPTIONS\n"
"\t-h, --help\t\tshow this message\n"
"\t-s, --scale\t\tchoose output size\n"
"\t-t, --threshold\t\tchoose output threshold 0 to 1\n"
"\t-b, --buffer\t\tprint or save output in a buffer\n"
"\n"
"EXAMPLES\n"
"\n"
"\tprint ascii art of an image:\n"
"\t$ img2ascii image.png \n"
"\n"
"\tprint ascii art of an image with 0.5 of threshold:\n"
"\t$ img2ascii image.png -t=0.5\n";
"\n"

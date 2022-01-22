
string arguments = "Must provide at least 1 file\n";
string example_size = "Usage: img2ascii -s=100\n";
string cleared = "Buffer is clear\n";
string buff_used = "This Buffer is already in use\n";

string usage = "Copyright (c) 2017, Adi Shavit\n"
"All rights reserved.\n"

"Redistribution and use in source and binary forms, with or without\n"
"modification, are permitted provided that the following conditions are met:\n"

" * Redistributions of source code must retain the above copyright notice,\n"
"   this list of conditions and the following disclaimer.\n"
" * Redistributions in binary form must reproduce the above copyright\n"
"   notice, this list of conditions and the following disclaimer in the\n"
"   documentation and/or other materials provided with the distribution.\n"
" * Neither the name of  nor the names of its contributors may be used to\n"
"   endorse or promote products derived from this software without specific\n"
"   prior written permission.\n"

"THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS \"AS IS\n"
"AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE\n"
"IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE\n"
"ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE\n"
"LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR\n"
"CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF\n"
"SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS\n"
"INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN\n"
"CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)\n"
"ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE\n"
"POSSIBILITY OF SUCH DAMAGE.\n\n"
"Usage:\n"
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
"\t$ img2ascii image.png -t=0.5\n"
"\n";

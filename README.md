# cCode
My C codes. For study only.
When we include at header <code><cs50.h>, we need link this library with <code>-lcs50</code>, like we do with <math.h> <code>-lm</code>, so:
  
<code>$ gcc -o file file.c -lm -lcs50</code>

or if you install cs50.h in your computer, you can use 

<code>$ make [file]</code>

and <code>file.c</code> will be compiled as <code>$ gcc -o file file.c -lm -lcs50</code> automaticly

at: https://github.com/cs50/libcs50#cs50-library-for-c
CS50 Library for C
Build Status

Development
<code>make</code>: builds dynamic library

<code>make deb</code>: builds source deb

<code>make install</code>: installs the library under /usr/local by default (set DESTDIR to change that)

Installation

Ubuntu

<code>$ curl -s https://packagecloud.io/install/repositories/cs50/repo/script.deb.sh | sudo bash
$ sudo apt-get install libcs50</code>

Fedora

<code>$ curl -s https://packagecloud.io/install/repositories/cs50/repo/script.rpm.sh | sudo bash
$ yum install libcs50</code>

From Source (Linux and Mac)

Download the latest release from https://github.com/cs50/libcs50/releases

<code>Extract libcs50-*.*
cd libcs50-*
sudo make install</code>
By default, we install to <code>/usr/local</code>. If you'd like to change the installation location, run <code>sudo DESTDIR=/path/to/install make install</code> as desired.

Troubleshooting
If, when compiling a program, you see <code>/usr/bin/ld: cannot find -lcs50: Add export LIBRARY_PATH=/usr/local/lib to your .bashrc</code>.
If, when compiling a program, you see <code>fatal error: 'cs50.h' file not found: Add export C_INCLUDE_PATH=/usr/local/include to your .bashrc</code>.
If, when executing a program, you see <code>error while loading shared libraries: libcs50.so.8: cannot open shared object file: No such file or directory: Add export LD_LIBRARY_PATH=/usr/local/lib to your .bashrc</code>.
Close and reopen any terminal windows.

Usage
Link with <code>-lcs50</code>.

<code>#include <cs50.h>

...
char c = get_char("Prompt: ");
double d = get_double("Prompt: ");
float f = get_float("Prompt: ");
int i = get_int("Prompt: ");
long l = get_long("Prompt: ");
string s = get_string("Prompt: ");

// deprecated as of fall 2017
long long ll = get_long_long("Prompt: ");</code>
Documentation
See <code>man get_*</code> after installation, or CS50 Reference!

TODO
Add tests.
Contributors
Chad Sharp
Emrul Hasan Zawad
Ivan Jasenov
Kareem Zidane

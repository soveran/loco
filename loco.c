/*

Copyright (c) 2014 Michel Martens

Permission is hereby granted, free of charge, to any person
obtaining a copy of this software and associated documentation
files (the "Software"), to deal in the Software without
restriction, including without limitation the rights to use, copy,
modify, merge, publish, distribute, sublicense, and/or sell copies
of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.

*/

#include <stdio.h>
#include <ctype.h>

int main(void) {
	char c;
	int s = 0; /* state */
	int t = 0; /* count */

	/*
	   0 == pending
	   1 == discard
	   2 == confirm
	*/

	while((c = (char) getchar()) != EOF) {
		switch (s) {

		case 0:
			if (!isspace(c)) {
				s = (c == '#' ? 1 : 2);
			}

			break;

		case 1:
			if (c == '\n') {
				s = 0;
			}

			break;

		case 2:
			if (c == '\n') {
				t = t + 1;
				s = 0;
			}

			break;
		}
	}

	printf("%d\n", t);
	return 0;
}

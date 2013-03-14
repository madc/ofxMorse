#ofxMorse
ofxMorse is an addon for openFrameworks by Matthias Esterl. The original code was written in C for Arduino and can be found in this [GIST](https://gist.github.com/4474559). Both versions (oF and Arduino) are fully compatible.
To meet the official standards for morse code, ofxMorse has been build after the specs, that can be found on the [Wikipedia page on Morse code](http://en.wikipedia.org/wiki/Morse_code).
All available characters are defined in [src/ofxMorse.cpp](src/ofxMorse.cpp).

## Usage

~~~~
ofxMorse Morse;
string myWord = "I have two guns, one for each of ya.";
    
string encodedString = Morse.encode( myWord );
//Output: ..       .... .- ...- .       - .-- ---       --. ..- -. ... --..--       --- -. .       ..-. --- .-.       . .- -.-. ....       --- ..-.       -.-- .- .-.-.- 
string decodedString = Morse.decode( encodedString );
//Output: I HAVE TWO GUNS, ONE FOR EACH OF YA.
~~~~

See [example-basic/](example-basic/) for further infos.

## License
ofxMorse is available under the MIT License.
https://en.wikipedia.org/wiki/Mit_license
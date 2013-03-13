#ofxMorse
ofxMorse is an addon for openFrameworks by Matthias Esterl. The original software, written in C for Arduino, can be found in this [GIST](https://gist.github.com/4474559). Both are fully compatible.
To meet the official standards for morse code, ofxMorse has been build after the specs, that can be found on the [Wikipedia page on Morse code](http://en.wikipedia.org/wiki/Morse_code). It includes sveral non-standard special characters. All possible characters are defined in *ofxMorse.cpp*.

## Useage

~~~~
ofxMorse Morse;
string myWord = "I have two guns, one for each of ya.";
    
string encodedString = Morse.encode( myWord );
string decodedString = Morse.decode( encodedString );
~~~~

See *example-basic/* for further infos.

## License
ofxMorse is available under the MIT License.
https://en.wikipedia.org/wiki/Mit_license
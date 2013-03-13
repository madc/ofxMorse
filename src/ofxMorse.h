#include <map>
#include <string>

using namespace std;

class ofxMorse {
public:
	ofxMorse();
	
    string encode( string );
    string decode( string );

    //Build a struct with the morse code mapping
    map<char, string> MorseMap;
};
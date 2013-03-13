#include "ofxMorse.h"

using namespace std;

ofxMorse::ofxMorse() {
    MorseMap['>'] = "-.-.-";	// Starting Signal
    MorseMap['<'] = "...-.-";   // End of work, end signal
    
    MorseMap['A'] = ".-";
    MorseMap['€'] = ".-.-";
    MorseMap['B'] = "-...";
    MorseMap['C'] = "-.-.";
    MorseMap['D'] = "-..";
    MorseMap['E'] = ".";
    MorseMap['F'] = "..-.";
    MorseMap['G'] = "--.";
    MorseMap['H'] = "....";
    MorseMap['I'] = "..";
    MorseMap['J'] = ".---";
    MorseMap['K'] = ".-.-";
    MorseMap['L'] = ".-..";
    MorseMap['M'] = "--";
    MorseMap['N'] = "-.";
    MorseMap['O'] = "---";
    MorseMap['…'] = "---.";
    MorseMap['P'] = ".--.";
    MorseMap['Q'] = "--.-";
    MorseMap['R'] = ".-.";
    MorseMap['S'] = "...";
    MorseMap['T'] = "-";
    MorseMap['U'] = "..-";
    MorseMap['†'] = "..--";
    MorseMap['V'] = "...-";
    MorseMap['W'] = ".--";
    MorseMap['X'] = "-..-";
    MorseMap['Y'] = "-.--";
    MorseMap['Z'] = "--..";
    MorseMap[' '] = "     ";    //Gap between word, seven units
    
    MorseMap['1'] = ".----";
    MorseMap['2'] = "..---";
    MorseMap['3'] = "...--";
    MorseMap['4'] = "....-";
    MorseMap['5'] = ".....";
    MorseMap['6'] = "-....";
    MorseMap['7'] = "--...";
    MorseMap['8'] = "---..";
    MorseMap['9'] = "----.";
    MorseMap['0'] = "-----";
    
    MorseMap['.'] = ".-.-.-";
    MorseMap[','] = "--..--";
    MorseMap['?'] = "..--..";
    MorseMap['!'] = "-.-.--";
    MorseMap[':'] = "---...";
    MorseMap[';'] = "-.-.-.";
    MorseMap['('] = "-.--.";
    MorseMap[')'] = "-.--.-";
    MorseMap['"'] = ".-..-.";
    MorseMap['@'] = ".--.-.";
    MorseMap['&'] = ".-...";
}

string ofxMorse::encode( string string) {
    size_t i, j;
    std::string encodedString = "";
    
	for( i = 0; string[i]; ++i )
	{
        map<char, std::string>::const_iterator it = MorseMap.find(toupper(string[i]));
        if ( it != MorseMap.end() ) {
            encodedString += it->second;
        }
        
		encodedString += " "; //Add tailing space to seperate the chars
	}
    
	return encodedString;
}

string ofxMorse::decode( string morse ) {
    string decodedString = "";
    
	size_t lastPos = 0;
	size_t pos = morse.find_first_of(' ');
	
	while( lastPos <= morse.find_last_of(' ') )
	{
        for (map<char, string>::const_iterator it = MorseMap.begin(); it != MorseMap.end(); ++it )
        {
            if (it->second == morse.substr(lastPos, (pos-lastPos)))
            {
                decodedString += it->first;
            }            
        }
        
		lastPos = pos+1;
		pos = morse.find(' ', lastPos);
        
		// Handle white-spaces between words (7 spaces)
		while( morse[lastPos] == ' ' && morse[(pos+1)] == ' ' )
		{
			pos ++;
		}
	}
    
	return decodedString;
}

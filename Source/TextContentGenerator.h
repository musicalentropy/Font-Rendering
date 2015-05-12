/*
  ==============================================================================

    Text Content Generator (header file)
	Made by Ivan Cohen, Copyright (c) 2015

  ==============================================================================
*/

#ifndef TEXTCONTENTGEN_H_INCLUDED
#define TEXTCONTENTGEN_H_INCLUDED


#include "../JuceLibraryCode/JuceHeader.h"




// Class to generate Text Content
// =============================================================================
class TextContentGenerator
{
public:
	TextContentGenerator();
	~TextContentGenerator();

	static const String getLoremIpsum(int numParagraphs=1);
	static const String getQuickBrownFox(int numTimes=1);
	static const String getASCIICharacters(int numTimes=1);

private:

};




#endif
/*
  ==============================================================================

    JUCE Colours Library Manager (cpp file)
	Made by Ivan Cohen, Copyright (c) 2015

  ==============================================================================
*/

#include "ColourLibraryManager.h"


// Class to manage all the colours included in JUCE library
// ================================================================================
ColourLibraryManager::ColourLibraryManager()
{	createDatabase();
}

ColourLibraryManager::~ColourLibraryManager()
{	theStringDatabase.clear();
	theColourDatabase.clear();
}

const int ColourLibraryManager::getNumEntries()
{	return theStringDatabase.size();
}

StringArray *ColourLibraryManager::getStringDatabase()
{	return &theStringDatabase;
}

juce::Array <Colour> *ColourLibraryManager::getColourDatabase()
{	return &theColourDatabase;
}

const String ColourLibraryManager::getStringEntry(int index)
{	jassert(index >= 0 && index < theStringDatabase.size());
	return theStringDatabase[index];
}

const Colour ColourLibraryManager::getColourEntry(int index)
{	jassert(index >= 0 && index < theColourDatabase.size());
	return theColourDatabase[index];
}

void ColourLibraryManager::createDatabase()
{
	theStringDatabase.add("aliceblue");
	theStringDatabase.add("antiquewhite");
	theStringDatabase.add("aqua");
	theStringDatabase.add("aquamarine");
	theStringDatabase.add("azure");
	theStringDatabase.add("beige");
	theStringDatabase.add("bisque");
	theStringDatabase.add("black");
	theStringDatabase.add("blanchedalmond");
	theStringDatabase.add("blue");
	theStringDatabase.add("blueviolet");
	theStringDatabase.add("brown");
	theStringDatabase.add("burlywood");
	theStringDatabase.add("cadetblue");
	theStringDatabase.add("chartreuse");
	theStringDatabase.add("chocolate");
	theStringDatabase.add("coral");
	theStringDatabase.add("cornflowerblue");
	theStringDatabase.add("cornsilk");
	theStringDatabase.add("crimson");
	theStringDatabase.add("cyan");
	theStringDatabase.add("darkblue");
	theStringDatabase.add("darkcyan");
	theStringDatabase.add("darkgoldenrod");
	theStringDatabase.add("darkgrey");
	theStringDatabase.add("darkgreen");
	theStringDatabase.add("darkkhaki");
	theStringDatabase.add("darkmagenta");
	theStringDatabase.add("darkolivegreen");
	theStringDatabase.add("darkorange");
	theStringDatabase.add("darkorchid");
	theStringDatabase.add("darkred");
	theStringDatabase.add("darksalmon");
	theStringDatabase.add("darkseagreen");
	theStringDatabase.add("darkslateblue");
	theStringDatabase.add("darkslategrey");
	theStringDatabase.add("darkturquoise");
	theStringDatabase.add("darkviolet");
	theStringDatabase.add("deeppink");
	theStringDatabase.add("deepskyblue");
	theStringDatabase.add("dimgrey");
	theStringDatabase.add("dodgerblue");
	theStringDatabase.add("firebrick");
	theStringDatabase.add("floralwhite");
	theStringDatabase.add("forestgreen");
	theStringDatabase.add("fuchsia");
	theStringDatabase.add("gainsboro");
	theStringDatabase.add("gold");
	theStringDatabase.add("goldenrod");
	theStringDatabase.add("grey");
	theStringDatabase.add("green");
	theStringDatabase.add("greenyellow");
	theStringDatabase.add("honeydew");
	theStringDatabase.add("hotpink");
	theStringDatabase.add("indianred");
	theStringDatabase.add("indigo");
	theStringDatabase.add("ivory");
	theStringDatabase.add("khaki");
	theStringDatabase.add("lavender");
	theStringDatabase.add("lavenderblush");
	theStringDatabase.add("lemonchiffon");
	theStringDatabase.add("lightblue");
	theStringDatabase.add("lightcoral");
	theStringDatabase.add("lightcyan");
	theStringDatabase.add("lightgoldenrodyellow");
	theStringDatabase.add("lightgreen");
	theStringDatabase.add("lightgrey");
	theStringDatabase.add("lightpink");
	theStringDatabase.add("lightsalmon");
	theStringDatabase.add("lightseagreen");
	theStringDatabase.add("lightskyblue");
	theStringDatabase.add("lightslategrey");
	theStringDatabase.add("lightsteelblue");
	theStringDatabase.add("lightyellow");
	theStringDatabase.add("lime");
	theStringDatabase.add("limegreen");
	theStringDatabase.add("linen");
	theStringDatabase.add("magenta");
	theStringDatabase.add("maroon");
	theStringDatabase.add("mediumaquamarine");
	theStringDatabase.add("mediumblue");
	theStringDatabase.add("mediumorchid");
	theStringDatabase.add("mediumpurple");
	theStringDatabase.add("mediumseagreen");
	theStringDatabase.add("mediumslateblue");
	theStringDatabase.add("mediumspringgreen");
	theStringDatabase.add("mediumturquoise");
	theStringDatabase.add("mediumvioletred");
	theStringDatabase.add("midnightblue");
	theStringDatabase.add("mintcream");
	theStringDatabase.add("mistyrose");
	theStringDatabase.add("navajowhite");
	theStringDatabase.add("navy");
	theStringDatabase.add("oldlace");
	theStringDatabase.add("olive");
	theStringDatabase.add("olivedrab");
	theStringDatabase.add("orange");
	theStringDatabase.add("orangered");
	theStringDatabase.add("orchid");
	theStringDatabase.add("palegoldenrod");
	theStringDatabase.add("palegreen");
	theStringDatabase.add("paleturquoise");
	theStringDatabase.add("palevioletred");
	theStringDatabase.add("papayawhip");
	theStringDatabase.add("peachpuff");
	theStringDatabase.add("peru");
	theStringDatabase.add("pink");
	theStringDatabase.add("plum");
	theStringDatabase.add("powderblue");
	theStringDatabase.add("purple");
	theStringDatabase.add("red");
	theStringDatabase.add("rosybrown");
	theStringDatabase.add("royalblue");
	theStringDatabase.add("saddlebrown");
	theStringDatabase.add("salmon");
	theStringDatabase.add("sandybrown");
	theStringDatabase.add("seagreen");
	theStringDatabase.add("seashell");
	theStringDatabase.add("sienna");
	theStringDatabase.add("silver");
	theStringDatabase.add("skyblue");
	theStringDatabase.add("slateblue");
	theStringDatabase.add("slategrey");
	theStringDatabase.add("snow");
	theStringDatabase.add("springgreen");
	theStringDatabase.add("steelblue");
	theStringDatabase.add("tan");
	theStringDatabase.add("teal");
	theStringDatabase.add("thistle");
	theStringDatabase.add("tomato");
	theStringDatabase.add("turquoise");
	theStringDatabase.add("violet");
	theStringDatabase.add("wheat");
	theStringDatabase.add("white");
	theStringDatabase.add("whitesmoke");
	theStringDatabase.add("yellow");
	theStringDatabase.add("yellowgreen");

	for(int i=0; i<theStringDatabase.size(); i++)
		theColourDatabase.add(Colours::findColourForName(theStringDatabase[i], Colours::white));
}

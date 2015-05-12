/*
  ==============================================================================

    Text Content Generator (cpp file)
	Made by Ivan Cohen, Copyright (c) 2015

  ==============================================================================
*/

#include "TextContentGenerator.h"


// Class to generate Text Content
// =============================================================================

TextContentGenerator::TextContentGenerator()
{
}

TextContentGenerator::~TextContentGenerator()
{
}

const String TextContentGenerator::getLoremIpsum(int numParagraphs)
{	String strText = String::empty;

	for(int i=0; i<numParagraphs; i += 5)
	{	
		if (i > 0) strText += "\n\n";

		if (i < numParagraphs)
		{	strText += "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Integer malesuada pharetra nibh. Morbi ac imperdiet sapien. In porta tortor ac leo iaculis, a venenatis sapien blandit. Fusce id ex neque. Nam id nisi pulvinar nisi posuere molestie in at lectus. Donec efficitur est in massa rhoncus, eget rhoncus dui hendrerit. In porttitor feugiat odio non gravida. Quisque quis arcu sit amet nunc congue lobortis et nec massa. Curabitur luctus mi sed rhoncus interdum. Fusce luctus varius orci nec volutpat. Donec id maximus velit. Cras eu pretium nibh. Donec et congue nibh, a lacinia diam. Nulla eu ultricies ipsum, at ullamcorper enim.";
		}
		if (i + 1 < numParagraphs)
		{	strText += "\n\n";
			strText += "Nunc dignissim condimentum mauris, vitae tincidunt lacus pellentesque ut. Nulla bibendum eros ut dignissim sagittis. Fusce blandit neque ut fringilla vestibulum. Donec ultricies dictum pretium. Maecenas sit amet metus fringilla, suscipit nisi non, auctor odio. Vivamus tellus ex, suscipit quis lectus fringilla, pharetra dignissim lectus. Donec semper maximus dapibus. Donec pretium molestie quam eget commodo. Sed pellentesque imperdiet rutrum. Nullam ac arcu porttitor ex bibendum consequat. Phasellus tincidunt, felis ut egestas volutpat, nisi risus porttitor arcu, ac fringilla ipsum nunc eu augue. Cras at placerat lorem. Quisque in urna tellus. Maecenas vitae diam et orci ornare posuere molestie in dolor. Ut vehicula quam mattis, consectetur massa et, vestibulum arcu. Morbi consequat elit ac blandit finibus.";
		}
		if (i + 2 < numParagraphs)
		{	strText += "\n\n";
			strText += "Cum sociis natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus. Maecenas ultrices mi feugiat, tincidunt lorem mattis, pellentesque metus. Curabitur scelerisque risus quis odio ornare bibendum. Nam convallis feugiat ante sed auctor. Sed at consectetur turpis. Proin eu massa vel quam mollis euismod. Nulla quis feugiat mauris. Pellentesque pretium fringilla libero vel condimentum.";
		}
		if (i + 3 < numParagraphs)
		{	strText += "\n\n";
			strText += "Mauris rutrum justo risus, eget gravida nisl venenatis vitae. Fusce tempor finibus lectus, sit amet sollicitudin nulla laoreet et. Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia Curae; Duis urna turpis, aliquet ut nunc vitae, feugiat semper est. Maecenas sit amet quam eu turpis tincidunt facilisis. Sed leo dui, gravida eget augue aliquet, mollis tincidunt ligula. Nulla a justo vitae felis varius varius. Nam vulputate metus sem, in porta mauris interdum sit amet.";
		}
		if (i + 4 < numParagraphs)
		{	strText += "\n\n";
			strText += "Suspendisse potenti. Proin malesuada, mauris ut posuere rutrum, quam risus hendrerit nibh, in aliquam eros neque a sem. In porttitor rutrum magna. Fusce molestie gravida nulla, a lobortis ante dapibus eget. Ut tristique arcu ut eleifend posuere. Praesent consequat facilisis neque, ut dignissim lacus cursus sed. Nulla dictum molestie arcu, sit amet euismod tortor vestibulum eu. Proin eu varius risus. Donec ut enim pharetra, posuere mi sit amet, varius justo. Pellentesque nisi ex, consectetur non nisl sit amet, venenatis interdum risus. Proin est nisi, imperdiet feugiat placerat sit amet, aliquam volutpat nisi. Sed venenatis lorem sit amet condimentum laoreet. Suspendisse a elit pulvinar leo dignissim auctor. Mauris sollicitudin cursus accumsan. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. Integer non imperdiet ligula, a ultricies dui. ";
		}
	}

	return strText;
}

const String TextContentGenerator::getQuickBrownFox(int numTimes)
{	String strTemp = String::empty;

	for(int i=0; i<numTimes; i++)
		strTemp += "The quick brown fox jumps over the lazy dog. ";
	
	return strTemp;
}

const String TextContentGenerator::getASCIICharacters(int numTimes)
{	String strTemp = String::empty;

	String strModel = String::empty;
	for(int i=33; i<147; i++)
		strModel = strModel + String::charToString(i);

	for(int i=0; i<numTimes; i++)
		strTemp += strModel;

	return strTemp;
}








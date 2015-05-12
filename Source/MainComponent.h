/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#ifndef MAINCOMPONENT_H_INCLUDED
#define MAINCOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

#include "TextContentGenerator.h"
#include "CustomLookAndFeel.h"
#include "ColourLibraryManager.h"



//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainContentComponent   : public Component, public ComboBox::Listener, public Button::Listener
{
public:
    //==============================================================================
    MainContentComponent();
    ~MainContentComponent();

    void paint (Graphics&);
    void resized();

	void comboBoxChanged(ComboBox *comboBoxThatHasChanged);
	void buttonClicked(Button *button);

	// I'm trying to improve the drawFittedText function, with the following features :
	// - Does not fit the text anymore (not the case for Fitted even with extreme parameters)
	// - Keeps the Justification behaviour in the parameters (not the case for Multi-Line)
	// - The text is rendered only inside the specified rectangle (not the case for Fitted)
	void drawMultiLineTextIntoRectangle(Graphics &g, const String& text, const Rectangle<int>& area, Justification justification);

	void updateTextToDisplay();

	void updateSoftwareRenderers();

	bool loadCustomFont(File fileFont);

private:
    //==============================================================================
    String strTextToDisplay;
	juce::Array <Font> fonts;

	Font theCustomFont;
	bool hasCustomFontBeenLoaded;

	ComboBox *comboFontName, *comboFontHeight, *comboJustification;
	ComboBox *comboContent, *comboBackgroundColour, *comboTextColour;
	ComboBox *comboRendering;
	ComboBox *comboKerning, *comboScale;

	ToggleButton *toggleBold, *toggleItalic, *toggleUnderlined;

	CustomLookAndFeel theLF;
	ColourLibraryManager theColourManager;

	#if JUCE_OPENGL
		OpenGLContext openGLContext;
	#endif
	
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent);
};


#endif  // MAINCOMPONENT_H_INCLUDED

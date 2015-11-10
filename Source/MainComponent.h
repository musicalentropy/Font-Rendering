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
class MainContentComponent : public Component, public ComboBox::Listener, public Button::Listener, public TextEditor::Listener, public Timer
{
public:
    //==============================================================================
    MainContentComponent();
    ~MainContentComponent();

    void paint (Graphics&);
    void resized();

	void comboBoxChanged(ComboBox *comboBoxThatHasChanged);
	void buttonClicked(Button *button);

	void mouseDown(const MouseEvent &event);
	void mouseExit(const MouseEvent &event);

	void textEditorTextChanged(TextEditor &editor);
	void timerCallback();

	// I'm trying to improve the drawFittedText function, with the following features :
	// - Does not fit the text anymore (not the case for Fitted even with extreme parameters)
	// - Keeps the Justification behaviour in the parameters (not the case for Multi-Line)
	// - The text is rendered only inside the specified rectangle (not the case for Fitted)
	void drawMultiLineTextIntoRectangle(Graphics &g, const String& text, const Rectangle<int>& area, Justification justification);

	// Same than before, but with columns
	void drawMultiLineTextIntoColumns(Graphics &g, const String &text, const Rectangle<int>& area, Justification justification,
		int numColumns, int gapWidth, bool isDelimitedWithLines);

	// Updates the text to display
	void updateTextToDisplay();

	// Sets the font renderers list in the associated combobox
	void updateSoftwareRenderers();

	// Loads a font from a file on a drive
	bool loadCustomFont(File fileFont);

	// Updates TextEditor status
	void updateTextEditorStatus();

	// Returns the font we need to use for the display
	Font getFontToUse();


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

	Label *labelAddons;

	ComboBox *comboColumns, *comboGap;
	ToggleButton *toggleLimit;

	TextEditor *editorContent;

	CustomLookAndFeel theLF;
	ColourLibraryManager theColourManager;

	#if JUCE_OPENGL
		OpenGLContext openGLContext;
	#endif
	
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent);
};


#endif  // MAINCOMPONENT_H_INCLUDED

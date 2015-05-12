/*
  ==============================================================================

  ==============================================================================
*/

#ifndef JUCE_CUSTOMLOOKANDFEEL_H_INCLUDED
#define JUCE_CUSTOMLOOKANDFEEL_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"


//==============================================================================
/**
    The latest JUCE look-and-feel style, as introduced in 2013.
    @see LookAndFeel
*/
class CustomLookAndFeel   : public LookAndFeel_V2
{
public:
    CustomLookAndFeel();
    ~CustomLookAndFeel();

    //==============================================================================
    void drawComboBox (Graphics&, int width, int height, bool isButtonDown,
                       int buttonX, int buttonY, int buttonW, int buttonH, ComboBox&) override;

	

	void drawToggleButton(Graphics&, ToggleButton &, bool isMouseOverButton, bool isButtonDown) override;

	// ==============================================================================

	void setDefaultLookAndFeelBaseColours();

	void setLookAndFeelBaseColours(Colour backgroundColour, Colour textColour);

};


#endif  

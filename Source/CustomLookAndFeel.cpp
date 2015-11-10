/*
  ==============================================================================


  ==============================================================================
*/

#include "CustomLookAndFeel.h"



CustomLookAndFeel::CustomLookAndFeel()
{	setDefaultLookAndFeelBaseColours();
}

CustomLookAndFeel::~CustomLookAndFeel() 
{
}

void CustomLookAndFeel::setDefaultLookAndFeelBaseColours()
{
	setLookAndFeelBaseColours(Colour(0xff001F36), Colours::white);
}

void CustomLookAndFeel::setLookAndFeelBaseColours(Colour backgroundColour, Colour textColour)
{	
	setColour(ComboBox::backgroundColourId, backgroundColour);
	setColour(ComboBox::textColourId, textColour);
	setColour(ComboBox::arrowColourId, textColour);
	setColour(ComboBox::buttonColourId, textColour);
	setColour(ComboBox::outlineColourId, textColour);

	setColour(PopupMenu::textColourId, textColour);
	setColour(PopupMenu::backgroundColourId, backgroundColour);
	setColour(PopupMenu::headerTextColourId, textColour);
	setColour(PopupMenu::highlightedBackgroundColourId, textColour.withAlpha(0.5f));
	setColour(PopupMenu::highlightedTextColourId, textColour);

	setColour(Label::backgroundColourId, backgroundColour);
	setColour(Label::textColourId, textColour);

	setColour(TextButton::buttonColourId, backgroundColour);
	setColour(ToggleButton::textColourId, textColour);

	setColour(TextEditor::backgroundColourId, backgroundColour);
	setColour(TextEditor::focusedOutlineColourId, backgroundColour);
	//setColour(TextEditor::highlightColourId, backgroundColour);
	setColour(TextEditor::highlightedTextColourId, textColour);
	setColour(TextEditor::outlineColourId, textColour);
	setColour(TextEditor::shadowColourId, backgroundColour);
	setColour(TextEditor::textColourId, textColour);
	setColour(CaretComponent::caretColourId, textColour);
}

void CustomLookAndFeel::drawComboBox (Graphics& g, int width, int height, const bool isButtonDown,
                                   int buttonX, int buttonY, int buttonW, int buttonH, ComboBox& box)
{
    g.fillAll (box.findColour (ComboBox::backgroundColourId));
    g.setColour (box.findColour (ComboBox::outlineColourId));
    g.drawRect (0, 0, width, height);
    
    const float outlineThickness = box.isEnabled() ? (isButtonDown ? 1.2f : 0.5f) : 0.3f;

    if (box.isEnabled())
    {
        const float arrowX = 0.3f;
        const float arrowH = 0.2f;

        Path p;
        p.addTriangle (buttonX + buttonW * 0.5f,            buttonY + buttonH * (0.45f - arrowH),
                       buttonX + buttonW * (1.0f - arrowX), buttonY + buttonH * 0.45f,
                       buttonX + buttonW * arrowX,          buttonY + buttonH * 0.45f);

        p.addTriangle (buttonX + buttonW * 0.5f,            buttonY + buttonH * (0.55f + arrowH),
                       buttonX + buttonW * (1.0f - arrowX), buttonY + buttonH * 0.55f,
                       buttonX + buttonW * arrowX,          buttonY + buttonH * 0.55f);

        g.setColour (box.findColour (ComboBox::arrowColourId));
        g.fillPath (p);
    }
}

void CustomLookAndFeel::drawToggleButton(Graphics &g, ToggleButton &button, bool isMouseOverButton, bool isButtonDown)
{
	float fontSize = jmin (15.0f, button.getHeight() * 0.75f);
	const int tickWidth = juce::roundFloatToInt(fontSize * 1.1f);

    /*drawTickBox (g, button, 4.0f, (button.getHeight() - tickWidth) * 0.5f,
                 tickWidth, tickWidth,
                 button.getToggleState(),
                 button.isEnabled(),
                 isMouseOverButton,
                 isButtonDown);
				 */
	g.setColour (button.findColour (ToggleButton::textColourId));
	g.drawRect(0, (button.getHeight() - tickWidth) / 2, tickWidth, tickWidth, 1);

	if (button.getToggleState())
		g.fillRect(4, (button.getHeight() - tickWidth) / 2 + 4, tickWidth - 8, tickWidth - 8);

    g.setFont (fontSize);

    if (! button.isEnabled()) g.setOpacity (0.5f);

    const int textX = tickWidth + 6;

    g.drawFittedText (button.getButtonText(),
                      textX, 0,
                      button.getWidth() - textX, button.getHeight(),
                      Justification::centredLeft, 10);
}


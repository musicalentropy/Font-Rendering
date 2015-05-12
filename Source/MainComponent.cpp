/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"
//#include "FreeTypeFaces.h"


//==============================================================================
MainContentComponent::MainContentComponent()
{
    setLookAndFeel(&theLF);
	Font::findFonts (fonts);

	StringArray *theColourNames = theColourManager.getStringDatabase();

	// -------------------------------------------------------------------------
	addAndMakeVisible(comboJustification = new ComboBox(""));
	
	comboJustification->addSectionHeading("Justification");
	comboJustification->addItem("Top Left", Justification::topLeft);
	comboJustification->addItem("Top Centred", Justification::centredTop);
	comboJustification->addItem("Top Right", Justification::topRight);
	comboJustification->addItem("Top Justified", Justification::top + Justification::horizontallyJustified);
	
	comboJustification->addItem("Centred Left", Justification::centredLeft);
	comboJustification->addItem("Centred", Justification::centred);
	comboJustification->addItem("Centred Right", Justification::centredRight);
	comboJustification->addItem("Center Justified", Justification::verticallyCentred + Justification::horizontallyJustified);

	comboJustification->addItem("Bottom Left", Justification::bottomLeft);
	comboJustification->addItem("Bottom Centred", Justification::centredBottom);
	comboJustification->addItem("Bottom Right", Justification::bottomRight);
	comboJustification->addItem("Bottom Justified", Justification::bottom + Justification::horizontallyJustified);

	comboJustification->addListener(this);
	comboJustification->setSelectedId(Justification::centred, dontSendNotification);

	// -------------------------------------------------------------------------
	addAndMakeVisible(comboFontHeight = new ComboBox(""));

	comboFontHeight->addSectionHeading("Font Height");
	comboFontHeight->addItem("8", 8);
	comboFontHeight->addItem("9", 9);
	comboFontHeight->addItem("10", 10);
	comboFontHeight->addItem("11", 11);
	comboFontHeight->addItem("12", 12);
	comboFontHeight->addItem("13", 13);
	comboFontHeight->addItem("14", 14);
	comboFontHeight->addItem("16", 16);
	comboFontHeight->addItem("18", 18);
	comboFontHeight->addItem("20", 20);
	comboFontHeight->addItem("22", 22);
	comboFontHeight->addItem("24", 24);
	comboFontHeight->addItem("26", 26);
	comboFontHeight->addItem("28", 28);
	comboFontHeight->addItem("30", 30);
	comboFontHeight->addItem("34", 34);
	comboFontHeight->addItem("40", 40);
	comboFontHeight->addItem("60", 60);

	comboFontHeight->addSectionHeading("Font Height in Points");
	comboFontHeight->addItem("8p", 8+100);
	comboFontHeight->addItem("9p", 9+100);
	comboFontHeight->addItem("10p", 10+100);
	comboFontHeight->addItem("11p", 11+100);
	comboFontHeight->addItem("12p", 12+100);
	comboFontHeight->addItem("13p", 13+100);
	comboFontHeight->addItem("14p", 14+100);
	comboFontHeight->addItem("16p", 16+100);
	comboFontHeight->addItem("18p", 18+100);
	comboFontHeight->addItem("20p", 20+100);
	comboFontHeight->addItem("22p", 22+100);
	comboFontHeight->addItem("24p", 24+100);
	comboFontHeight->addItem("26p", 26+100);
	comboFontHeight->addItem("28p", 28+100);
	comboFontHeight->addItem("30p", 30+100);
	comboFontHeight->addItem("34p", 34+100);
	comboFontHeight->addItem("40p", 40+100);
	comboFontHeight->addItem("60p", 60+100);

	comboFontHeight->addListener(this);
	comboFontHeight->setSelectedId(16, dontSendNotification);

	// -------------------------------------------------------------------------
	addAndMakeVisible(comboFontName = new ComboBox(""));
	
	comboFontName->addSectionHeading("Font Name");
	comboFontName->addItem("--- default ---", 1);
	comboFontName->addItem("Load a Font file...", 2);
	//comboFontName->addItem("Load a Font file with FreeType...", 3);
	comboFontName->addItem("Custom Font", 4);
	comboFontName->setItemEnabled(4, false);
	
	comboFontName->addSeparator();
	for(int i=0; i<fonts.size(); i++) comboFontName->addItem(fonts[i].getTypefaceName(), i+5);

	comboFontName->addListener(this);
	comboFontName->setSelectedId(1, dontSendNotification);

	// -------------------------------------------------------------------------
	addAndMakeVisible(comboContent = new ComboBox());

	comboContent->addSectionHeading("Text to Display");
	comboContent->addItem("Lorem Ipsum 1", 1);
	comboContent->addItem("Lorem Ipsum 2", 2);
	comboContent->addItem("Lorem Ipsum 30", 3);
	comboContent->addItem("ASCII characters 1", 4);
	comboContent->addItem("ASCII characters 50", 5);
	comboContent->addItem("ASCII characters 200", 6);
	comboContent->addItem("Quick Brown Fox 1", 7);
	comboContent->addItem("Quick Brown Fox 50", 8);
	comboContent->addItem("Quick Brown Fox 200", 9);

	comboContent->addListener(this);
	comboContent->setSelectedId(1, dontSendNotification);

	updateTextToDisplay();

	// -------------------------------------------------------------------------
	addAndMakeVisible(toggleBold = new ToggleButton("Bold"));
	toggleBold->addListener(this);
	toggleBold->setToggleState(false, dontSendNotification);

	addAndMakeVisible(toggleItalic = new ToggleButton("Italic"));
	toggleItalic->addListener(this);
	toggleItalic->setToggleState(false, dontSendNotification);

	addChildComponent(toggleUnderlined = new ToggleButton("Underlined"));
	toggleUnderlined->addListener(this);
	toggleUnderlined->setToggleState(false, dontSendNotification);

	// -------------------------------------------------------------------------
	addAndMakeVisible(comboBackgroundColour = new ComboBox());

	comboBackgroundColour->addSectionHeading("Background Colour");
	comboBackgroundColour->addItem("0xFF001F36", 1);
	comboBackgroundColour->addSeparator();

	for(int i=0; i<theColourManager.getNumEntries(); i++)
		comboBackgroundColour->addItem(theColourNames->getReference(i), i+2);
	
	comboBackgroundColour->addListener(this);
	comboBackgroundColour->setSelectedId(1, dontSendNotification);

	// -------------------------------------------------------------------------
	addAndMakeVisible(comboTextColour = new ComboBox());

	comboTextColour->addSectionHeading("Text Colour");
	comboTextColour->addItem("white", 1);
	comboTextColour->addSeparator();

	for(int i=0; i<theColourManager.getNumEntries(); i++)
		comboTextColour->addItem(theColourNames->getReference(i), i+2);
	
	comboTextColour->addListener(this);
	comboTextColour->setSelectedId(1, dontSendNotification);

	// -------------------------------------------------------------------------
	addAndMakeVisible(comboRendering = new ComboBox());
	comboRendering->addSectionHeading("Graphics Rendering Engine");
	comboRendering->addListener(this);

	// -------------------------------------------------------------------------
	addAndMakeVisible(comboKerning = new ComboBox());
	comboKerning->addSectionHeading("Extra Kerning");

	comboKerning->addItem("-20 %", 1);
	comboKerning->addItem("-16 %", 2);
	comboKerning->addItem("-12 %", 3);
	comboKerning->addItem("-8 %", 4);
	comboKerning->addItem("-4 %", 5);
	comboKerning->addItem("0 %", 6);
	comboKerning->addItem("10 %", 7);
	comboKerning->addItem("20 %", 8);
	comboKerning->addItem("40 %", 9);
	comboKerning->addItem("60 %", 10);
	comboKerning->addItem("100 %", 11);
	
	comboKerning->addListener(this);
	comboKerning->setSelectedId(6, dontSendNotification);

	// -------------------------------------------------------------------------
	addAndMakeVisible(comboScale = new ComboBox());
	comboScale->addSectionHeading("Horizontal Scale");

	comboScale->addItem("25 %", 1);
	comboScale->addItem("50 %", 2);
	comboScale->addItem("66 %", 3);
	comboScale->addItem("75 %", 4);
	comboScale->addItem("100 %", 5);
	comboScale->addItem("150 %", 6);
	comboScale->addItem("200 %", 7);
	comboScale->addItem("300 %", 8);
	comboScale->addItem("400 %", 9);
	
	comboScale->addListener(this);
	comboScale->setSelectedId(5, dontSendNotification);

	// -------------------------------------------------------------------------

	hasCustomFontBeenLoaded = false;
	setSize (710, 400);

}

MainContentComponent::~MainContentComponent()
{	
	#if JUCE_OPENGL
		openGLContext.detach();
	#endif
	
	deleteAllChildren();
}

void MainContentComponent::updateTextToDisplay()
{	const int index = comboContent->getSelectedId();

	if (index == 1) strTextToDisplay = TextContentGenerator::getLoremIpsum(1);
	else if (index == 2) strTextToDisplay = TextContentGenerator::getLoremIpsum(2);
	else if (index == 3) strTextToDisplay = TextContentGenerator::getLoremIpsum(30);

	else if (index == 4) strTextToDisplay = TextContentGenerator::getASCIICharacters(1);
	else if (index == 5) strTextToDisplay = TextContentGenerator::getASCIICharacters(50);
	else if (index == 6) strTextToDisplay = TextContentGenerator::getASCIICharacters(200);
	
	else if (index == 7) strTextToDisplay = TextContentGenerator::getQuickBrownFox(1);
	else if (index == 8) strTextToDisplay = TextContentGenerator::getQuickBrownFox(50);
	else strTextToDisplay = TextContentGenerator::getQuickBrownFox(200);
}

void MainContentComponent::updateSoftwareRenderers()
{
	if (getTopLevelComponent()->getPeer() != nullptr)
	{	StringArray theArray = getTopLevelComponent()->getPeer()->getAvailableRenderingEngines();
		
		#if (JUCE_USE_DIRECTWRITE && JUCE_WINDOWS)
			for(int i=0; i<theArray.size(); i++)
			{	if (theArray.getReference(i) == "Software Renderer")
					theArray.set(i, "DirectWrite Renderer");
			}
		#endif
	
		comboRendering->addItemList(theArray, 1);

		#if JUCE_OPENGL
			comboRendering->addItem("OpenGL Renderer", 99);
		#endif

		comboRendering->setSelectedId(getTopLevelComponent()->getPeer()->getCurrentRenderingEngine()+1);
	}
}

void MainContentComponent::resized()
{	comboFontName->setBounds(10, 10, 210, 24);
	comboFontHeight->setBounds(230, 10, 50, 24);
	comboJustification->setBounds(290, 10, 120, 24);

	comboKerning->setBounds(420, 10, 70, 24);
	comboScale->setBounds(500, 10, 70, 24);

	comboRendering->setBounds(10, getHeight()-35, 210, 24);
	
	comboContent->setBounds(230, getHeight()-35, 170, 24);
	comboBackgroundColour->setBounds(410, getHeight()-35, 140, 24);
	comboTextColour->setBounds(560, getHeight()-35, 140, 24);

	toggleBold->setBounds(580, 10, 50, 24);
	toggleItalic->setBounds(640, 10, 55, 24);
	//toggleUnderlined->setBounds(545, 10, 90, 24);
}

void MainContentComponent::paint (Graphics& g)
{
	g.fillAll (theLF.findColour(Label::backgroundColourId));

	const int style = (toggleBold->getToggleState() ? Font::bold : Font::plain) + 
		(toggleItalic->getToggleState() ? Font::italic : Font::plain) +
		(toggleUnderlined->getToggleState() ? Font::underlined : Font::plain);

	Font font = Font();

	if ((comboFontName->getSelectedId() == 0 || comboFontName->getSelectedId() == 4) && hasCustomFontBeenLoaded)
		font = Font(theCustomFont);
	else if (comboFontName->getSelectedId() >= 5)
		font = Font(fonts[comboFontName->getSelectedId()-5].getTypefaceName(), 16.f, Font::plain);
	
	if (comboFontHeight->getSelectedId() < 100)
		font = font.withHeight((float) comboFontHeight->getSelectedId());
	else
		font = font.withPointHeight((float) comboFontHeight->getSelectedId()-100);

	font = font.withStyle(style);
	font = font.withExtraKerningFactor(comboKerning->getText().getFloatValue()*0.01f);
	font = font.withHorizontalScale(comboScale->getText().getFloatValue()*0.01f);

	g.setFont(font);	
	g.setColour (theLF.findColour(Label::textColourId));

	drawMultiLineTextIntoRectangle(g, strTextToDisplay, 
		Rectangle <int> (10, 50, getWidth()-20, getHeight()-100), 
		comboJustification->getSelectedId());

	g.drawHorizontalLine(45, 10.f, getWidth()-10.f);
	g.drawHorizontalLine(getHeight() - 45, 10.f, getWidth()-10.f);
}

void MainContentComponent::comboBoxChanged(ComboBox *comboBoxThatHasChanged)
{	
	if (comboBoxThatHasChanged == comboContent)
		updateTextToDisplay();

	else if (comboBoxThatHasChanged == comboBackgroundColour || comboBoxThatHasChanged == comboTextColour)
	{	
		if (comboBackgroundColour->getSelectedId() == comboTextColour->getSelectedId())
			theLF.setDefaultLookAndFeelBaseColours();

		else
		{	theLF.setLookAndFeelBaseColours(comboBackgroundColour->getSelectedId() == 1 ? Colour (0xff001F36) : theColourManager.getColourEntry(comboBackgroundColour->getSelectedId()-2),
				comboTextColour->getSelectedId() == 1 ? Colours::white : theColourManager.getColourEntry(comboTextColour->getSelectedId()-2));
		}

		comboBackgroundColour->lookAndFeelChanged();
		comboTextColour->lookAndFeelChanged();
		comboContent->lookAndFeelChanged();

		comboRendering->lookAndFeelChanged();

		comboJustification->lookAndFeelChanged();
		comboFontHeight->lookAndFeelChanged();
		comboFontName->lookAndFeelChanged();

		comboScale->lookAndFeelChanged();
		comboKerning->lookAndFeelChanged();

	}

	else if (comboBoxThatHasChanged == comboRendering)
	{	
		#if JUCE_OPENGL
			if (comboRendering->getSelectedId() == 99)
			{	openGLContext.attachTo (*getTopLevelComponent());
				return;
			}

			openGLContext.detach();
		#endif
		
		if (getTopLevelComponent()->getPeer() != nullptr)
		{	
			int renderingEngine = comboRendering->getSelectedId() - 1;

			getTopLevelComponent()->getPeer()->setCurrentRenderingEngine(renderingEngine);

			// It is necessary to add a hack on PopupMenu::showWithOptionalCallback() too
			// Hacks on juce_win32_Windowing.cpp
		}
	}
	else if (comboBoxThatHasChanged == comboFontName)
	{	if (comboFontName->getSelectedId() == 2)
		{	
			FileChooser theFileChooser("Find a Font file", File::getSpecialLocation(File::currentApplicationFile).getParentDirectory(), 
				"*.ttf; *.otf", true);

			if (theFileChooser.browseForFileToOpen())
			{	if (loadCustomFont(theFileChooser.getResult()))
				{	hasCustomFontBeenLoaded = true;
					comboFontName->setItemEnabled(4, true);
					comboFontName->setSelectedId(4);
				}
				else
					comboFontName->setSelectedId(1, dontSendNotification);
			}
			else
				comboFontName->setSelectedId(1, dontSendNotification);
		}
		
		else if (comboFontName->getSelectedId() == 4)
		{	comboFontName->setText("# " + theCustomFont.getTypefaceName(), dontSendNotification);
			//comboFontName->setSelectedId(3, dontSendNotification);
		}
	}

	repaint();
}

void MainContentComponent::buttonClicked(Button *button)
{	
	repaint();
}

// I'm trying to improve the drawFittedText function
// =========================================================================================================================
void MainContentComponent::drawMultiLineTextIntoRectangle(Graphics &g, const String& text, const Rectangle<int>& area, Justification justification)
{
	if (text.isNotEmpty() && (! area.isEmpty()) && g.clipRegionIntersects (area))
    {
        GlyphArrangement arr;
        
		arr.addJustifiedText(g.getCurrentFont(), text, (float) area.getX(), (float) area.getY() + g.getCurrentFont().getAscent(), 
			(float) area.getWidth(), justification);

		int i=arr.getNumGlyphs()-1;

		if (i > 0)
		{	while(i >= 0 && arr.getGlyph(i).getBottom() > area.getY() + area.getHeight()) i--;
			arr.removeRangeOfGlyphs(i+1, arr.getNumGlyphs() - i);
		}

		if (arr.getNumGlyphs() - i > 0)
		{	
			float deltaY = 0.f;
			if (justification.testFlags (Justification::bottom))   
				deltaY = area.getY() + area.getHeight() - arr.getGlyph(arr.getNumGlyphs() - 1).getBottom();
			else if (justification.testFlags (Justification::top) == false) 
				deltaY = (area.getY() + area.getHeight() - arr.getGlyph(arr.getNumGlyphs() - 1).getBottom()) * 0.5f;

			arr.moveRangeOfGlyphs (0, arr.getNumGlyphs(), 0.f, deltaY);
		}

        arr.draw (g);
    }
}

bool MainContentComponent::loadCustomFont(File fileFont)
{
	FileInputStream theStream(fileFont);
	
	MemoryBlock theMemoryBlock;
	theStream.readIntoMemoryBlock(theMemoryBlock);

	Typeface::Ptr ptr = Typeface::createSystemTypefaceFor(theMemoryBlock.getData(), theMemoryBlock.getSize());

	#if JUCE_WINDOWS
		if (fileFont.getFileExtension().toLowerCase() == ".otf")
		{	AlertWindow::showMessageBox(AlertWindow::WarningIcon, "OTF Font files", 
				"The OFT Font file reading is still not working on Windows with JUCE. Use a OTF to TTF converter instead.", "OK");
		}
	#endif
	
	if (ptr == nullptr)
		return false;

	else
	{	theCustomFont = Font(ptr);
		return true;
	}

}

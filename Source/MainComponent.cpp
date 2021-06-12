#include "MainComponent.h"
#include "Tracks.h"

/*
  ==============================================================================

    File containing definitions of GUI functions

  ==============================================================================
*/

//==============================================================================
MainComponent::MainComponent()
{
    // Set LookAndFeel
    // https://coolors.co/4965a3-fca311-353643-757d88-dadbe7-ffffff

    getLookAndFeel().setColour(juce::ResizableWindow::backgroundColourId, juce::Colour (0xff353643));

    // Add UI Elements
    outputVolumeSlider.setRange(-100, 0);
    outputVolumeSlider.setTextBoxStyle(juce::Slider::TextBoxRight, false, 100, 20);

    newTrackButton.setButtonText("+");
    newTrackButton.onClick = [this] { return; };

    addAndMakeVisible(outputVolumeSlider);
    addAndMakeVisible(newTrackButton);


    // Make sure you set the size of the component after
    // you add any child components.
    setSize (800, 600);

    // Some platforms require permissions to open input channels so request that here
    if (juce::RuntimePermissions::isRequired (juce::RuntimePermissions::recordAudio)
        && ! juce::RuntimePermissions::isGranted (juce::RuntimePermissions::recordAudio))
    {
        juce::RuntimePermissions::request (juce::RuntimePermissions::recordAudio,
                                           [&] (bool granted) { setAudioChannels (granted ? 2 : 0, 2); });
    }
    else
    {
        // Specify the number of input and output channels that we want to open
        setAudioChannels (2, 2);
    }
}

MainComponent::~MainComponent()
{
    // This shuts down the audio device and clears the audio source.
    shutdownAudio();
}


//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    // You can add your drawing code here!
}

void MainComponent::resized()
{
    // This is called when the MainContentComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
    outputVolumeSlider.setBounds(100, 10, getWidth() - 110, 20);
    newTrackButton.setBounds(100, 50, 20, 20);
}

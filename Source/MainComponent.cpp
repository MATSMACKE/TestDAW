#include "MainComponent.h"
#include "Tracks.h"
#include "GUIComponents.h"

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
    addAndMakeVisible(transportBar);
    addAndMakeVisible(trackPlugins);
    addAndMakeVisible(fileBrowser);
    addAndMakeVisible(allTracksWindow);

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

GUIVars MainComponent::guiVars = GUIVars(64, 128, 128, 100);

void MainComponent::resized()
{
    // This is called when the MainContentComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
    updateUI();
}

void MainComponent::updateUI() {
    // This is basically MainComponent::resized(), but will 
    //also be called elsewhere to update UI
    auto availableArea = getLocalBounds();

    transportBar.setBounds(availableArea.removeFromTop(guiVars.transportHeight));
    trackPlugins.setBounds(availableArea.removeFromBottom(guiVars.trackPluginsHeight));
    fileBrowser.setBounds(availableArea.removeFromLeft(guiVars.browserWidth));
    allTracksWindow.setBounds(availableArea);
}

void MainComponent::createTrack() {

}

// GUIVars constructor. GUIVars struct stores parameters about UI. 
GUIVars::GUIVars(int transportHeight, int browserWidth, int trackPluginsHeight, int trackSegmentHeight) {
    this->transportHeight = transportHeight;
    this->browserWidth = browserWidth;
    this->trackPluginsHeight = trackPluginsHeight;
    this->trackSegmentHeight = trackSegmentHeight;
}
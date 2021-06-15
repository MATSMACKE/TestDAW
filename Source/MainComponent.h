#pragma once

// Vector is used for list of tracks in TrackManager
// String is used for names of Tracks and Managers
#include <vector>
#include <string>

using std::string;
using std::vector;

#include <JuceHeader.h>
#include <vector>
#include "GUIComponents.h"
#include "Tracks.h"

//==================================================================================
/*
    MainComponent class contains all the GUI of the app, as well as providing the
    3 basic audio functions that connect the app to JUCE's behind the scenes 
    audio i/o management
*/
class MainComponent  : public juce::AudioAppComponent
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent() override;

    //==============================================================================
    // THESE 3 FUNCTIONS CONNECT THE APP TO JUCE's AUDIO I/O
    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override;
    void getNextAudioBlock (const juce::AudioSourceChannelInfo& bufferToFill) override;
    void releaseResources() override;

    //==============================================================================
    void paint (juce::Graphics& g) override;
    void resized() override;

    void updateUI();

    void newTrack(string newTrackName, TrackType newTrackType);

private:
    //==============================================================================

    // This vector contains all tracks in the project, it is very important
    std::vector<Track> tracks;

    static GUIVars guiVars;

    // Create instances of GUI components
    TransportBar transportBar;

    TrackPlugins trackPlugins;

    FileBrowser fileBrowser;

    AllTracksWindow allTracksWindow;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
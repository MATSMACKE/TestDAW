#pragma once

#include <JuceHeader.h>
#include <vector>


/*
    ================================================================================

    Declarations of all GUI related classes are below

    ================================================================================
*/

class FileBrowser           : public juce::Component {

};

class TransportBar          : public juce::Component {

};

class TrackGUI              : public juce::Component {

};

class AllTracksWindow       : public juce::Component {

};

class TrackPluginsSection   : public juce::Component {

};

class TrackSynthSection     : public juce::Component {

};

class TrackEffectSection    : public juce::Component {

};

class TrackModSection       : public juce::Component {

};

class Plugin                : public juce::Component {

};

class EffectPlugin          : public Plugin {

};

class SourcePlugin          : public Plugin {

};

class ModulatorPlugin       : public Plugin {

};

class EffectLane            : public juce::Component {

};


struct GUIVars {
    int transportHeigt;
    int browserWidth;
    int trackPluginsHeight;
    int trackSegmentHeight;

    GUIVars(int transportHeight, int browserWidth, int trackPluginsHeight, int trackSegmentHeight);
};


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

    void createTrack();

private:
    //==============================================================================
    // Create instances of GUI components
    GUIVars thisGUISpace;

    TransportBar transportBar;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};

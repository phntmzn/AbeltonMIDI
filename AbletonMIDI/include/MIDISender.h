#pragma once
#include <string>
#include <vector>
#include <RtMidi.h>

class MidiSender {
public:
    MidiSender();
    ~MidiSender();

    bool openPort(unsigned int portIndex);
    void listPorts() const;

    void sendNoteOn(unsigned char note, unsigned char velocity);
    void sendNoteOff(unsigned char note, unsigned char velocity);

private:
    RtMidiOut midiOut;
};
#include "MidiSender.h"
#include <iostream>

MidiSender::MidiSender() {}
MidiSender::~MidiSender() {}

bool MidiSender::openPort(unsigned int portIndex) {
    try {
        midiOut.openPort(portIndex);
        return true;
    } catch (RtMidiError &error) {
        error.printMessage();
        return false;
    }
}

void MidiSender::listPorts() const {
    unsigned int nPorts = midiOut.getPortCount();
    std::cout << "Available MIDI Output Ports:\n";
    for (unsigned int i = 0; i < nPorts; ++i)
        std::cout << "  " << i << ": " << midiOut.getPortName(i) << "\n";
}

void MidiSender::sendNoteOn(unsigned char note, unsigned char velocity) {
    std::vector<unsigned char> message = {0x90, note, velocity};
    midiOut.sendMessage(&message);
}

void MidiSender::sendNoteOff(unsigned char note, unsigned char velocity) {
    std::vector<unsigned char> message = {0x80, note, velocity};
    midiOut.sendMessage(&message);
}
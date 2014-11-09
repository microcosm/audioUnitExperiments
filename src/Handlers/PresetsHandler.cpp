#include "PresetsHandler.h"

void PresetsHandler::setup(string synthName, ofxAudioUnit* synth){
    this->synthName = synthName;
    this->synth = synth;
    
    currentPreset = -1;
    this->readFromDisk();
    
    if(presets.size() > 0) {
        currentPreset = presets.size()-1;
        this->load(currentPreset);
    }
}

void PresetsHandler::load(int index) {
    string name = presets.at(index).getBaseName();
    synth->loadCustomPreset(name);
    updateMsg = "Loaded preset [" + ofToString(index) + "] " + name;
    cout << updateMsg << endl;
}

void PresetsHandler::save() {
    string name = synthName + "-";
    name.append(ofToString(ofGetUnixTime()));
    synth->saveCustomPreset(name);
    readFromDisk();
    currentPreset = presets.size()-1;
    updateMsg = "Saved preset [" + ofToString(currentPreset) + "] " + name;
    cout << updateMsg << endl;
}

void PresetsHandler::increment() {
    readFromDisk();
    if(currentPreset == presets.size()-1) currentPreset = 0;
    else currentPreset += 1;
    load(currentPreset);
}

void PresetsHandler::decrement() {
    readFromDisk();
    if(currentPreset == 0) currentPreset = presets.size()-1;
    else currentPreset -= 1;
    load(currentPreset);
}

void PresetsHandler::readFromDisk() {
    ofDirectory dir("");
    dir.allowExt("aupreset");
    dir.listDir();
    presets = dir.getFiles();
    if(currentPreset > presets.size()-1) {
        currentPreset = presets.size()-1;
    }
}

int PresetsHandler::currentIndex(){
    return currentPreset;
}

string PresetsHandler::report() {
    stringstream report;
    report << "PRESETS" << endl << endl;
    
    for(int i = 0; i < presets.size(); i++) {
        report << endl << i << ": " << presets.at(i).getBaseName();
        if(i == currentIndex()) {
            report << " [*]";
        }
    }
    
    return report.str();
}
#include "SkinFXSocketLerp.h"

FSkinFXSocketLerp::FSkinFXSocketLerp() {
    this->bUseBoneOne = false;
    this->bUseBoneTwo = false;
    this->SocketOutput = ESkinFXSocketOutput::SFXS_POSITION;
    this->SocketOutputAlpha = ESkinFXSocketOutputAlphaPack::SFXSAP_NONE;
    this->bStretchToEnvelope = false;
    this->bLoop = false;
    this->bMultiplyByASREnvelope = false;
}


#include "SkinFXSocket.h"

FSkinFXSocket::FSkinFXSocket() {
    this->SocketOutput = ESkinFXSocketOutput::SFXS_POSITION;
    this->SocketOutputAlpha = ESkinFXSocketOutputAlphaPack::SFXSAP_NONE;
    this->bMultiplyColorByEnvelope = false;
    this->EnvelopeColorMod = ESkinFXEnvelopeColorMod::RGBONLY;
    this->bMultiplyScalarByEnvelope = false;
    this->bUseBone = false;
    this->bUseReferencePose = false;
}


#include "ChromaSDKSceneEffect.h"

FChromaSDKSceneEffect::FChromaSDKSceneEffect() {
    this->State = false;
    this->PrimaryColor = 0;
    this->SecondaryColor = 0;
    this->Speed = 0;
    this->Blend = EChromaSDKSceneBlend::SB_None;
    this->Mode = EChromaSDKSceneMode::SM_Replace;
}


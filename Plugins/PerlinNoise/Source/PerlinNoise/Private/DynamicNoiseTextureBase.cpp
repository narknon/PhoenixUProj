#include "DynamicNoiseTextureBase.h"

class UTexture2D;

UTexture2D* UDynamicNoiseTextureBase::GetDynamicTexture() {
    return NULL;
}

UDynamicNoiseTextureBase::UDynamicNoiseTextureBase() {
    this->Width = 0;
    this->Height = 0;
    this->UpdateInterval = 0.10f;
    this->Texture = NULL;
    this->Age = 0.00f;
    this->NextUpdate = 0.10f;
}


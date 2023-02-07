#include "BlendTrackInfo.h"

FBlendTrackInfo::FBlendTrackInfo() {
    this->BlendSpaceParameterGetter = NULL;
    this->bIsAdditive = false;
    this->bRotationOffsetMeshSpace = false;
    this->bOverrideMeshSpaceRotationBlend = false;
    this->bMeshSpaceRotationBlend = false;
    this->bLoop = false;
    this->BoneWeightAsset = NULL;
}


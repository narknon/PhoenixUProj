#include "AblBoneBlendWeightAsset.h"

UAblBoneBlendWeightAsset::UAblBoneBlendWeightAsset() {
    this->DefaultBoneWeight = 0.00f;
    this->Skeleton = NULL;
    this->bMeshSpaceRotationBlend = true;
    this->BlendWeightsDirty = true;
}


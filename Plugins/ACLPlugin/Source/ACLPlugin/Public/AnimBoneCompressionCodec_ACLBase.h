#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimBoneCompressionCodec.h"
#include "AnimBoneCompressionCodec_ACLBase.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew, MinimalAPI)
class UAnimBoneCompressionCodec_ACLBase : public UAnimBoneCompressionCodec {
    GENERATED_BODY()
public:
    UAnimBoneCompressionCodec_ACLBase();
};


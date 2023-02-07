#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimNodeBase.h"
#include "Animation/AnimNodeBase.h"
#include "AnimNode_CustomizableCharacterLocalModifyBoneScales.generated.h"

class UCustomizableCharacterComponent;

USTRUCT(BlueprintType)
struct CUSTOMIZABLECHARACTER_API FAnimNode_CustomizableCharacterLocalModifyBoneScales : public FAnimNode_Base {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPoseLink BasePose;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 LODThreshold;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCustomizableCharacterComponent* CustomizableCharacterComponent;
    
public:
    FAnimNode_CustomizableCharacterLocalModifyBoneScales();
};


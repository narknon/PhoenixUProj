#pragma once
#include "CoreMinimal.h"
#include "BoneControllers/AnimNode_SkeletalControlBase.h"
#include "AnimNode_CustomizableCharacterModifyBoneScales.generated.h"

class UCustomizableCharacterComponent;

USTRUCT(BlueprintType)
struct CUSTOMIZABLECHARACTER_API FAnimNode_CustomizableCharacterModifyBoneScales : public FAnimNode_SkeletalControlBase {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCustomizableCharacterComponent* CustomizableCharacterComponent;
    
public:
    FAnimNode_CustomizableCharacterModifyBoneScales();
};


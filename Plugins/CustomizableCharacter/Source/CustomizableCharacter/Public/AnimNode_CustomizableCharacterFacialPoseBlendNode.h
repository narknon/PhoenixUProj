#pragma once
#include "CoreMinimal.h"
#include "AnimNodes/AnimNode_PoseBlendNode.h"
#include "AnimNode_CustomizableCharacterFacialPoseBlendNode.generated.h"

class UCustomizableCharacterComponent;

USTRUCT(BlueprintType)
struct CUSTOMIZABLECHARACTER_API FAnimNode_CustomizableCharacterFacialPoseBlendNode : public FAnimNode_PoseBlendNode {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCustomizableCharacterComponent* CustomizableCharacterComponent;
    
public:
    FAnimNode_CustomizableCharacterFacialPoseBlendNode();
};


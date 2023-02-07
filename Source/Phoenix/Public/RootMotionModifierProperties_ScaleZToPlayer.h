#pragma once
#include "CoreMinimal.h"
#include "RootMotionModifierProperties.h"
#include "RootMotionModifierProperties_ScaleZToPlayer.generated.h"

class USkeletalMesh;

UCLASS(Blueprintable, EditInlineNew)
class URootMotionModifierProperties_ScaleZToPlayer : public URootMotionModifierProperties {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USkeletalMesh* SkeletalMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName BoneName;
    
    URootMotionModifierProperties_ScaleZToPlayer();
};


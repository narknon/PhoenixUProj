#pragma once
#include "CoreMinimal.h"
#include "AnimationValidatedInWorld.h"
#include "AnimationSetEntry.generated.h"



USTRUCT(BlueprintType)
struct AVAANIMATION_API FAnimationSetEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName EntryName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimationAsset* AnimationAsset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<AnimationValidatedInWorld> InWorldStatus;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSelectedForNextUse;
    
    FAnimationSetEntry();
};


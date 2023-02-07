#pragma once
#include "CoreMinimal.h"
#include "AnimationProvider.h"
#include "AnimationAsset_Direct.generated.h"

class UAnimationAsset;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class AVAANIMATION_API UAnimationAsset_Direct : public UAnimationProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimationAsset* AnimationAsset;
    
    UAnimationAsset_Direct();
};


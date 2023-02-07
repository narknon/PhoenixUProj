#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "GameplayTagContainer.h"
#include "AblAnimationTagChooser.generated.h"

class UAnimationAsset;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class ABLECORE_API UAblAnimationTagChooser : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UAnimationAsset*> AnimationAssets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGameplayTagContainer> AnimationTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAppendAnimationTags;
    
    UAblAnimationTagChooser();
};


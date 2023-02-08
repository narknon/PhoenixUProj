#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "GameplayTagContainer.h"
#include "AblAnimationAssetChooser.generated.h"



UCLASS(Abstract, Blueprintable, EditInlineNew)
class ABLECORE_API UAblAnimationAssetChooser : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UAnimationAsset*> AnimationAssets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGameplayTagContainer> AnimationTags;
    
    UAblAnimationAssetChooser();
};


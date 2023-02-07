#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "BaseArchitectAsset.h"
#include "InteractionArchitectAsset_Connection.h"
#include "InteractionArchitectAsset.generated.h"

class UInteractionArchitectAsset;

UCLASS(Blueprintable)
class ANIMATIONARCHITECTRUNTIME_API UInteractionArchitectAsset : public UBaseArchitectAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FInteractionArchitectAsset_Connection> ConnectionArray;
    
    UInteractionArchitectAsset();
    UFUNCTION(BlueprintCallable)
    TArray<UClass*> K2_FindAbilityConnectionArray(const FGameplayTagContainer& InSourceTagContainer, const TArray<UInteractionArchitectAsset*>& InTargetAssets, const TArray<FGameplayTagContainer>& InTargetTags);
    
};


#pragma once
#include "CoreMinimal.h"
#include "EInteractionProject.h"
#include "GameplayTagContainer.h"
#include "BTTask_PlayAbilityBase.h"
#include "BTTask_PlayArchitectAbility.generated.h"

class UInteractionArchitectAsset;

UCLASS(Blueprintable)
class ABLECORE_API UBTTask_PlayArchitectAbility : public UBTTask_PlayAbilityBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInteractionArchitectAsset* InteractionArchitectAsset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EInteractionProject Project;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer SourceTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer TargetTags;
    
    UBTTask_PlayArchitectAbility();
};


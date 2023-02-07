#pragma once
#include "CoreMinimal.h"
#include "AblTaskCondition.h"
#include "GameplayTagContainer.h"
#include "AblTaskCondition_ReactionData.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblTaskCondition_ReactionData : public UAblTaskCondition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCompareImpactDirectionWithActorForward;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ImpactDotForwardMin;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ImpactDotForwardMax;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer RequiredMunitionTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer UnallowedMunitionTags;
    
    UAblTaskCondition_ReactionData();
};


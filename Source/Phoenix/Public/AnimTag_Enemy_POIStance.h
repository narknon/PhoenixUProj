#pragma once
#include "CoreMinimal.h"
#include "AnimationArchitectTagProvider.h"
#include "GameplayTagContainer.h"
#include "AnimTag_Enemy_POIStance.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UAnimTag_Enemy_POIStance : public UAnimationArchitectTagProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer AnimTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDesiredPOIAttackStance;
    
    UAnimTag_Enemy_POIStance();
};


#pragma once
#include "CoreMinimal.h"
#include "AnimationArchitectTagProvider.h"
#include "GameplayTagContainer.h"
#include "ENPC_Mobility.h"
#include "ENPC_TargetAwareState.h"
#include "AnimTag_NPC_Mobility.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UAnimTag_NPC_Mobility : public UAnimationArchitectTagProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer AnimTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ENPC_Mobility> MobilityStates;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAdditionallyCheckAwareState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ENPC_TargetAwareState> AwareStates;
    
    UAnimTag_NPC_Mobility();
};


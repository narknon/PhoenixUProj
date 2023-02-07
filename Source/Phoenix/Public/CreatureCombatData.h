#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ECreatureCombatDebugBehaviorType.h"
#include "ECreatureCombatDebugDisplayType.h"
#include "CreatureCombatData.generated.h"

UCLASS(Blueprintable)
class UCreatureCombatData : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ECreatureCombatDebugDisplayType DrawDebug;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ECreatureCombatDebugBehaviorType ForceBehavior;
    
    UCreatureCombatData();
};


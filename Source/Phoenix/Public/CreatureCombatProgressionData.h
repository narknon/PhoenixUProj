#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CreatureCombatStageSpecifier.h"
#include "CreatureCombatProgressionData.generated.h"

UCLASS(Blueprintable)
class UCreatureCombatProgressionData : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FCreatureCombatStageSpecifier> CombatStages;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bDebugDraw;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bEnableDebugStageIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 DebugStageIndex;
    
    UCreatureCombatProgressionData();
};


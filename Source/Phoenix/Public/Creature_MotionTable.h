#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CreatureGaitMotionData.h"
#include "Creature_MotionTable.generated.h"

UCLASS(Blueprintable)
class UCreature_MotionTable : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FCreatureGaitMotionData GaitMotionData[4];
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUsingTurnAssist;
    
    UCreature_MotionTable();
};


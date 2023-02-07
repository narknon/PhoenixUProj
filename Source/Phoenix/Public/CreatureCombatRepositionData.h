#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CreatureCombatData.h"
#include "CreatureCombatRepositionData.generated.h"

UCLASS(Blueprintable)
class UCreatureCombatRepositionData : public UCreatureCombatData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D RepositionDistanceRange;
    
    UCreatureCombatRepositionData();
};


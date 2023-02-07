#pragma once
#include "CoreMinimal.h"
#include "MissionStatus.h"
#include "WorldEventCondition.h"
#include "WorldEventCondition_Mission.generated.h"

UCLASS(Blueprintable)
class UWorldEventCondition_Mission : public UWorldEventCondition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName MissionName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<MissionStatus> MissionStatusToCheck;
    
    UWorldEventCondition_Mission();
};


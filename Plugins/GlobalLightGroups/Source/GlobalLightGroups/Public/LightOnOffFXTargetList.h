#pragma once
#include "CoreMinimal.h"
#include "LightOnOffFXTarget.h"
#include "LightOnOffFXTargetList.generated.h"

USTRUCT(BlueprintType)
struct FLightOnOffFXTargetList {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FLightOnOffFXTarget> Targets;
    
    GLOBALLIGHTGROUPS_API FLightOnOffFXTargetList();
};


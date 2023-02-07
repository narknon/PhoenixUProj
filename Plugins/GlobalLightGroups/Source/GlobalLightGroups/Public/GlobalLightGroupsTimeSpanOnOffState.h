#pragma once
#include "CoreMinimal.h"
#include "GlobalLightGroupsTimeSpanOnOffState.generated.h"

USTRUCT(BlueprintType)
struct FGlobalLightGroupsTimeSpanOnOffState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    uint8 State;
    
    GLOBALLIGHTGROUPS_API FGlobalLightGroupsTimeSpanOnOffState();
};


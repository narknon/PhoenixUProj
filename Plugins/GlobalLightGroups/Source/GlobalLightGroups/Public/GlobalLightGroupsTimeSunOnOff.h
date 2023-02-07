#pragma once
#include "CoreMinimal.h"
#include "GlobalLightGroupsTimeSun.h"
#include "GlobalLightGroupsTimeSunOnOff.generated.h"

USTRUCT(BlueprintType)
struct FGlobalLightGroupsTimeSunOnOff {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGlobalLightGroupsTimeSun On;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGlobalLightGroupsTimeSun Off;
    
    GLOBALLIGHTGROUPS_API FGlobalLightGroupsTimeSunOnOff();
};


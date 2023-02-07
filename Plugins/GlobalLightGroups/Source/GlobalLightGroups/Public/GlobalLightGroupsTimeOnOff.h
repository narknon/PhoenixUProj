#pragma once
#include "CoreMinimal.h"
#include "GlobalLightGroupsTimeHMSOnOff.h"
#include "GlobalLightGroupsTimeSunOnOff.h"
#include "GlobalLightGroupsTimeOnOff.generated.h"

USTRUCT(BlueprintType)
struct FGlobalLightGroupsTimeOnOff {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGlobalLightGroupsTimeHMSOnOff TimeOnOff;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGlobalLightGroupsTimeSunOnOff SunOnOff;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseTime;
    
    GLOBALLIGHTGROUPS_API FGlobalLightGroupsTimeOnOff();
};


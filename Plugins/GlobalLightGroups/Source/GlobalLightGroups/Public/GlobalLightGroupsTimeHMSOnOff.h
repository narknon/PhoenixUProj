#pragma once
#include "CoreMinimal.h"
#include "GlobalLightGroupsTimeHMS.h"
#include "GlobalLightGroupsTimeHMSOnOff.generated.h"

USTRUCT(BlueprintType)
struct FGlobalLightGroupsTimeHMSOnOff {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGlobalLightGroupsTimeHMS On;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGlobalLightGroupsTimeHMS Off;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bNormalizeForSeasons;
    
    GLOBALLIGHTGROUPS_API FGlobalLightGroupsTimeHMSOnOff();
};


#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GlobalLightGroupsUpdateTime.generated.h"

USTRUCT(BlueprintType)
struct FGlobalLightGroupsUpdateTime {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimespan Time;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimespan SolarTime;
    
    GLOBALLIGHTGROUPS_API FGlobalLightGroupsUpdateTime();
};


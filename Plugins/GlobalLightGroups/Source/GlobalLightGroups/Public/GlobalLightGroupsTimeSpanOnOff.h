#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GlobalLightGroupsTimeSpanOnOffState.h"
#include "GlobalLightGroupsTimeSpanOnOff.generated.h"

USTRUCT(BlueprintType)
struct FGlobalLightGroupsTimeSpanOnOff {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FTimespan NextOn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FTimespan NextOff;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FGlobalLightGroupsTimeSpanOnOffState State;
    
    GLOBALLIGHTGROUPS_API FGlobalLightGroupsTimeSpanOnOff();
};


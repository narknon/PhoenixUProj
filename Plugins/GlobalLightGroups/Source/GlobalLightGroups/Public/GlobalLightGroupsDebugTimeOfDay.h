#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GlobalLightGroupsDebugTimeOfDay.generated.h"

USTRUCT(BlueprintType)
struct FGlobalLightGroupsDebugTimeOfDay {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDateTime DateTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString DateTimeString;
    
    GLOBALLIGHTGROUPS_API FGlobalLightGroupsDebugTimeOfDay();
};


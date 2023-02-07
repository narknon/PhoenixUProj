#pragma once
#include "CoreMinimal.h"
#include "GlobalLightGroupsScheduleDebugMapEntry.generated.h"

USTRUCT(BlueprintType)
struct FGlobalLightGroupsScheduleDebugMapEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Key;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FString> ScheduleEntries;
    
    GLOBALLIGHTGROUPS_API FGlobalLightGroupsScheduleDebugMapEntry();
};


#pragma once
#include "CoreMinimal.h"
#include "GlobalLightGroupsComponentSchedule.h"
#include "GlobalLightGroupsComponentSchedules.generated.h"

class ULightComponent;

USTRUCT(BlueprintType)
struct FGlobalLightGroupsComponentSchedules {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<TWeakObjectPtr<ULightComponent>, FGlobalLightGroupsComponentSchedule> Schedules;
    
    GLOBALLIGHTGROUPS_API FGlobalLightGroupsComponentSchedules();
};


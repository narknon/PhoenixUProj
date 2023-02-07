#pragma once
#include "CoreMinimal.h"
#include "LightComponentSchedule.h"
#include "LightComponentSchedules.generated.h"

class USceneComponent;

USTRUCT(BlueprintType)
struct FLightComponentSchedules {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<TWeakObjectPtr<USceneComponent>, FLightComponentSchedule> Schedules;
    
    GLOBALLIGHTGROUPS_API FLightComponentSchedules();
};


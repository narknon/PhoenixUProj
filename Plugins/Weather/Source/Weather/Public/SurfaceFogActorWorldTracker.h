#pragma once
#include "CoreMinimal.h"
#include "SurfaceFogActorTracker.h"
#include "SurfaceFogActorWorldTracker.generated.h"

class UWorld;

USTRUCT(BlueprintType)
struct FSurfaceFogActorWorldTracker {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<UWorld*, FSurfaceFogActorTracker> Trackers;
    
    WEATHER_API FSurfaceFogActorWorldTracker();
};


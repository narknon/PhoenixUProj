#pragma once
#include "CoreMinimal.h"
#include "EVanishmentEventType.h"
#include "VanishmentEvent.generated.h"

USTRUCT(BlueprintType)
struct FVanishmentEvent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName SurfaceTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EVanishmentEventType EventType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DesiredDurationSeconds;
    
    PHOENIX_API FVanishmentEvent();
};


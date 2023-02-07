#pragma once
#include "CoreMinimal.h"
#include "HoverDataEvent.generated.h"

USTRUCT(BlueprintType)
struct FHoverDataEvent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool isWayMarker;
    
    PHOENIX_API FHoverDataEvent();
};


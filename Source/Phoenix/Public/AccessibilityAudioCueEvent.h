#pragma once
#include "CoreMinimal.h"
#include "MapIconEntry.h"
#include "AccessibilityAudioCueEvent.generated.h"

USTRUCT(BlueprintType)
struct FAccessibilityAudioCueEvent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FMapIconEntry> Icons;
    
    PHOENIX_API FAccessibilityAudioCueEvent();
};


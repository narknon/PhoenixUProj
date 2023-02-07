#pragma once
#include "CoreMinimal.h"
#include "AkXboxOneGDKApuHeapInitializationSettings.generated.h"

USTRUCT(BlueprintType)
struct FAkXboxOneGDKApuHeapInitializationSettings {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint32 CachedSize;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint32 NonCachedSize;
    
    AKAUDIO_API FAkXboxOneGDKApuHeapInitializationSettings();
};


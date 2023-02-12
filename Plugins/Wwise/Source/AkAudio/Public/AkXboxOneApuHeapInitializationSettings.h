#pragma once
#include "CoreMinimal.h"
#include "AkXboxOneApuHeapInitializationSettings.generated.h"

USTRUCT(BlueprintType)
struct FAkXboxOneApuHeapInitializationSettings {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint32 CachedSize;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint32 NonCachedSize;
    
    AKAUDIO_API FAkXboxOneApuHeapInitializationSettings();
};


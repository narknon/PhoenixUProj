#pragma once
#include "CoreMinimal.h"
#include "AkXSXApuHeapInitializationSettings.generated.h"

USTRUCT(BlueprintType)
struct FAkXSXApuHeapInitializationSettings {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint32 CachedSize;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint32 NonCachedSize;
    
    AKAUDIO_API FAkXSXApuHeapInitializationSettings();
};


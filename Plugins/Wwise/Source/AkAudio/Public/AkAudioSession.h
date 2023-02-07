#pragma once
#include "CoreMinimal.h"
#include "EAkAudioSessionCategory.h"
#include "EAkAudioSessionMode.h"
#include "AkAudioSession.generated.h"

USTRUCT(BlueprintType)
struct FAkAudioSession {
    GENERATED_BODY()
public:
    UPROPERTY(Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAkAudioSessionCategory AudioSessionCategory;
    
    UPROPERTY(Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint32 AudioSessionCategoryOptions;
    
    UPROPERTY(Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAkAudioSessionMode AudioSessionMode;
    
    AKAUDIO_API FAkAudioSession();
};


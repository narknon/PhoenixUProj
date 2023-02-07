#pragma once
#include "CoreMinimal.h"
#include "AkCommunicationSettings.h"
#include "AkCommunicationSettingsWithSystemInitialization.generated.h"

USTRUCT(BlueprintType)
struct FAkCommunicationSettingsWithSystemInitialization : public FAkCommunicationSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool InitializeSystemComms;
    
    AKAUDIO_API FAkCommunicationSettingsWithSystemInitialization();
};


#pragma once
#include "CoreMinimal.h"
#include "AkCommunicationSettings.h"
#include "EAkCommSystem.h"
#include "AkCommunicationSettingsWithCommSelection.generated.h"

USTRUCT(BlueprintType)
struct FAkCommunicationSettingsWithCommSelection : public FAkCommunicationSettings {
    GENERATED_BODY()
public:
    UPROPERTY(Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAkCommSystem CommunicationSystem;
    
    AKAUDIO_API FAkCommunicationSettingsWithCommSelection();
};


#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "SanctuaryIdentitySettings.h"
#include "SanctuaryIdentitySettingsAsset.generated.h"

UCLASS(Blueprintable)
class USanctuaryIdentitySettingsAsset : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSanctuaryIdentitySettings IdentitySettings;
    
    USanctuaryIdentitySettingsAsset();
};


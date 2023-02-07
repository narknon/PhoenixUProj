#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "RenderSettingsPostProcessingGroup.h"
#include "RenderSettingsPostProcessingGroupSettings.generated.h"

UCLASS(Blueprintable)
class RENDERSETTINGS_API URenderSettingsPostProcessingGroupSettings : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FRenderSettingsPostProcessingGroup> Settings;
    
    URenderSettingsPostProcessingGroupSettings();
};


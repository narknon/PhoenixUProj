#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "RenderSettingsPPDepthOfField.h"
#include "RenderSettingsPPDepthOfFieldSettings.generated.h"

UCLASS(Blueprintable)
class RENDERSETTINGS_API URenderSettingsPPDepthOfFieldSettings : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FRenderSettingsPPDepthOfField> Settings;
    
    URenderSettingsPPDepthOfFieldSettings();
};


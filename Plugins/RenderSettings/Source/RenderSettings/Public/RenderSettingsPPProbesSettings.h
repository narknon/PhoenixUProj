#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "RenderSettingsPPProbes.h"
#include "RenderSettingsPPProbesSettings.generated.h"

UCLASS(Blueprintable)
class RENDERSETTINGS_API URenderSettingsPPProbesSettings : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FRenderSettingsPPProbes> Settings;
    
    URenderSettingsPPProbesSettings();
};


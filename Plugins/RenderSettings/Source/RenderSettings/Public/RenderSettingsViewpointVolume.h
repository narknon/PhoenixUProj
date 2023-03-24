#pragma once
#include "CoreMinimal.h"
#include "RenderSettingsViewpointVolumeBase.h"
#include "RenderSettingsViewpointVolume.generated.h"

UCLASS(Blueprintable)
class RENDERSETTINGS_API ARenderSettingsViewpointVolume : public ARenderSettingsViewpointVolumeBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ViewpointLerp;
    
    ARenderSettingsViewpointVolume(const FObjectInitializer& ObjectInitializer);
};


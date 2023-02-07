#pragma once
#include "CoreMinimal.h"
#include "RenderSettingsViewpointVolumeBase.h"
#include "RenderSettingsViewpointInsideOutsideVolume.generated.h"

UCLASS(Blueprintable)
class RENDERSETTINGS_API ARenderSettingsViewpointInsideOutsideVolume : public ARenderSettingsViewpointVolumeBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TargetViewpointLerp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InsideMaxDifference;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InsideMinDifference;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float ViewpointLerp;
    
public:
    ARenderSettingsViewpointInsideOutsideVolume();
};


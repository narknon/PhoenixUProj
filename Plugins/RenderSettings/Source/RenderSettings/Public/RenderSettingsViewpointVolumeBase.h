#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Volume.h"
#include "RenderSettingsViewpointVolumeBase.generated.h"

UCLASS(Abstract, Blueprintable)
class RENDERSETTINGS_API ARenderSettingsViewpointVolumeBase : public AVolume {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    float Priority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    float BlendRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    float BlendWeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    bool bUnbounded;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    bool bEnabled;
    
    ARenderSettingsViewpointVolumeBase(const FObjectInitializer& ObjectInitializer);
};


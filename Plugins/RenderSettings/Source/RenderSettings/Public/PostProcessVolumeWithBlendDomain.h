#pragma once
#include "CoreMinimal.h"
#include "Engine/PostProcessVolume.h"
#include "BlendDomain.h"
#include "PostProcessVolumeWithBlendDomain.generated.h"

UCLASS(Blueprintable)
class RENDERSETTINGS_API APostProcessVolumeWithBlendDomain : public APostProcessVolume {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBlendDomain BlendDomain;
    
    APostProcessVolumeWithBlendDomain(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void CopySettings();
    
};


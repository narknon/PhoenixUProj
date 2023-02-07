#pragma once
#include "CoreMinimal.h"
#include "AnimatedLightClusterComponent.h"
#include "DynamicLightAdaptationSettings.h"
#include "LightAdaptationComponent.generated.h"

UCLASS(Abstract, Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class RENDERSETTINGS_API ULightAdaptationComponent : public UAnimatedLightClusterComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDynamicLightAdaptationSettings Settings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float Adaptation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float LastExposure;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    uint32 FirstUpdateFrame;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bForceClusterUpdate;
    
    ULightAdaptationComponent();
};


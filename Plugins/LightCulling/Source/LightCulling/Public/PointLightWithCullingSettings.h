#pragma once
#include "CoreMinimal.h"
#include "Engine/Light.h"
#include "PointLightWithCullingSettings.generated.h"

class UPointLightComponentWithCullingSettings;

UCLASS(Blueprintable)
class LIGHTCULLING_API APointLightWithCullingSettings : public ALight {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPointLightComponentWithCullingSettings* PointLightComponent;
    
    APointLightWithCullingSettings(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void Copy();
    
};


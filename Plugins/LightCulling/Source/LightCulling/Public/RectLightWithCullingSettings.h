#pragma once
#include "CoreMinimal.h"
#include "Engine/Light.h"
#include "RectLightWithCullingSettings.generated.h"

class URectLightComponentWithCullingSettings;

UCLASS(Blueprintable)
class LIGHTCULLING_API ARectLightWithCullingSettings : public ALight {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    URectLightComponentWithCullingSettings* RectLightComponent;
    
    ARectLightWithCullingSettings(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void Copy();
    
};


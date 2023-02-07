#pragma once
#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "LightTemplateSettings.h"
#include "LightTemplateComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ULightTemplateComponent : public USceneComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLightTemplateSettings TemplateSettings;
    
    ULightTemplateComponent();
    UFUNCTION(BlueprintCallable)
    void SetIntensityFactor(float InIntensityFactor, bool bApplyNow);
    
};


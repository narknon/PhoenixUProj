#pragma once
#include "CoreMinimal.h"
#include "FadeToDecalPointLightComponent.h"
#include "FillDecalPointLightComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class FXUTIL_API UFillDecalPointLightComponent : public UFadeToDecalPointLightComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float IntensityMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InnerCutoutRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float OuterCutoutRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FullRadius;
    
    UFillDecalPointLightComponent();
    UFUNCTION(BlueprintCallable)
    void SetRadii(float NewInnerCutoutRadius, float NewOuterCutoutRadius, float NewFullRadius);
    
    UFUNCTION(BlueprintCallable)
    void SetOuterCutoutRadius(float NewOuterCutoutRadius);
    
    UFUNCTION(BlueprintCallable)
    void SetIntensityMultiplier(float NewIntensityMultiplier);
    
    UFUNCTION(BlueprintCallable)
    void SetInnerCutoutRadius(float NewInnerCutoutRadius);
    
    UFUNCTION(BlueprintCallable)
    void SetFullRadius(float NewFullRadius);
    
};


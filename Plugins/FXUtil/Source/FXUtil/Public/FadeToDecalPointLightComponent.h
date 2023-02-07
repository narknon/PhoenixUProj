#pragma once
#include "CoreMinimal.h"
#include "DecalPointLightComponentBase.h"
#include "FadeToDecalPointLightComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class FXUTIL_API UFadeToDecalPointLightComponent : public UDecalPointLightComponentBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseLightVisibility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bLightParametersCanChange;
    
    UFadeToDecalPointLightComponent();
    UFUNCTION(BlueprintCallable)
    void SetUseLightVisibility(bool bNewUseLightVisibility);
    
    UFUNCTION(BlueprintCallable)
    void SetLightParametersCanChange(bool bNewLightParametersCanChange);
    
};


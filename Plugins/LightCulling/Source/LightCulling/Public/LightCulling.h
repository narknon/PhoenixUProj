#pragma once
#include "CoreMinimal.h"
#include "LightCullingLight.h"
#include "LightCulling.generated.h"

class ULocalLightComponent;

USTRUCT(BlueprintType)
struct LIGHTCULLING_API FLightCulling {
    GENERATED_BODY()
public:
private:
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<TWeakObjectPtr<ULocalLightComponent>, FLightCullingLight> Lights;
    
    UPROPERTY(EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<ULocalLightComponent>> IgnoreLights;
    
public:
    FLightCulling();
};


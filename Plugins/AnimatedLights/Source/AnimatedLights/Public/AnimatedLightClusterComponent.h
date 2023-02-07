#pragma once
#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "AnimatedLightClusterComponent.generated.h"

class UAnimatedLightsClusterSettings;
class ULightComponent;

UCLASS(Abstract, Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ANIMATEDLIGHTS_API UAnimatedLightClusterComponent : public USceneComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimatedLightsClusterSettings* CullingSettings;
    
    UPROPERTY(EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<ULightComponent>> LightComponents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float MaxVisibleDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float SleepDeltaTime;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCanForceUpdates;
    
public:
    UAnimatedLightClusterComponent();
    UFUNCTION(BlueprintCallable)
    void RebuildLights();
    
};


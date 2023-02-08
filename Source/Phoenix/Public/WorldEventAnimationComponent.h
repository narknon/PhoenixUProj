#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "WorldEventAnimationComponent.generated.h"



UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UWorldEventAnimationComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UWorldEventAnimationComponent();
    UFUNCTION(BlueprintCallable)
    void SetAnimation(UAnimationAsset* InAnimation);
    
    UFUNCTION(BlueprintCallable)
    void RemoveComponent();
    
    UFUNCTION(BlueprintCallable)
    UAnimationAsset* GetAnimation();
    
};


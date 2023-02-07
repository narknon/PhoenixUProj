#pragma once
#include "CoreMinimal.h"
#include "PointAtActorBaseComponent.h"
#include "PointAtActorTargetComponent.generated.h"

class AActor;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UPointAtActorTargetComponent : public UPointAtActorBaseComponent {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<AActor> Target;
    
    UPointAtActorTargetComponent();
    UFUNCTION(BlueprintCallable)
    void PointAtActorSetTarget(AActor* TargetActor);
    
    UFUNCTION(BlueprintCallable)
    void PointAtActorClearTarget(AActor* TargetActor);
    
};


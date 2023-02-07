#pragma once
#include "CoreMinimal.h"
#include "StateEffectComponent.h"
#include "UncurseComponent.generated.h"

class AActor;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UUncurseComponent : public UStateEffectComponent {
    GENERATED_BODY()
public:
    UUncurseComponent();
    UFUNCTION(BlueprintCallable)
    void AddToInstanceList(AActor* InInstigator, int32 InMaxInstancesPerInstigator);
    
};


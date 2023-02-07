#pragma once
#include "CoreMinimal.h"
#include "ActorTracker.h"
#include "ComponentTracker.generated.h"

class USceneComponent;

USTRUCT(BlueprintType)
struct SKINFX_API FComponentTracker : public FActorTracker {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<USceneComponent> SceneComponent;
    
public:
    FComponentTracker();
};


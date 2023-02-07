#pragma once
#include "CoreMinimal.h"
#include "LightCullingLightPhysicsParent.generated.h"

class UPrimitiveComponent;

USTRUCT(BlueprintType)
struct FLightCullingLightPhysicsParent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UPrimitiveComponent> PhysicsParentPtr;
    
public:
    LIGHTCULLING_API FLightCullingLightPhysicsParent();
};


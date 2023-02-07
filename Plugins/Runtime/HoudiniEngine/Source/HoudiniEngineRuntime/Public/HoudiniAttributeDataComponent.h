#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HoudiniAttributeDataComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class HOUDINIENGINERUNTIME_API UHoudiniAttributeDataComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UHoudiniAttributeDataComponent();
};


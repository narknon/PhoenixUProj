#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AnimNotifyStaticMeshPropComponent.generated.h"

UCLASS(Blueprintable, Transient, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class AVAANIMATION_API UAnimNotifyStaticMeshPropComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UAnimNotifyStaticMeshPropComponent();
};


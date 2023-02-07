#pragma once
#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "BeamTarget.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UBeamTarget : public USceneComponent {
    GENERATED_BODY()
public:
    UBeamTarget();
};


#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SplineToolGenerator.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class PHOENIX_API USplineToolGenerator : public UActorComponent {
    GENERATED_BODY()
public:
    USplineToolGenerator();
};


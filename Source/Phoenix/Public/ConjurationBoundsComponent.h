#pragma once
#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "ConjurationBoundsComponent.generated.h"

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UConjurationBoundsComponent : public UBoxComponent {
    GENERATED_BODY()
public:
    UConjurationBoundsComponent();
};


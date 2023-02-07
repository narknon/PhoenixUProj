#pragma once
#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "ConjurationWallAlignmentComponent.generated.h"

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UConjurationWallAlignmentComponent : public UBoxComponent {
    GENERATED_BODY()
public:
    UConjurationWallAlignmentComponent();
};


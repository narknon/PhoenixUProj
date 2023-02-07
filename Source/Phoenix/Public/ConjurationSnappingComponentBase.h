#pragma once
#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "ConjurationSnappingComponentBase.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class PHOENIX_API UConjurationSnappingComponentBase : public UBoxComponent {
    GENERATED_BODY()
public:
    UConjurationSnappingComponentBase();
};


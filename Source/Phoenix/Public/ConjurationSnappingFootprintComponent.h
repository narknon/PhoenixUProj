#pragma once
#include "CoreMinimal.h"
#include "ConjurationSnappingComponentBase.h"
#include "ConjurationSnappingFootprintComponent.generated.h"

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class PHOENIX_API UConjurationSnappingFootprintComponent : public UConjurationSnappingComponentBase {
    GENERATED_BODY()
public:
    UConjurationSnappingFootprintComponent();
};


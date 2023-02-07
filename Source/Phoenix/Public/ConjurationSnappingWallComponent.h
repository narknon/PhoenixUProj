#pragma once
#include "CoreMinimal.h"
#include "ConjurationSnappingComponentBase.h"
#include "ConjurationSnappingWallComponent.generated.h"

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class PHOENIX_API UConjurationSnappingWallComponent : public UConjurationSnappingComponentBase {
    GENERATED_BODY()
public:
    UConjurationSnappingWallComponent();
};


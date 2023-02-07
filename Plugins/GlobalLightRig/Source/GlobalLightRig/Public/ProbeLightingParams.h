#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ProbeLightingParams.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, Const, EditInlineNew)
class GLOBALLIGHTRIG_API UProbeLightingParams : public UObject {
    GENERATED_BODY()
public:
    UProbeLightingParams();
};


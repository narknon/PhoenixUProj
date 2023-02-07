#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "BaseArchitectFilter.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, Const, EditInlineNew)
class ANIMATIONARCHITECTRUNTIME_API UBaseArchitectFilter : public UObject {
    GENERATED_BODY()
public:
    UBaseArchitectFilter();
};


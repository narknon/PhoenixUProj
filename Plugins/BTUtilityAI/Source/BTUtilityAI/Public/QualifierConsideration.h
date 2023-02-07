#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "QualifierConsideration.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, DefaultToInstanced, EditInlineNew)
class BTUTILITYAI_API UQualifierConsideration : public UObject {
    GENERATED_BODY()
public:
    UQualifierConsideration();
};


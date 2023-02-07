#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "QualifierOptions.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, DefaultToInstanced, EditInlineNew)
class BTUTILITYAI_API UQualifierOptions : public UObject {
    GENERATED_BODY()
public:
    UQualifierOptions();
};


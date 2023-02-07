#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "QualifierTask.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, DefaultToInstanced, EditInlineNew)
class BTUTILITYAI_API UQualifierTask : public UObject {
    GENERATED_BODY()
public:
    UQualifierTask();
};


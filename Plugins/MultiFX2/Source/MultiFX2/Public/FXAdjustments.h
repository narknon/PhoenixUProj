#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "FXAdjustments.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, Const, EditInlineNew)
class MULTIFX2_API UFXAdjustments : public UObject {
    GENERATED_BODY()
public:
    UFXAdjustments();
};


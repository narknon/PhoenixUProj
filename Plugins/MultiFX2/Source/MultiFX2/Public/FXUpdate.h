#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "FXUpdate.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class MULTIFX2_API UFXUpdate : public UObject {
    GENERATED_BODY()
public:
    UFXUpdate();
};


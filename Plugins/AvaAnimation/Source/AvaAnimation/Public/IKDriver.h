#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "IKDriver.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, Const, EditInlineNew)
class AVAANIMATION_API UIKDriver : public UObject {
    GENERATED_BODY()
public:
    UIKDriver();
};


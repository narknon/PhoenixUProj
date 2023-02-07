#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "CameraFixupSetPositionMethod.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, Const, EditInlineNew)
class AVAANIMATION_API UCameraFixupSetPositionMethod : public UObject {
    GENERATED_BODY()
public:
    UCameraFixupSetPositionMethod();
};


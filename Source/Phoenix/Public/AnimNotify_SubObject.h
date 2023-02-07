#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AnimNotify_SubObject.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, Const)
class UAnimNotify_SubObject : public UObject {
    GENERATED_BODY()
public:
    UAnimNotify_SubObject();
};


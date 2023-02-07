#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "CloudsWindParams.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, Const, EditInlineNew)
class GLOBALLIGHTRIG_API UCloudsWindParams : public UObject {
    GENERATED_BODY()
public:
    UCloudsWindParams();
};


#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "WindEnvelopeController.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, Const, EditInlineNew)
class UWindEnvelopeController : public UObject {
    GENERATED_BODY()
public:
    UWindEnvelopeController();
};


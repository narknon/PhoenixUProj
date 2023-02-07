#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "MultiFX2_Base.generated.h"

UCLASS(Abstract, Blueprintable, Const, EditInlineNew)
class MULTIFX2_API UMultiFX2_Base : public UObject {
    GENERATED_BODY()
public:
    UMultiFX2_Base();
};


#pragma once
#include "CoreMinimal.h"
#include "MultiFX2_Filtered.h"
#include "MultiFX2_CustomDepthLockBase.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class UMultiFX2_CustomDepthLockBase : public UMultiFX2_Filtered {
    GENERATED_BODY()
public:
    UMultiFX2_CustomDepthLockBase();
};


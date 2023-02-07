#pragma once
#include "CoreMinimal.h"
#include "ModFilter.h"
#include "ModFilter_VendorTransaction_Base.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UModFilter_VendorTransaction_Base : public UModFilter {
    GENERATED_BODY()
public:
    UModFilter_VendorTransaction_Base();
};


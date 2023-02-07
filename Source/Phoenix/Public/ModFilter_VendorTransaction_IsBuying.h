#pragma once
#include "CoreMinimal.h"
#include "ModFilter_VendorTransaction_Base.h"
#include "ModFilter_VendorTransaction_IsBuying.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UModFilter_VendorTransaction_IsBuying : public UModFilter_VendorTransaction_Base {
    GENERATED_BODY()
public:
    UModFilter_VendorTransaction_IsBuying();
};


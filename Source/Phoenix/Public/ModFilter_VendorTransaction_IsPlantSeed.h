#pragma once
#include "CoreMinimal.h"
#include "ModFilter_VendorTransaction_Base.h"
#include "ModFilter_VendorTransaction_IsPlantSeed.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UModFilter_VendorTransaction_IsPlantSeed : public UModFilter_VendorTransaction_Base {
    GENERATED_BODY()
public:
    UModFilter_VendorTransaction_IsPlantSeed();
};


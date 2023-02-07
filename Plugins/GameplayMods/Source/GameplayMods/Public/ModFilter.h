#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ModFilter.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class GAMEPLAYMODS_API UModFilter : public UPrimaryDataAsset {
    GENERATED_BODY()
public:
    UModFilter();
};


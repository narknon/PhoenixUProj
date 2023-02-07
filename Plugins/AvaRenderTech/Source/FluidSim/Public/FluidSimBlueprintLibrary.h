#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FluidSimBlueprintLibrary.generated.h"

UCLASS(Blueprintable, MinimalAPI)
class UFluidSimBlueprintLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UFluidSimBlueprintLibrary();
};


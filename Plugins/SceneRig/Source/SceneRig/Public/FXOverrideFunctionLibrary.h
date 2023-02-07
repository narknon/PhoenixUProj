#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FXOverride.h"
#include "FXOverrideFunctionLibrary.generated.h"

UCLASS(Blueprintable)
class UFXOverrideFunctionLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UFXOverrideFunctionLibrary();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsMatch(const FFXOverride& FXOverride);
    
};


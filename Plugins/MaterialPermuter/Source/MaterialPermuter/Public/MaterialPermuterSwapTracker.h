#pragma once
#include "CoreMinimal.h"
#include "MaterialPermuterSwapTracker.generated.h"

class UMeshComponent;
class UObject;

USTRUCT(BlueprintType)
struct MATERIALPERMUTER_API FMaterialPermuterSwapTracker {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<TWeakObjectPtr<UMeshComponent>, TWeakObjectPtr<UObject>> ActiveSwaps;
    
    FMaterialPermuterSwapTracker();
};


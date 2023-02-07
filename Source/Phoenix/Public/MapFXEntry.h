#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MapFXEntry.generated.h"

USTRUCT(BlueprintType)
struct FMapFXEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName FXName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName FXPath;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Scale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool Looped;
    
    PHOENIX_API FMapFXEntry();
};


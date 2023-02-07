#pragma once
#include "CoreMinimal.h"
#include "WorldFXOctreeFXList.generated.h"

class UWorldFXOctreeFX;

USTRUCT(BlueprintType)
struct FWorldFXOctreeFXList {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UWorldFXOctreeFX*> FXList;
    
    WORLDFX_API FWorldFXOctreeFXList();
};


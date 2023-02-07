#pragma once
#include "CoreMinimal.h"
#include "DeflectionData.generated.h"

class UMultiFX2_Base;

USTRUCT(BlueprintType)
struct FDeflectionData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UMultiFX2_Base*> DeflectedFX2;
    
    PHOENIX_API FDeflectionData();
};


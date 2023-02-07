#pragma once
#include "CoreMinimal.h"
#include "ConfundoData.generated.h"

class UMultiFX2_Base;

USTRUCT(BlueprintType)
struct FConfundoData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UMultiFX2_Base*> FX2;
    
    PHOENIX_API FConfundoData();
};


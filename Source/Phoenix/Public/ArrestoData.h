#pragma once
#include "CoreMinimal.h"
#include "ArrestoData.generated.h"

class UMultiFX2_Base;

USTRUCT(BlueprintType)
struct FArrestoData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UMultiFX2_Base*> FX2;
    
    PHOENIX_API FArrestoData();
};


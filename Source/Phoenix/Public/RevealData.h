#pragma once
#include "CoreMinimal.h"
#include "RevealData.generated.h"

class UMultiFX2_Base;

USTRUCT(BlueprintType)
struct FRevealData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UMultiFX2_Base*> FX2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UMultiFX2_Base*> GlobalFX2;
    
    PHOENIX_API FRevealData();
};


#pragma once
#include "CoreMinimal.h"
#include "ImperiusData.generated.h"

class UGameplayPropertyMod;
class UMultiFX2_Base;

USTRUCT(BlueprintType)
struct FImperiusData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UMultiFX2_Base*> FX2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UGameplayPropertyMod* Mod;
    
    PHOENIX_API FImperiusData();
};


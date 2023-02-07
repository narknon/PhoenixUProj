#pragma once
#include "CoreMinimal.h"
#include "MultiFX.h"
#include "PerkInfoFX.generated.h"

USTRUCT(BlueprintType)
struct FPerkInfoFX {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMultiFX PerkFX;
    
    PHOENIX_API FPerkInfoFX();
};


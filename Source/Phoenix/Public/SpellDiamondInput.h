#pragma once
#include "CoreMinimal.h"
#include "SpellDiamondInput.generated.h"

USTRUCT(BlueprintType)
struct FSpellDiamondInput {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Slot1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Slot2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Slot3;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Slot4;
    
    PHOENIX_API FSpellDiamondInput();
};


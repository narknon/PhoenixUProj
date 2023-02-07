#pragma once
#include "CoreMinimal.h"
#include "SpellLoadOut.h"
#include "SpellLoadOutData.generated.h"

class USpellToolRecord;

USTRUCT(BlueprintType)
struct FSpellLoadOutData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FSpellLoadOut> SpellLoadouts;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<USpellToolRecord*> SpellFinishers;
    
    PHOENIX_API FSpellLoadOutData();
};


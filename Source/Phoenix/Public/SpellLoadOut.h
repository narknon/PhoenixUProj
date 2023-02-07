#pragma once
#include "CoreMinimal.h"
#include "SpellLoadOut.generated.h"

class USpellToolRecord;

USTRUCT(BlueprintType)
struct FSpellLoadOut {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<USpellToolRecord*> SpellToolRecords;
    
    PHOENIX_API FSpellLoadOut();
};


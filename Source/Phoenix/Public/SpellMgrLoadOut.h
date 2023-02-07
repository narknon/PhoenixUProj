#pragma once
#include "CoreMinimal.h"
#include "SpellMgrLoadOut.generated.h"

USTRUCT(BlueprintType)
struct FSpellMgrLoadOut {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> SpellNames;
    
    PHOENIX_API FSpellMgrLoadOut();
};


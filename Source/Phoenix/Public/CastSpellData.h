#pragma once
#include "CoreMinimal.h"
#include "CastSpellData.generated.h"

class AActor;
class USpellToolRecord;

USTRUCT(BlueprintType)
struct FCastSpellData {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<AActor> TargetActor;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<AActor> Instigator;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USpellToolRecord* SpellToolRecord;
    
    PHOENIX_API FCastSpellData();
};


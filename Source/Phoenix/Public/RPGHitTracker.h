#pragma once
#include "CoreMinimal.h"
#include "RPGHitTracker.generated.h"

class AActor;
class USpellToolRecord;

USTRUCT(BlueprintType)
struct FRPGHitTracker {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* Target;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float Timestamp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USpellToolRecord* Spell;
    
    PHOENIX_API FRPGHitTracker();
};


#pragma once
#include "CoreMinimal.h"
#include "SpellCastData.generated.h"

class AActor;

USTRUCT(BlueprintType)
struct FSpellCastData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* Target;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* Instigator;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName SpellType;
    
    PHOENIX_API FSpellCastData();
};


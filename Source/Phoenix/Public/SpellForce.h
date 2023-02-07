#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SpellForce.generated.h"

USTRUCT(BlueprintType)
struct FSpellForce {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector m_forceVector;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector m_appliedLocation;
    
    PHOENIX_API FSpellForce();
};


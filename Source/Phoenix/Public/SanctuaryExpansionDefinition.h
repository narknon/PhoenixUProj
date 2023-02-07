#pragma once
#include "CoreMinimal.h"
#include "SanctuaryExpansionDefinition.generated.h"

USTRUCT(BlueprintType)
struct FSanctuaryExpansionDefinition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ExpansionLockID;
    
    PHOENIX_API FSanctuaryExpansionDefinition();
};


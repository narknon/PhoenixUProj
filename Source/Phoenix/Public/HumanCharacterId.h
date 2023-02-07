#pragma once
#include "CoreMinimal.h"
#include "HumanCharacterId.generated.h"

USTRUCT(BlueprintType)
struct FHumanCharacterId {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ID;
    
    PHOENIX_API FHumanCharacterId();
};


#pragma once
#include "CoreMinimal.h"
#include "CharacterName.generated.h"

USTRUCT(BlueprintType)
struct FCharacterName {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName CharacterName;
    
    PHOENIX_API FCharacterName();
};


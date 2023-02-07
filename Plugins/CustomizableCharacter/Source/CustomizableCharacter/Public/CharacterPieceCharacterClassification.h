#pragma once
#include "CoreMinimal.h"
#include "CharacterPieceCharacterClassification.generated.h"

USTRUCT(BlueprintType)
struct FCharacterPieceCharacterClassification {
    GENERATED_BODY()
public:
    UPROPERTY(AssetRegistrySearchable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Type;
    
    CUSTOMIZABLECHARACTER_API FCharacterPieceCharacterClassification();
};


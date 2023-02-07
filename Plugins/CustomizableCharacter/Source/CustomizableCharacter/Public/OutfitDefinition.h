#pragma once
#include "CoreMinimal.h"
#include "CharacterPieceDefinition.h"
#include "OutfitDefinition.generated.h"

USTRUCT(BlueprintType)
struct CUSTOMIZABLECHARACTER_API FOutfitDefinition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FCharacterPieceDefinition> OutfitItems;
    
    FOutfitDefinition();
};


#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "CharacterPieceCharacterType.h"
#include "CharacterClassificationRow.generated.h"

USTRUCT(BlueprintType)
struct FCharacterClassificationRow : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSet<FCharacterPieceCharacterType> CharacterTypes;
    
    CUSTOMIZABLECHARACTER_API FCharacterClassificationRow();
};


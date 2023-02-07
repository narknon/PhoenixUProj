#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "DbCharacterPiece.generated.h"

class UCharacterPiece;

USTRUCT(BlueprintType)
struct FDbCharacterPiece : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UCharacterPiece> CharacterPiece;
    
    CUSTOMIZABLECHARACTER_API FDbCharacterPiece();
};


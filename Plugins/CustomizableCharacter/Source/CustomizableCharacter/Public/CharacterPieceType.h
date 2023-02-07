#pragma once
#include "CoreMinimal.h"
#include "CharacterPieceType.generated.h"

USTRUCT(BlueprintType)
struct FCharacterPieceType {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Type;
    
    CUSTOMIZABLECHARACTER_API FCharacterPieceType();
};


#pragma once
#include "CoreMinimal.h"
#include "CharacterPieceCharacterType.generated.h"

USTRUCT(BlueprintType)
struct FCharacterPieceCharacterType {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Type;
    
    CUSTOMIZABLECHARACTER_API FCharacterPieceCharacterType();
};

FORCEINLINE uint32 GetTypeHash(const FCharacterPieceCharacterType) { return 0; }


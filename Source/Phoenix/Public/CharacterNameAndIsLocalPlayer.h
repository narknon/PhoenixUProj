#pragma once
#include "CoreMinimal.h"
#include "CharacterNameAndIsLocalPlayer.generated.h"

USTRUCT(BlueprintType)
struct FCharacterNameAndIsLocalPlayer {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName CharacterName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool LocalPlayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString ActorProvider;
    
    PHOENIX_API FCharacterNameAndIsLocalPlayer();
};

FORCEINLINE uint32 GetTypeHash(const FCharacterNameAndIsLocalPlayer) { return 0; }
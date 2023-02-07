#pragma once
#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "PersistentOffline.generated.h"

UCLASS(Blueprintable)
class PERSISTENTDATA_API UPersistentOffline : public USaveGame {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString EpicAccountID;
    
    UPersistentOffline();
};


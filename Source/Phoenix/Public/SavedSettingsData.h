#pragma once
#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "SavedSettingsData.generated.h"

UCLASS(Blueprintable)
class USavedSettingsData : public USaveGame {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<uint8> SettingsData;
    
    USavedSettingsData();
};


#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "GameLogicMaster.generated.h"

class UGameLogicGameSettings;

UCLASS(Blueprintable, Config=Engine, DefaultConfig, Config=Game)
class GAMELOGICRUNTIME_API UGameLogicMaster : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGameLogicGameSettings* GameLogicGameSettings;
    
    UGameLogicMaster();
};


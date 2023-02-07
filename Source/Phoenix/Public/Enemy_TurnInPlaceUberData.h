#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ENPC_GameContext.h"
#include "Enemy_TurnInPlaceUberData.generated.h"

USTRUCT(BlueprintType)
struct FEnemy_TurnInPlaceUberData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ENPC_GameContext GameContext;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSupported;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer AATags;
    
    PHOENIX_API FEnemy_TurnInPlaceUberData();
};


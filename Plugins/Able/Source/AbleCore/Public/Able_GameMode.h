#pragma once
#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "OnPauseEventDelegate.h"
#include "Able_GameMode.generated.h"

UCLASS(Blueprintable, NonTransient)
class ABLECORE_API AAble_GameMode : public AGameMode {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnPauseEvent OnPauseGameEvent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnPauseEvent OnClearPauseGameEvent;
    
    AAble_GameMode(const FObjectInitializer& ObjectInitializer);
};


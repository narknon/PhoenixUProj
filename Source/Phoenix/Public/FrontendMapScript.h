#pragma once
#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"
#include "FrontendMapScript.generated.h"

UCLASS(Blueprintable)
class AFrontendMapScript : public ALevelScriptActor {
    GENERATED_BODY()
public:
    AFrontendMapScript(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void GoToMenu();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void GoToIntro();
    
};


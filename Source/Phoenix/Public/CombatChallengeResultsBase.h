#pragma once
#include "CoreMinimal.h"
#include "Screen.h"
#include "CombatChallengeResultsBase.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class PHOENIX_API UCombatChallengeResultsBase : public UScreen {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString TitleText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ResultIsAVictory;
    
public:
    UCombatChallengeResultsBase();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ShowResultsScreen();
    
    UFUNCTION(BlueprintCallable)
    void RestartFromDeath();
    
    UFUNCTION(BlueprintCallable)
    void OnPostGameSave();
    
    UFUNCTION(BlueprintCallable)
    void ExitRequested();
    
};


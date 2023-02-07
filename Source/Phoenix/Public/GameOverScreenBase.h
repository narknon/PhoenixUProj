#pragma once
#include "CoreMinimal.h"
#include "EUIGameOverReason.h"
#include "Screen.h"
#include "GameOverScreenBase.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UGameOverScreenBase : public UScreen {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EUIGameOverReason MyReason;
    
public:
    UGameOverScreenBase();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ShowLoadSaveResultPopup(const FString& ResultMessage, float Duration);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetRestartButtonText(const FString& ButtonText);
    
    UFUNCTION(BlueprintCallable)
    void SetGameOverReason(EUIGameOverReason Reason);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void CannotAbandonQuest();
    
};


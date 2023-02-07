#pragma once
#include "CoreMinimal.h"
#include "EUIGameOverReason.h"
#include "Screen.h"
#include "MissionFailScreenBase.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UMissionFailScreenBase : public UScreen {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EUIGameOverReason MyReason;
    
public:
    UMissionFailScreenBase();
    UFUNCTION(BlueprintCallable)
    void SetReason(EUIGameOverReason Reason);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetDisplayText(const FString& Title, const FString& Description);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void CannotAbandonQuest();
    
};


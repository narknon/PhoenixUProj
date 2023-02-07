#pragma once
#include "CoreMinimal.h"
#include "BroomRiderSubActionBase.h"
#include "DialogueConversationReference.h"
#include "BroomRiderAction_PlayDialogue.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UBroomRiderAction_PlayDialogue : public UBroomRiderSubActionBase {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDialogueConversationReference DialogueEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bWaitForDialogueToComplete;
    
public:
    UBroomRiderAction_PlayDialogue();
private:
    UFUNCTION(BlueprintCallable)
    void OnDialogueComplete();
    
};


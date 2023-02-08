#pragma once
#include "CoreMinimal.h"
#include "AvaAudioDialogueEvent.h"
#include "MultiFX2_Filtered.h"
#include "AvaAudioDialogueFlags.h"
#include "PerformTasksForAI.h"
#include "MultiFX2_Dialogue.generated.h"



UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UMultiFX2_Dialogue : public UMultiFX2_Filtered {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAvaAudioDialogueEvent* DialogueEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString DialogueEventName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bStopWhenAttachedToDestroyed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AvaAudioDialogueFlags flags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIgnoreDeactivate;
    
public:
    UMultiFX2_Dialogue();
};


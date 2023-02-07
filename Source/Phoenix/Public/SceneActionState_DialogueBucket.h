#pragma once
#include "CoreMinimal.h"
#include "SceneRigObjectActionState.h"
#include "DialogueConversationReference.h"
#include "SceneActionState_DialogueBucket.generated.h"

UCLASS(Blueprintable)
class USceneActionState_DialogueBucket : public USceneRigObjectActionState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FDialogueConversationReference> EventBucket;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 AudioHandle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHasValidEnter;
    
    USceneActionState_DialogueBucket();
};


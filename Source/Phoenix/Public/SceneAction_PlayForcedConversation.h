#pragma once
#include "CoreMinimal.h"
#include "SceneRigObjectActionBase.h"
#include "TimeRigOutputSymbol.h"
#include "EPlayForcedConversation_ConversationInitializationTime.h"
#include "SceneAction_PlayForcedConversation.generated.h"

class UStoryGraph_Conversation;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_PlayForcedConversation : public USceneRigObjectActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName CharacterID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStoryGraph_Conversation* ConversationGraph;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimeRigOutputSymbol ConversationStart;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimeRigOutputSymbol ConversationEnd;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EPlayForcedConversation_ConversationInitializationTime ConversationInitializationTime;
    
    USceneAction_PlayForcedConversation();
};


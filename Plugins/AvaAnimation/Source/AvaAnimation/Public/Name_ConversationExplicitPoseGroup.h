#pragma once
#include "CoreMinimal.h"
#include "ConversationExplicitPoseGroupReference.h"
#include "NameProvider.h"
#include "Name_ConversationExplicitPoseGroup.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class AVAANIMATION_API UName_ConversationExplicitPoseGroup : public UNameProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FConversationExplicitPoseGroupReference Reference;
    
    UName_ConversationExplicitPoseGroup();
};


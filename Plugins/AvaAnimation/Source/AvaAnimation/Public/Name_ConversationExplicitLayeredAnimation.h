#pragma once
#include "CoreMinimal.h"
#include "ConversationExplicitLayeredAnimationReference.h"
#include "NameProvider.h"
#include "Name_ConversationExplicitLayeredAnimation.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class AVAANIMATION_API UName_ConversationExplicitLayeredAnimation : public UNameProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FConversationExplicitLayeredAnimationReference Reference;
    
    UName_ConversationExplicitLayeredAnimation();
};


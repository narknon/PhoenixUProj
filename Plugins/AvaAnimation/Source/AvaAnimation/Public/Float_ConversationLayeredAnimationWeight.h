#pragma once
#include "CoreMinimal.h"
#include "ConversationLayeredAnimationWeight.h"
#include "FloatProvider.h"
#include "Float_ConversationLayeredAnimationWeight.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class AVAANIMATION_API UFloat_ConversationLayeredAnimationWeight : public UFloatProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FConversationLayeredAnimationWeight WeightEntryName;
    
    UFloat_ConversationLayeredAnimationWeight();
};


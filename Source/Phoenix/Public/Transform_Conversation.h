#pragma once
#include "CoreMinimal.h"
#include "TransformProvider.h"
#include "EConversationTransformType.h"
#include "Transform_Conversation.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class PHOENIX_API UTransform_Conversation : public UTransformProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EConversationTransformType TransformType;
    
    UTransform_Conversation();
};


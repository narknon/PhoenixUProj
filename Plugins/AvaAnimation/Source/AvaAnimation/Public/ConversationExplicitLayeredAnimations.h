#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ConversationExplicitLayeredAnimationCategory.h"
#include "ConversationExplicitLayeredAnimations.generated.h"

UCLASS(Blueprintable)
class AVAANIMATION_API UConversationExplicitLayeredAnimations : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FConversationExplicitLayeredAnimationCategory> Categories;
    
    UConversationExplicitLayeredAnimations();
};


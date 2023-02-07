#pragma once
#include "CoreMinimal.h"
#include "ConversationExplicitLayeredAnimation.h"
#include "ConversationExplicitLayeredAnimationCategory.generated.h"

USTRUCT(BlueprintType)
struct AVAANIMATION_API FConversationExplicitLayeredAnimationCategory {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString DisplayName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Description;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FConversationExplicitLayeredAnimation> Animations;
    
    FConversationExplicitLayeredAnimationCategory();
};


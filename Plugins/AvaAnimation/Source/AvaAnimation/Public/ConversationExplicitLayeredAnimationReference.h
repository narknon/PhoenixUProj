#pragma once
#include "CoreMinimal.h"
#include "ConversationExplicitLayeredAnimationReference.generated.h"

USTRUCT(BlueprintType)
struct AVAANIMATION_API FConversationExplicitLayeredAnimationReference {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName CategoryName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName AnimationName;
    
    FConversationExplicitLayeredAnimationReference();
};


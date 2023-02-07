#pragma once
#include "CoreMinimal.h"
#include "ConversationExplicitCameraShotReference.generated.h"

USTRUCT(BlueprintType)
struct AVAANIMATION_API FConversationExplicitCameraShotReference {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName CameraShotName;
    
    FConversationExplicitCameraShotReference();
};


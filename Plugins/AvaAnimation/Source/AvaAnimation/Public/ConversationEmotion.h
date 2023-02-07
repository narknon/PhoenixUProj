#pragma once
#include "CoreMinimal.h"
#include "EFacialEmotion.h"
#include "ConversationEmotion.generated.h"

USTRUCT(BlueprintType)
struct AVAANIMATION_API FConversationEmotion {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EFacialEmotion Emotion;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HoldTime;
    
    FConversationEmotion();
};


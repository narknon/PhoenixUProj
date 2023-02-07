#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ConversationEmotion.h"
#include "ConversationEmotions.generated.h"

UCLASS(Blueprintable)
class AVAANIMATION_API UConversationEmotions : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FConversationEmotion> Emotions;
    
    UConversationEmotions();
};


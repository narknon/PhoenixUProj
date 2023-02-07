#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ConversationLayeredAnimationWeightEntry.h"
#include "ConversationLayeredAnimationWeights.generated.h"

UCLASS(Blueprintable)
class AVAANIMATION_API UConversationLayeredAnimationWeights : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FConversationLayeredAnimationWeightEntry> WeightEntries;
    
    UConversationLayeredAnimationWeights();
};


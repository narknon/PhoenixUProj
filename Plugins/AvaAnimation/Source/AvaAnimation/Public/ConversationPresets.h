#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ConversationPreset.h"
#include "ConversationPresets.generated.h"

UCLASS(Blueprintable)
class AVAANIMATION_API UConversationPresets : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FConversationPreset> Presets;
    
    UConversationPresets();
};


#pragma once
#include "CoreMinimal.h"
#include "ConversationPresetReference.generated.h"

USTRUCT(BlueprintType)
struct AVAANIMATION_API FConversationPresetReference {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName PresetName;
    
    FConversationPresetReference();
};


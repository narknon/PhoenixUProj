#pragma once
#include "CoreMinimal.h"
#include "ConversationLayeredAnimationWeightEntry.generated.h"

class UFloatProvider;

USTRUCT(BlueprintType)
struct AVAANIMATION_API FConversationLayeredAnimationWeightEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString DisplayName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Description;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFloatProvider* Provider;
    
    FConversationLayeredAnimationWeightEntry();
};


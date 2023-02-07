#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ConversationExplicitPoseGroup.generated.h"

USTRUCT(BlueprintType)
struct AVAANIMATION_API FConversationExplicitPoseGroup {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString DisplayName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Description;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer Tags;
    
    FConversationExplicitPoseGroup();
};


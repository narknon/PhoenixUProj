#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ConversationCameraRegistration.generated.h"

class UNameProvider;

USTRUCT(BlueprintType)
struct AVAANIMATION_API FConversationCameraRegistration {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString DisplayName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Description;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer CameraTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UNameProvider*> AvoidTransitionCameraNames;
    
    FConversationCameraRegistration();
};


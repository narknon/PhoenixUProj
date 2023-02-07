#pragma once
#include "CoreMinimal.h"
#include "StaticConversationRegistration.h"
#include "StaticConversationRegistrationPerUser.generated.h"

USTRUCT(BlueprintType)
struct FStaticConversationRegistrationPerUser {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString CharacterID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FStaticConversationRegistration> Registrations;
    
    PHOENIX_API FStaticConversationRegistrationPerUser();
};


#pragma once
#include "CoreMinimal.h"
#include "GreetingQueryData.generated.h"

class ASocialReasoning;

USTRUCT(BlueprintType)
struct FGreetingQueryData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsValid;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<ASocialReasoning> TargetReasoner;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName SocialAction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName SocialActionResponse;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 SocialActionResponseMagnitude;
    
    PHOENIX_API FGreetingQueryData();
};


#pragma once
#include "CoreMinimal.h"
#include "SocialCapitalMovement.generated.h"

USTRUCT(BlueprintType)
struct FSocialCapitalMovement {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsValid;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Magnitude;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Reason;
    
    PHOENIX_API FSocialCapitalMovement();
};


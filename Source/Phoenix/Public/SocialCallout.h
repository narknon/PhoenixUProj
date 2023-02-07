#pragma once
#include "CoreMinimal.h"
#include "SocialCapitalMovement.h"
#include "SocialDebug.h"
#include "SocialCallout.generated.h"

USTRUCT(BlueprintType)
struct FSocialCallout {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsFresh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSocialDebug SocialDebug;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSocialCapitalMovement SocialCapitalMovement;
    
    PHOENIX_API FSocialCallout();
};


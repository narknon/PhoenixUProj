#pragma once
#include "CoreMinimal.h"
#include "ESocialResponseContext.h"
#include "StationQueryData.h"
#include "SocialResponse.generated.h"

USTRUCT(BlueprintType)
struct FSocialResponse {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool Accepted;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<ESocialResponseContext::Type> Context;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Reason;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FStationQueryData StationToUse;
    
    PHOENIX_API FSocialResponse();
};


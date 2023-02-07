#pragma once
#include "CoreMinimal.h"
#include "WBPNData.generated.h"

USTRUCT(BlueprintType)
struct FWBPNData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool m_isLoggedIn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString m_deviceFlowVerificationUrl;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString m_deviceFlowCode;
    
    WBPN_API FWBPNData();
};


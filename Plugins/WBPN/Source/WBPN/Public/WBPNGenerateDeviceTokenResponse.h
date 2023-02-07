#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "WBPNGenerateDeviceTokenResponse.generated.h"

USTRUCT(BlueprintType)
struct FWBPNGenerateDeviceTokenResponse {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString m_url;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString m_code;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString m_deviceToken;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float m_pollInterval;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDateTime m_expiresAt;
    
    WBPN_API FWBPNGenerateDeviceTokenResponse();
};


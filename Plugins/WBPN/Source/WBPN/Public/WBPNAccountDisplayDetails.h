#pragma once
#include "CoreMinimal.h"
#include "WBPNAvatarDetails.h"
#include "WBPNAccountDisplayDetails.generated.h"

USTRUCT(BlueprintType)
struct FWBPNAccountDisplayDetails {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString m_accountId;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString m_username;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWBPNAvatarDetails m_avatar;
    
    WBPN_API FWBPNAccountDisplayDetails();
};


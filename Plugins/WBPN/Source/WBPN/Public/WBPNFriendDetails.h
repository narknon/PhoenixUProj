#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "WBPNAccountDisplayDetails.h"
#include "WBPNFriendDetails.generated.h"

USTRUCT(BlueprintType)
struct FWBPNFriendDetails {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWBPNAccountDisplayDetails m_account;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDateTime m_createdAt;
    
    WBPN_API FWBPNFriendDetails();
};


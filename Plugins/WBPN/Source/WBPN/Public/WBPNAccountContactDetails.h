#pragma once
#include "CoreMinimal.h"
#include "WBPNAccountDisplayDetails.h"
#include "WBPNAccountContactDetails.generated.h"

USTRUCT(BlueprintType)
struct FWBPNAccountContactDetails {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString m_ownerId;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString m_contactId;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool m_blocked;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWBPNAccountDisplayDetails m_account;
    
    WBPN_API FWBPNAccountContactDetails();
};


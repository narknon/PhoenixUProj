#pragma once
#include "CoreMinimal.h"
#include "EFriendInvitationState.h"
#include "WBPNAccountDisplayDetails.h"
#include "WBPNFriendInvitationDetails.generated.h"

USTRUCT(BlueprintType)
struct FWBPNFriendInvitationDetails {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString m_id;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString m_sentFrom;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString m_sentTo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EFriendInvitationState m_state;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWBPNAccountDisplayDetails m_account;
    
    WBPN_API FWBPNFriendInvitationDetails();
};


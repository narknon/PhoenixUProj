#pragma once
#include "CoreMinimal.h"
#include "WBPNFriendInvitationDetails.h"
#include "WBPNPaginatedFriendInvitations.generated.h"

USTRUCT(BlueprintType)
struct FWBPNPaginatedFriendInvitations {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 m_total;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 m_page;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 m_pageSize;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FWBPNFriendInvitationDetails> m_invitations;
    
    WBPN_API FWBPNPaginatedFriendInvitations();
};


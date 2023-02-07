#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EFriendInvitationState.h"
#include "WBPNFriendInvitation.generated.h"

USTRUCT(BlueprintType)
struct FWBPNFriendInvitation {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDateTime m_createdAt;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDateTime m_updatedAt;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString m_sentFrom;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString m_sentTo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EFriendInvitationState m_state;
    
    WBPN_API FWBPNFriendInvitation();
};


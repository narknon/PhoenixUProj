#pragma once
#include "CoreMinimal.h"
#include "WBPNFriendDetails.h"
#include "WBPNPaginatedFriendDetails.generated.h"

USTRUCT(BlueprintType)
struct FWBPNPaginatedFriendDetails {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 m_total;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 m_page;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 m_pageSize;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FWBPNFriendDetails> m_friends;
    
    WBPN_API FWBPNPaginatedFriendDetails();
};


#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "WBPNAvatarDetails.h"
#include "WBPNAccountLookupData.generated.h"

USTRUCT(BlueprintType)
struct FWBPNAccountLookupData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString m_id;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString m_publicId;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString m_username;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWBPNAvatarDetails m_avatar;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDateTime m_lastLogin;
    
    WBPN_API FWBPNAccountLookupData();
};


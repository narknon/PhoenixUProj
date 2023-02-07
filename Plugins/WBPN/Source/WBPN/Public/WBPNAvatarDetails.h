#pragma once
#include "CoreMinimal.h"
#include "WBPNAvatarDetails.generated.h"

USTRUCT(BlueprintType)
struct FWBPNAvatarDetails {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString m_name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString m_imageUrl;
    
    WBPN_API FWBPNAvatarDetails();
};


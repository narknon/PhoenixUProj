#pragma once
#include "CoreMinimal.h"
#include "WBPNWizardingWorldLinkAttributeData.generated.h"

USTRUCT(BlueprintType)
struct FWBPNWizardingWorldLinkAttributeData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString m_keyname;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString m_value;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString m_iss;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString m_issuerKeynameHash;
    
    WBPN_API FWBPNWizardingWorldLinkAttributeData();
};


#pragma once
#include "CoreMinimal.h"
#include "WBPNWizardingWorldLinkAttributeData.h"
#include "WBPNWizardingWorldLinkData.generated.h"

USTRUCT(BlueprintType)
struct FWBPNWizardingWorldLinkData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString m_Source;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString m_iss;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString m_groupHash;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString m_groupLink;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FWBPNWizardingWorldLinkAttributeData> m_attributes;
    
    WBPN_API FWBPNWizardingWorldLinkData();
};


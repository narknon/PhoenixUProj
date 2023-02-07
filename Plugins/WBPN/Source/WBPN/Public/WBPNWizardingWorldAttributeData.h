#pragma once
#include "CoreMinimal.h"
#include "WBPNWizardingWorldAttributeData.generated.h"

USTRUCT(BlueprintType)
struct FWBPNWizardingWorldAttributeData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString m_keyname;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString m_value;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString m_issuer;
    
    WBPN_API FWBPNWizardingWorldAttributeData();
};


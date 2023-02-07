#pragma once
#include "CoreMinimal.h"
#include "WBPNWizardingWorldAttributeData.h"
#include "WBPNWizardingWorldAttributeListData.generated.h"

USTRUCT(BlueprintType)
struct FWBPNWizardingWorldAttributeListData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FWBPNWizardingWorldAttributeData> m_attributes;
    
    WBPN_API FWBPNWizardingWorldAttributeListData();
};


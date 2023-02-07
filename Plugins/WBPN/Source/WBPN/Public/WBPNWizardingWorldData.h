#pragma once
#include "CoreMinimal.h"
#include "WBPNWizardingWorldLinkedAccountData.h"
#include "WBPNWizardingWorldData.generated.h"

USTRUCT(BlueprintType)
struct FWBPNWizardingWorldData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString m_sourceUserId;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString m_Source;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString m_issuer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString m_groupHash;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FWBPNWizardingWorldLinkedAccountData> m_linkedAccounts;
    
    WBPN_API FWBPNWizardingWorldData();
};


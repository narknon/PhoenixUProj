#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "VaultRangeSet.h"
#include "VaultSettings.generated.h"

class UAblAbility;

USTRUCT(BlueprintType)
struct FVaultSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bForceReachingVaultLinkEndLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSnapRotationBeforeVault;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> VaultAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FVaultRangeSet> VaultVariations;
    
    PHOENIX_API FVaultSettings();
};


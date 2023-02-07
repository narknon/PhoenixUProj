#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "DbSingleColumnInfo.h"
#include "OdcPathSpec.h"
#include "CompanionIdentityBuff.h"
#include "SocialSemanticIDs.h"
#include "CompanionSettings.generated.h"

UCLASS(Blueprintable, Config=Engine, DefaultConfig, Config=Game)
class UCompanionSettings : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSoftObjectPath CompanionConfigData;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDbSingleColumnInfo TestCompanionName;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<TEnumAsByte<SocialSemanticIDs>, FCompanionIdentityBuff> BuffsPerIdentity;
    
    UPROPERTY(Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<uint32> BuffLevels;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOdcPathSpec CompanionPathSpecs;
    
    UCompanionSettings();
};


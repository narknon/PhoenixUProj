#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Templates/SubclassOf.h"
#include "PopulationConfigData.generated.h"

class UAblAbility;
class UMultiFX2_Base;

UCLASS(Blueprintable)
class PHOENIX_API UPopulationConfigData : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, TSubclassOf<UAblAbility>> ApparateMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UMultiFX2_Base*> Effects;
    
    UPopulationConfigData();
};


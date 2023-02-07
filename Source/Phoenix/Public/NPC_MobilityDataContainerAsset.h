#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "NPC_MobilityDataContainer.h"
#include "NPC_MobilityDataContainerAsset.generated.h"

UCLASS(Blueprintable)
class UNPC_MobilityDataContainerAsset : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNPC_MobilityDataContainer ContainerData;
    
    UNPC_MobilityDataContainerAsset();
};


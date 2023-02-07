#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ENPC_PerceptionUpdate.h"
#include "Templates/SubclassOf.h"
#include "NPC_PerceptionUpdateDataAsset.generated.h"

class UNPC_PerceptionUpdate;

UCLASS(Blueprintable)
class UNPC_PerceptionUpdateDataAsset : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<ENPC_PerceptionUpdate, TSubclassOf<UNPC_PerceptionUpdate>> UpdateClassMap;
    
    UNPC_PerceptionUpdateDataAsset();
};


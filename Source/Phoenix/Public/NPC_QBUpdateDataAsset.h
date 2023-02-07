#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ENPC_QBUpdate.h"
#include "Templates/SubclassOf.h"
#include "NPC_QBUpdateDataAsset.generated.h"

class UNPC_QBUpdate;

UCLASS(Blueprintable)
class UNPC_QBUpdateDataAsset : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<ENPC_QBUpdate, TSubclassOf<UNPC_QBUpdate>> UpdateClassMap;
    
    UNPC_QBUpdateDataAsset();
};


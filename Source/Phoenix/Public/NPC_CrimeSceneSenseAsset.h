#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "NPC_CrimeSceneSense.h"
#include "NPC_CrimeSceneSenseAsset.generated.h"

UCLASS(Blueprintable)
class UNPC_CrimeSceneSenseAsset : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNPC_CrimeSceneSense CrimeSceneSense;
    
    UNPC_CrimeSceneSenseAsset();
};


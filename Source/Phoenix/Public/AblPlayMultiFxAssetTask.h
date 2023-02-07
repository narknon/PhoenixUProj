#pragma once
#include "CoreMinimal.h"
#include "AblPlayMultiFxAssetBaseTask.h"
#include "AblPlayMultiFxAssetTask.generated.h"

class UMultiFX2Asset;

UCLASS(Blueprintable, EditInlineNew)
class UAblPlayMultiFxAssetTask : public UAblPlayMultiFxAssetBaseTask {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMultiFX2Asset* FXAsset;
    
    UAblPlayMultiFxAssetTask();
};


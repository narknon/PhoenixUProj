#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ESimpleDataSetPreloadState.h"
#include "SimpleDataSetPendingLoad.h"
#include "SimpleDataSet.generated.h"

UCLASS(Blueprintable, Transient)
class MATERIALPERMUTER_API USimpleDataSet : public UObject {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSet<UObject*> LoadedObjects;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSimpleDataSetPendingLoad> PendingLoads;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESimpleDataSetPreloadState PreloadState;
    
public:
    USimpleDataSet();
};


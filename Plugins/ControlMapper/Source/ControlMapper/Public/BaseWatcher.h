#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "BaseWatcher.generated.h"

class UWatcherRecord;

UCLASS(Abstract, Blueprintable)
class CONTROLMAPPER_API UBaseWatcher : public UObject {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UWatcherRecord* WatcherRecord;
    
public:
    UBaseWatcher();
    UFUNCTION(BlueprintCallable)
    void FiltersHaveChanged(bool bNewResult);
    
};


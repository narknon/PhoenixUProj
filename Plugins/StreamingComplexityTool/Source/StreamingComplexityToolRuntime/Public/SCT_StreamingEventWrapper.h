#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "SCT_StreamingEventWrapper.generated.h"

class ASCT_LevelController;
class ULevelStreaming;

UCLASS(Blueprintable)
class STREAMINGCOMPLEXITYTOOLRUNTIME_API USCT_StreamingEventWrapper : public UObject {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ASCT_LevelController* LevelController;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ULevelStreaming* LevelStreaming;
    
public:
    USCT_StreamingEventWrapper();
    UFUNCTION(BlueprintCallable)
    void OnLevelUnloaded();
    
    UFUNCTION(BlueprintCallable)
    void OnLevelShown();
    
    UFUNCTION(BlueprintCallable)
    void OnLevelLoaded();
    
    UFUNCTION(BlueprintCallable)
    void OnLevelHidden();
    
};


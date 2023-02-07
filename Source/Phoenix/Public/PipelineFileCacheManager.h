#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "PipelineFileCacheManager.generated.h"

class UPipelineFileCacheManager;

UCLASS(Blueprintable)
class PHOENIX_API UPipelineFileCacheManager : public UObject {
    GENERATED_BODY()
public:
    UPipelineFileCacheManager();
    UFUNCTION(BlueprintCallable)
    void ResumeBatching();
    
    UFUNCTION(BlueprintCallable)
    void PauseBatching();
    
    UFUNCTION(BlueprintCallable)
    bool IsPrecachingEnabled();
    
    UFUNCTION(BlueprintCallable)
    bool IsPipelioneFileCacheManagerEnabled();
    
    UFUNCTION(BlueprintCallable)
    bool IsBatchingPaused();
    
    UFUNCTION(BlueprintCallable)
    static UPipelineFileCacheManager* Get();
    
};


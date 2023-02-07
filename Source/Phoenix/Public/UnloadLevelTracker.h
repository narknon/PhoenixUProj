#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UnloadLevelTracker.generated.h"

class ULevelStreaming;
class UObjectStateManager;
class UWorld;

UCLASS(Blueprintable)
class UUnloadLevelTracker : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UWorld* World;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ULevelStreaming* StreamingLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UObjectStateManager* Manager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FString> RemovedOSINames;
    
    UUnloadLevelTracker();
    UFUNCTION(BlueprintCallable)
    void OnLevelUnloaded();
    
    UFUNCTION(BlueprintCallable)
    void Cleanup();
    
};


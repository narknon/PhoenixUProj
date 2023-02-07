#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "PlaySceneRigCinematic.generated.h"

class UCinematicBatch;
class UCinematicBatchHUD;

UCLASS(Blueprintable)
class PHOENIX_API UPlaySceneRigCinematic : public UObject {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UCinematicBatch* CurrentCinematicBatch;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UCinematicBatchHUD* CurrentCinematicBatchHUD;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UCinematicBatch*> CinematicBatches;
    
public:
    UPlaySceneRigCinematic();
    UFUNCTION(BlueprintCallable)
    void PlayAllCinematicBatchJobs(const TArray<FString> InCinematicBatchPaths);
    
};


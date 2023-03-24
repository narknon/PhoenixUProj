#pragma once
#include "CoreMinimal.h"
#include "SpawnSelectInfo.h"
#include "StreamingPlaceholderBase.h"
#include "StreamingPlaceholderFixedUID.generated.h"

class AActor;

UCLASS(Blueprintable)
class AStreamingPlaceholderFixedUID : public AStreamingPlaceholderBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSpawnSelectInfo DbIdInfo;
    
protected:
    UPROPERTY(EditAnywhere, TextExportTransient, meta=(AllowPrivateAccess=true))
    uint32 UID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* SpawnedActor;
    
public:
    AStreamingPlaceholderFixedUID(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    AActor* GetSpawnedActor();
    
};


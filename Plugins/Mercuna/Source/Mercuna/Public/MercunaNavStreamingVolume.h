#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Volume.h"
#include "MercunaNavStreamingVolume.generated.h"

class ULevelStreaming;
class UWorld;

UCLASS(Blueprintable, MinimalAPI)
class AMercunaNavStreamingVolume : public AVolume {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UWorld> LevelToStream;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector AdditionalLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRotator AdditionalRotation;
    
private:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<ULevelStreaming> StreamingLevel;
    
public:
    AMercunaNavStreamingVolume(const FObjectInitializer& ObjectInitializer);
};


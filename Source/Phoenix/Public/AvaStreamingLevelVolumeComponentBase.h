#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "AvaStreamingVolumeComponentBase.h"
#include "AvaStreamingLevelVolumeComponentBase.generated.h"

class AActor;
class ULevelStreamingDynamic;
class UWorld;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class PHOENIX_API UAvaStreamingLevelVolumeComponentBase : public UAvaStreamingVolumeComponentBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UWorld> LevelToStream;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* LevelPlacementActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ULevelStreamingDynamic* LoadedLevel;
    
    UAvaStreamingLevelVolumeComponentBase();
    UFUNCTION(BlueprintCallable)
    FRotator GetLevelRot();
    
    UFUNCTION(BlueprintCallable)
    FVector GetLevelLoc();
    
};


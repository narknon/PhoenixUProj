#pragma once
#include "CoreMinimal.h"
#include "SceneRig.h"
#include "SceneRig_Bink.generated.h"

class UDataTable;
class UMediaSource;
class USceneRig_Bink;

UCLASS(Blueprintable)
class PHOENIX_API USceneRig_Bink : public USceneRig {
    GENERATED_BODY()
public:
    USceneRig_Bink();
    UFUNCTION(BlueprintCallable)
    USceneRig_Bink* PlayBink(UMediaSource* FileMediaSource, UDataTable* Subtitles);
    
};

